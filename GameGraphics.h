#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "FrogObject.h"
#include "CarObject.h"
#include "FrogObjectSprite.h"
#include "CarObjectSprite.h"
#include "PlaygroundGraphics.h"
#include "PlaygroundLogic.h"

class GameGraphics
{
public:
	GameGraphics();
	void Update(std::unordered_map<int, Object*> allModels);
	void SetPlaygroundGraphics(PlaygroundLogic* playgroundLogic);
	void MapAllObjectsToObjectSprites(std::unordered_map<int, Object*> allModels);
	void MapOneObjectToSprite(Object* source, ObjectSprite* target);
	ObjectSprite* ChooseTypeOfNewObjectStripe(Object* source);
	void DeleteSpritesOfObjectsThatNoLongerExist();
	//void SetNewPositionsOfSprites();
	void Render(sf::RenderWindow* window);

	std::unordered_map<int, ObjectSprite*> allObjectSprites;
	std::unordered_map<int, ObjectSprite*> spritesToDelete;
	PlaygroundGraphics* playgroundGraphics;
	//sf::Sprite* background;  // wskaŸnik na grafikê do za³adowania
	//sf::Texture* texture;  // wskaŸnik na teksturê, która zostanie u¿yta jako t³o
};
