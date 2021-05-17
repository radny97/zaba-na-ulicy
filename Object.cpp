#include "Object.h"

//Object::Object()
//{
//
//}

int Object::GenerateID()
{
	uint32_t id = reinterpret_cast<uint32_t>(this);
	return abs((int)id);
}