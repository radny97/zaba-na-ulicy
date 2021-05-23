#include "GameGraphics.h"

GameGraphics::GameGraphics()
{

}

void GameGraphics::Update(std::unordered_map<int, Object*> allModels)
{
	this->spritesToDelete = this->allObjectSprites;

	MapAllObjectsToObjectSprites(allModels);

	if (!this->spritesToDelete.empty())
	{
		DeleteSpritesOfObjectsThatNoLongerExist();
	}
}

void GameGraphics::MapAllObjectsToObjectSprites(std::unordered_map<int, Object*> allObjects)
{
	for (auto& iteratorObjects : allObjects)
	{
		bool newSpriteNeedsToBeAdded = true;

		for (auto& iteratorObjectSprites : this->allObjectSprites)
		{
			if (iteratorObjects.second->ID == iteratorObjectSprites.second->ID)
			{
				MapOneObjectToSprite(iteratorObjects.second, iteratorObjectSprites.second);
				newSpriteNeedsToBeAdded = false;

				this->spritesToDelete.erase(iteratorObjects.second->ID);
			}
		}

		if (newSpriteNeedsToBeAdded == true)
		{
			ObjectSprite* objectSprite = ChooseTypeOfNewObjectStripe(iteratorObjects.second);

			MapOneObjectToSprite(iteratorObjects.second, objectSprite);
			this->allObjectSprites.insert(std::make_pair(objectSprite->ID, objectSprite));
		}
	}
}

void GameGraphics::MapOneObjectToSprite(Object* source, ObjectSprite* target)
{
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Trzeba poprawiæ mapowanie z u¿yciem dynamic cast tak jak na przyk³adzie ni¿ej
	//aby móc mapowaæ pola specyficzne dla ka¿dego obiektu pochodnego
	//i nie robiæ ha³tury

	CarObject *kp;
	kp = dynamic_cast<CarObject*>(source);


	if (source->type == "frog")
	{
		target->posX = source->posX;
		target->posY = source->posY;
		target->ID = source->ID;
	}
	else if (source->type == "car")
	{
		target->posX = source->posX;
		target->posY = source->posY;
		target->ID = source->ID;
	}
	/*else if (source->type == "playground")
	{
		target->posX = source->posX;
		target->posY = source->posY;
		target->ID = source->ID;
	}*/
	target->setPosition(target->posX, target->posY);
}

ObjectSprite* GameGraphics::ChooseTypeOfNewObjectStripe(Object* source)
{
	if (source->type == "frog")
	{
		return new FrogObjectSprite();
	}
	else if (source->type == "car")
	{
		return new CarObjectSprite();
	}
	else return new ObjectSprite();
}

void GameGraphics::DeleteSpritesOfObjectsThatNoLongerExist()
{
	for (auto& iterator : this->spritesToDelete)
	{
		ObjectSprite *toDelete = this->allObjectSprites.at(iterator.second->ID);
		this->allObjectSprites.erase(iterator.second->ID);
		delete toDelete;
	}
	this->spritesToDelete.clear();
}

void GameGraphics::Render(sf::RenderWindow* window)
{
	for (auto& iteratorObjectSprites : this->allObjectSprites)
	{
		window->draw(*iteratorObjectSprites.second);
	}
}