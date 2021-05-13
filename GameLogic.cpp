#include "GameLogic.h"

GameLogic::GameLogic()
{
	this->frogModel = new FrogModel(100,100);
	this->allModels.insert(std::make_pair("0", this->frogModel));
}

std::unordered_map<std::string, FrogModel*> GameLogic::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		this->frogModel->posX += 20;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		this->frogModel->posX -= 20;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		this->frogModel->posY -= 20;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		this->frogModel->posY += 20;
	}

	return this->allModels;
}