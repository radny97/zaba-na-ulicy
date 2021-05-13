#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "FrogModel.h"
#include "FrogModelGraphics.h"

class GameGraphics
{
public:
	GameGraphics();
	void Update(sf::RenderWindow* window, std::unordered_map<std::string, FrogModel*> allModels); //zamiast frogModel zrobiæ Model, po którym bêd¹ dziedziczyæ inne modele

private:
	//FrogModelGraphics* frogModelGraphics;
};
