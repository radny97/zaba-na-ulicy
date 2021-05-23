#pragma once
#include "Object.h"

class CarObject : public Object
{
public:
	CarObject() {};
	CarObject(int x, int y, bool fromDownToUp)
	{
		this->posX = x - (Utilities::carImageSizeX / 2);
		this->posY = y - (Utilities::carImageSizeY / 2);
		this->type = "car";
		this->ID = GenerateID();
		this->fromDownToUp = fromDownToUp;

		UpdateCollisionPoints();
	}

	bool CheckIfCollisionPointIsInBounds(Point point) override;
	void Move(int velocity) override;

	Point *frontCollisionPoint; //middle of front bumper of car
	Point *backCollisionPoint; //middle of back bumper of car

	bool fromDownToUp;

private:
	void UpdateCollisionPoints();
};