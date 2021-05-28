#pragma once
#include "ObjectSprite.h"

class TrackSprite : public ObjectSprite
{
public:
	TrackSprite()
	{
		this->texture = new sf::Texture();
		this->Load("GraphicsTest/road.png");
	};
};
