#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "FrogObject.h"
#include "CarObject.h"
#include "FrogObjectSprite.h"
#include "CarObjectSprite.h"

class GameGraphics
{
public:
	GameGraphics();
	void Update(std::unordered_map<int, Object*> allModels);
	void MapAllObjectsToObjectSprites(std::unordered_map<int, Object*> allModels);
	void MapOneObjectToSprite(Object* source, ObjectSprite* target);
	ObjectSprite* ChooseTypeOfNewObjectStripe(Object* source);
	void DeleteSpritesOfObjectsThatNoLongerExist();
	void SetNewPositionsOfSprites();
	void Render(sf::RenderWindow* window);

	std::unordered_map<int, ObjectSprite*> allObjectSprites;
	std::unordered_map<int, ObjectSprite*> spritesToDelete;

};
