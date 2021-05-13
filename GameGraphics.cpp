#include "GameGraphics.h"

GameGraphics::GameGraphics()
{
	
}

void GameGraphics::Update(sf::RenderWindow* window, std::unordered_map<std::string, FrogModel*> allModels)
{
	//mapowanie model na modelGraphics
	FrogModel* frogModel;// = new FrogModel();
	frogModel = allModels.at("0");

	FrogModelGraphics* frogModelGraphics = new FrogModelGraphics();
	frogModelGraphics->posX = frogModel->posX;
	frogModelGraphics->posY = frogModel->posY;

	frogModelGraphics->setPosition(frogModelGraphics->posX, frogModelGraphics->posY);

	window->draw(*frogModelGraphics);
}