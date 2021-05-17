#pragma once
#include "FrogObject.h"
#include "CarObject.h"
#include <SFML/Graphics.hpp>
#include <unordered_map>

class GameLogic
{
public:
	GameLogic();
	void UpdateLogic();
	std::unordered_map<int, Object*> GetAllObjects();
	bool IsTimeToGenerateCar();
	void GenerateCar();
	void InputControl();

private:
	Object* frogObject;
	std::unordered_map<int, Object*> allObjects;

	sf::Clock timer;
	sf::Time elapsedTime;

	bool leftKeyPressed;
	bool rightKeyPressed;
};
