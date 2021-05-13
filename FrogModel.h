#pragma once

class FrogModel
{
//public:
	//Player(Score* score, Object_manager* manager, float x, float y);


	//void Update(sf::RenderWindow* window);
	//void Collision(Objects* object);
public:
	FrogModel();
	FrogModel(float x, float y)
	{
		this->posX = x;
		this->posY = y;
	}
	float posX;
	float posY;
};