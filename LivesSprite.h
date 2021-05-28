#pragma once
#include "ObjectSprite.h"

class LivesSprite : public ObjectSprite
{
public:
	LivesSprite()
	{
		this->texture = new sf::Texture();
		this->Load("GraphicsTest/heart.png");
	};
};

