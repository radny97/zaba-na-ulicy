#pragma once
#include <string>
#include <cmath>

class Object
{
public:
	Object() {};

	float posX;
	float posY;
	std::string type;
	int ID;

protected:
	int GenerateID();
};