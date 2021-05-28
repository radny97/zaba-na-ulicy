#pragma once
#include "Utilities.h"
#include <string>

class Player
{
public:
	Player() 
	{
		this->lives = Utilities::playerLives;
		this->score = 0;
	};
	int lives;
	int score;
	std::string name;
};

