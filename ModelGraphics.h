#pragma once
#include <SFML/Graphics.hpp>

class ModelGraphics : public sf::Sprite
{
public:
	float posX;
	float posY;
	sf::Texture* texture;
	
	ModelGraphics();
	void Load(std::string filename);
};