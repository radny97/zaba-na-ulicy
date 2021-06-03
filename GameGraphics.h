#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <list>
#include "FrogObject.h"
#include "CarObject.h"
#include "FrogObjectSprite.h"
#include "CarObjectSprite.h"
#include "PlaygroundGraphics.h"
#include "PauseScreenGraphics.h"
#include "PlaygroundLogic.h"
#include "Player.h"
#include "LivesSprite.h"
#include "ScoreText.h"

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
	void UpdateHud();
	//void SetNewPositionsOfSprites();
	void Render(sf::RenderWindow* window);
	void RenderPause(sf::RenderWindow* window);

	std::unordered_map<int, ObjectSprite*> allObjectSprites;
	std::unordered_map<int, ObjectSprite*> spritesToDelete;
	std::list<ObjectSprite*> livesSprites;
	ScoreText* scoreText;

	PlaygroundGraphics* playgroundGraphics;
	PauseScreenGraphics* pauseScreenGraphics;
	
	//sf::Sprite* background;  // wskaŸnik na grafikê do za³adowania
	//sf::Texture* texture;  // wskaŸnik na teksturê, która zostanie u¿yta jako t³o
};
