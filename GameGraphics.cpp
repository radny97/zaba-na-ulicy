#include "GameGraphics.h"

GameGraphics::GameGraphics()
{
	
}

void GameGraphics::Update(sf::RenderWindow* window, std::unordered_map<std::string, Model*> allModels)
{
	//mapowanie model na modelGraphics
	Model* frogModel = new FrogModel();
	frogModel = allModels.at("0");

	Model* carModel = new CarModel();
	carModel = allModels.at("1");

	ModelGraphics* frogModelGraphics = new FrogModelGraphics();
	frogModelGraphics->posX = frogModel->posX;
	frogModelGraphics->posY = frogModel->posY;

	frogModelGraphics->setPosition(frogModelGraphics->posX, frogModelGraphics->posY);

	ModelGraphics* carModelGraphics = new CarModelGraphics();
	carModelGraphics->posX = carModel->posX;
	carModelGraphics->posY = carModel->posY;

	carModelGraphics->setPosition(carModelGraphics->posX, carModelGraphics->posY);

	window->draw(*frogModelGraphics);
	window->draw(*carModelGraphics);
}