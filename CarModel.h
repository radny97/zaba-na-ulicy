#pragma once
#include "Model.h"

class CarModel : public Model
{
public:
	CarModel();
	CarModel(float x, float y)
	{
		this->posX = x;
		this->posY = y;
	}
};