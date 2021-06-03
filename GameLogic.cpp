#include "GameLogic.h"

//GameLogic::GameLogic()
//{
//
//}

GameLogic::GameLogic()
{
	this->subState = SubStateOfGame::game;
	//this->stopGenerating = false;
	this->scoreInThisRound = 0;
	
	//this->player = player;
	this->scoreInPreviousRound = Player::getInstance().GetScore();

	this->playground = new PlaygroundLogic();

	this->positionOfFrogIterator = this->playground->frogStandingPoints.size() - 1;

	this->frogObject = new FrogObject(
		this->playground->frogStandingPoints.at(this->positionOfFrogIterator).coordinateX,
		this->playground->frogStandingPoints.at(this->positionOfFrogIterator).coordinateY
		//this->player
	);

	this->allObjects.insert(std::make_pair(this->frogObject->ID, this->frogObject));
}

void GameLogic::UpdateLogic()
{
	this->scoreInThisRound = Player::getInstance().GetScore() - this->scoreInPreviousRound;

	if (Player::getInstance().GetLives() == 0 || this->frogObject->posX < this->playground->frogStandingPoints.at(0).coordinateX)
	{
		//this->stopGenerating = true;
		this->subState = SubStateOfGame::gameWaiting;
	}

	if (this->subState == SubStateOfGame::gameWaiting && this->allObjects.size() == 1)
	{
		if (Player::getInstance().GetLives() == 0)
		{
			this->subState = SubStateOfGame::gameOver;
		}
		if (this->positionOfFrogIterator == 0)
		{
			this->subState = SubStateOfGame::nextLevel;
		}
	}


	for (auto& iterator : this->allObjects)
	{
		AddCarToDeleteListIfItMakeConditions(iterator.second);

		iterator.second->UpdateObject();

		if (this->subState == SubStateOfGame::gameWaiting && iterator.second->type == "car")
		{
			iterator.second->velocity++;
		}
	}



		for (auto& firstLoopObject : this->allObjects)
		{
			for (auto& secondLoopObject : this->allObjects)
			{

					if (firstLoopObject.second != secondLoopObject.second && (firstLoopObject.second->temporaryNonCollisional == false || secondLoopObject.second->temporaryNonCollisional == false))
					{
						if (CheckCollision(firstLoopObject.second, secondLoopObject.second) == CollisionType::carCarColision)
						{
							if (firstLoopObject.second->velocity > secondLoopObject.second->velocity)
							{
								firstLoopObject.second->velocity = secondLoopObject.second->velocity - 1;
								if(secondLoopObject.second->velocity < 3)
									secondLoopObject.second->velocity++;
								//secondLoopObject.second->velocity++;
								//firstLoopObject.second->temporaryNonCollisional = true;

							}
							else
							{
								secondLoopObject.second->velocity = firstLoopObject.second->velocity - 1;
								if (firstLoopObject.second->velocity < 3)
									firstLoopObject.second->velocity++;
								//firstLoopObject.second->velocity++;
								//secondLoopObject.second->temporaryNonCollisional = true;
							}
							firstLoopObject.second->temporaryNonCollisional = true;
							secondLoopObject.second->temporaryNonCollisional = true;

						}
						if (CheckCollision(firstLoopObject.second, secondLoopObject.second) == CollisionType::frogCarCollision)
						{
							this->positionOfFrogIterator = this->playground->frogStandingPoints.size() - 1;
							this->frogObject->Death(this->playground->frogStandingPoints.at(this->positionOfFrogIterator).coordinateX, this->scoreInThisRound);
							//this->frogObject->SetPosX(this->playground->frogStandingPoints.at(this->positionOfFrogIterator).coordinateX);
							//if (this->player->lives != 0)
							//{
							//	this->player->lives -= 1;
							//}
						}
					}

					//secondLoopObject.second->collisionChecked = true;
			}
			//firstLoopObject.second->collisionChecked = true;
		}



		if (this->subState == SubStateOfGame::game)
		{
			for (auto& track : this->playground->tracks)
			{
				if (IsTimeToGenerateCar(&track))
				{
					GenerateCar(track);
				}
			}
			//InputControl();
		}
		

		


	

	if (!this->objectsToDelete.empty())
	{
		DeleteObjects();
	}

}

