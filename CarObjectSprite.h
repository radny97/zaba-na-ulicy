#pragma once
#include "ObjectSprite.h"

class CarObjectSprite : public ObjectSprite
{
public:
	CarObjectSprite() {};
	CarObjectSprite(bool fromDownToUp)
	{
		if (fromDownToUp == true)
		{
			this->texture = new sf::Texture();
			this->Load("GraphicsTest/car from bottom.png");
		}
		else
		{
			this->texture = new sf::Texture();
			this->Load("GraphicsTest/car from top.png");
		}
	};

};