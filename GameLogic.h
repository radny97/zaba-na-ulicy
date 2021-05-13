#pragma once
#include "FrogModel.h"
#include <SFML/Graphics.hpp>
#include <unordered_map>

class GameLogic
{
public:
	GameLogic();
	std::unordered_map<std::string, FrogModel*> Update(); //póŸniej tê funkcjê porozdzielaæ na update, getModel itd

private:
	FrogModel* frogModel;
	std::unordered_map<std::string, FrogModel*> allModels;
};
