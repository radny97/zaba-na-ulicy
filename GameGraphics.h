#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "FrogModel.h"
#include "CarModel.h"
#include "FrogModelGraphics.h"
#include "CarModelGraphics.h"

class GameGraphics
{
public:
	GameGraphics();
	void Update(sf::RenderWindow* window, std::unordered_map<std::string, Model*> allModels);

};
