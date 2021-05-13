#pragma once
#include "FrogModel.h"
#include "CarModel.h"
#include <SFML/Graphics.hpp>
#include <unordered_map>

class GameLogic
{
public:
	GameLogic();
	std::unordered_map<std::string, Model*> Update(); //póŸniej tê funkcjê porozdzielaæ na update, getModel itd

private:
	Model* frogModel;
	std::unordered_map<std::string, Model*> allModels;
};
