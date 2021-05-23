#include "FrogObject.h"

//FrogObject::FrogObject()
//{
//}

void FrogObject::SetPosX(float x)
{
	this->posX = x - (Utilities::frogImageSizeX / 2);
}

bool FrogObject::CheckIfCollisionPointIsInBounds(Point point)
{
	if (point.coordinateX > this->posX
		&& point.coordinateX < this->posX + Utilities::frogImageSizeX
		&& point.coordinateY > this->posY + (Utilities::frogImageSizeY / 6)
		&& point.coordinateY < this->posY + ((5 * Utilities::frogImageSizeY) / 6)
		) {
		return true;
	}
	return false;
}