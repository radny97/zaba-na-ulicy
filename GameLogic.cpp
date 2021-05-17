#include "GameLogic.h"

GameLogic::GameLogic()
{
	this->frogObject = new FrogObject(100,100);
	this->allObjects.insert(std::make_pair(this->frogObject->ID, this->frogObject));

}

void GameLogic::UpdateLogic()
{
	if (IsTimeToGenerateCar())
	{
		GenerateCar();
	}

	InputControl();

}

std::unordered_map<int, Object*> GameLogic::GetAllObjects()
{
	return this->allObjects;
}

void GameLogic::InputControl()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !this->leftKeyPressed)
	{
		this->frogObject->posX -= 50;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !this->rightKeyPressed)
	{
		this->frogObject->posX += 50;
	}

	this->leftKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
	this->rightKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
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

void GameLogic::GenerateCar()
{
	Object* carObject = new CarObject(200, 200);
	this->allObjects.insert(std::make_pair(carObject->ID, carObject));
}