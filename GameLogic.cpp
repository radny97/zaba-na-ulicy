#include "GameLogic.h"

GameLogic::GameLogic()
{
	this->playground = new Playground();

	this->positionOfFrogIterator = this->playground->frogStandingPoints.size() - 1;

	this->frogObject = new FrogObject(
		this->playground->frogStandingPoints.at(this->positionOfFrogIterator).coordinateX,
		this->playground->frogStandingPoints.at(this->positionOfFrogIterator).coordinateY
	);

	this->allObjects.insert(std::make_pair(this->frogObject->ID, this->frogObject));

}

void GameLogic::UpdateLogic()
{
	//bedzie coœ w rodzaju animacji, które bêd¹ polegaæ na zmianie "stanu" obiektu, po up³yniêciu czasu mierzonego tutaj

	//tu bêdzie pêtla wszystkich obiektów w której bêdzie coœ w stylu Object.Update()
	UpdateCar();

	for (auto& firstLoopObject : this->allObjects)
	{
		for (auto& secondLoopObject : this->allObjects)
		{
			if (firstLoopObject.second != secondLoopObject.second)
			{
				if (CheckCollision(firstLoopObject.second, secondLoopObject.second) == collisionType::carCarColision)
				{
					//tutaj coœ ze zmian¹ 
				}
				if (CheckCollision(firstLoopObject.second, secondLoopObject.second) == collisionType::frogCarCollision)
				{
					this->positionOfFrogIterator = this->playground->frogStandingPoints.size() - 1;
					this->frogObject->SetPosX(this->playground->frogStandingPoints.at(this->positionOfFrogIterator).coordinateX);
				}
			}
		}
	}



	if (IsTimeToGenerateCar())
	{
		//generowanie dla ka¿dego toru oddzielnie
		for (auto const& track : this->playground->tracks)
		{
			GenerateCar(track);
		}
	}

	InputControl();

	if (!this->objectsToDelete.empty())
	{
		DeleteObjects();
	}

}

std::unordered_map<int, Object*> GameLogic::GetAllObjects()
{
	return this->allObjects;
}

collisionType GameLogic::CheckCollision(Object* firstObject, Object* secondObject)
{
	if (firstObject->type == "car")
	{
		CarObject* car;
		car = dynamic_cast<CarObject*>(firstObject);
		if (secondObject->CheckIfCollisionPointIsInBounds(*car->frontCollisionPoint) 
		|| secondObject->CheckIfCollisionPointIsInBounds(*car->backCollisionPoint))
		{
			if (secondObject->type == "frog")
			{
				std::cout << "kolizja ¿aba samochód";// << std::endl << std::endl;
				return collisionType::frogCarCollision;
			}
			if (secondObject->type == "car")
			{
				std::cout << "kolizja samochód samochód";// << std::endl << std::endl;
				return collisionType::carCarColision;
			}
		}
	}
	return collisionType::noCollision;
}

void GameLogic::InputControl()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !this->leftKeyPressed)
	{
		if (this->positionOfFrogIterator > 0)
		{
			this->positionOfFrogIterator--;
			this->frogObject->SetPosX(this->playground->frogStandingPoints.at(this->positionOfFrogIterator).coordinateX);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !this->rightKeyPressed)
	{
		if (this->positionOfFrogIterator < this->playground->frogStandingPoints.size()-1)
		{
			this->positionOfFrogIterator++;
			this->frogObject->SetPosX(this->playground->frogStandingPoints.at(this->positionOfFrogIterator).coordinateX);
		}
	}

	this->leftKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
	this->rightKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
}

void GameLogic::UpdateCar()
{
	for (auto& iterator : this->allObjects)
	{
		AddCarToDeleteListIfItDroveOfPlayground(iterator.second);
		if (iterator.second->type == "car")
		{
			iterator.second->Move(slowVelocity);
		}
	}
}

bool GameLogic::IsTimeToGenerateCar()
{
	srand(time(0));
	int randomNumber = rand() % 3 + 1;

	this->elapsedTime = this->timer.getElapsedTime();

	if (this->elapsedTime.asSeconds() > randomNumber)
	{
		this->timer.restart();
		return true;
	}	
	else
		return false;
}

void GameLogic::GenerateCar(Track track)
{
	Object* carObject = new CarObject(track.beginingOfTrack.coordinateX, track.beginingOfTrack.coordinateY, track.fromDownToUp);
	this->allObjects.insert(std::make_pair(carObject->ID, carObject));
}

void GameLogic::AddCarToDeleteListIfItDroveOfPlayground(Object *car)
{
	if (car->posY < -Utilities::carImageSizeY || car->posY > Utilities::screenResolutionY + Utilities::carImageSizeY)
	{
		this->objectsToDelete.insert(std::make_pair(car->ID, car));
	}
}

void GameLogic::DeleteObjects()
{
	for (auto& iterator : this->objectsToDelete)
	{
		Object* toDelete = this->allObjects.at(iterator.second->ID);
		this->allObjects.erase(iterator.second->ID);
		delete toDelete;
	}
	this->objectsToDelete.clear();
}