std::unordered_map<int, Object*> GameLogic::GetAllObjects()
{
	return this->allObjects;
}

PlaygroundLogic* GameLogic::GetPlaygroundLogic()
{
	return this->playground;
}

CollisionType GameLogic::CheckCollision(Object* firstObject, Object* secondObject)
{
	if (firstObject->type == "car" && firstObject->collisional)
	{
		CarObject* car;
		car = dynamic_cast<CarObject*>(firstObject);
		if (secondObject->collisional &&
			(secondObject->CheckIfCollisionPointIsInBounds(*car->frontCollisionPoint) 
		|| secondObject->CheckIfCollisionPointIsInBounds(*car->backCollisionPoint)))
		{
			if (secondObject->type == "frog")
			{
				std::cout << "kolizja ¿aba samochód";// << std::endl << std::endl;
				return CollisionType::frogCarCollision;
			}
			if (secondObject->type == "car")
			{
				std::cout << "kolizja samochód samochód";// << std::endl << std::endl;
				return CollisionType::carCarColision;
			}
		}
	}
	return CollisionType::noCollision;
}

void GameLogic::InputControl()
{
	FrogObject* frog;
	frog = dynamic_cast<FrogObject*>(this->frogObject);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && frog->stateOfFrog == StateOfFrog::normalStanding && this->subState == SubStateOfGame::game && !this->leftKeyPressed)
	{
		if (this->positionOfFrogIterator > 0)
		{
			this->positionOfFrogIterator--;
			//this->frogObject->SetPosX(this->playground->frogStandingPoints.at(this->positionOfFrogIterator).coordinateX);
			this->frogObject->Jump(this->playground->frogStandingPoints.at(this->positionOfFrogIterator).coordinateX);
			//this->player->score++;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && frog->stateOfFrog == StateOfFrog::normalStanding && this->subState == SubStateOfGame::game && !this->rightKeyPressed)
	{
		if (this->positionOfFrogIterator < this->playground->frogStandingPoints.size()-1)
		{
			this->positionOfFrogIterator++;
			//this->frogObject->SetPosX(this->playground->frogStandingPoints.at(this->positionOfFrogIterator).coordinateX);
			this->frogObject->Jump(this->playground->frogStandingPoints.at(this->positionOfFrogIterator).coordinateX);
			//this->player->score--;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) && this->subState == SubStateOfGame::game && !this->escapeKeyPressed)
	{
		this->subState = SubStateOfGame::pause;
		this->escapeKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) && this->subState == SubStateOfGame::pause && !this->enterKeyPressed)
	{
		this->subState = SubStateOfGame::game;
		this->enterKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter);
		for (auto& track : this->playground->tracks)
		{
			if (track.timer.getElapsedTime().asMilliseconds() > 3000)
			{
				track.randomNumber = rand() % 1500 + 300;
				track.timer.restart();
			}	
		}
	}

	this->enterKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter);
	this->escapeKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape);
	this->leftKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
	this->rightKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
}

//void GameLogic::UpdateCar()
//{
//	for (auto& iterator : this->allObjects)
//	{
//		AddCarToDeleteListIfItDroveOfPlayground(iterator.second);
//		if (iterator.second->type == "car")
//		{
//			iterator.second->Move();
//		}
//	}
//}

bool GameLogic::IsTimeToGenerateCar(Track* track)
{
	track->elapsedTime = track->timer.getElapsedTime();

	if (track->elapsedTime.asMilliseconds() > track->randomNumber)
	{
		track->timer.restart();
		track->randomNumber = rand() % 5000 + 800;
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

void GameLogic::AddCarToDeleteListIfItMakeConditions(Object *car)
{
	if (!(car->posY > - (2*Utilities::carImageSizeY) && car->posY < Utilities::screenResolutionY + (2* Utilities::carImageSizeY)))
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


SubStateOfGame GameLogic::GetSubStateOfGame()
{
	return this->subState;
}

void GameLogic::SetSubStateOfGame(SubStateOfGame subState)
{
	this->subState = subState;
}