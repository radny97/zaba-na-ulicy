#pragma once
#include "Object.h"

class FrogObject : public Object
{
public:
	FrogObject() {};
	FrogObject(float x, float y)
	{
		this->posX = x - (Utilities::frogImageSizeX / 2);
		this->posY = y - (Utilities::frogImageSizeY / 2);
		this->type = "frog";
		this->ID = GenerateID();
	}
	bool CheckIfCollisionPointIsInBounds(Point point) override;
	void SetPosX(float x) override;
};