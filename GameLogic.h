#pragma once
#include "FrogObject.h"
#include "CarObject.h"
#include "PlaygroundLogic.h"
#include <SFML/Graphics.hpp>
#include "Enums.h"
#include "Player.h"
#include <unordered_map>
#include <iostream> /////////////////////////////////////////

class GameLogic
{
public:
	GameLogic();
	void UpdateLogic();
	std::unordered_map<int, Object*> GetAllObjects();
	void UpdateCar();
	void AddCarToDeleteListIfItDroveOfPlayground(Object* car);
	bool IsTimeToGenerateCar();
	void GenerateCar(Track track);
	void InputControl();
	void DeleteObjects();
	PlaygroundLogic* GetPlaygroundLogic();

	CollisionType CheckCollision(Object* firstObject, Object* secondObject);
	SubStateOfGame GetSubStateOfGame();
	void SetSubStateOfGame(SubStateOfGame subState);

	Player* player;

private:
	Object* frogObject;
	PlaygroundLogic* playground;

	std::unordered_map<int, Object*> allObjects;
	std::unordered_map<int, Object*> objectsToDelete;

	sf::Clock timer;
	sf::Time elapsedTime;

	bool leftKeyPressed;
	bool rightKeyPressed;
	int positionOfFrogIterator;

	SubStateOfGame subState;
};
