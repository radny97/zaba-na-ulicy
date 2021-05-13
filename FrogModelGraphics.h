#pragma once
#include <SFML/Graphics.hpp>

class FrogModelGraphics : public sf::Sprite
{
public:
	FrogModelGraphics();

	float posX;
	float posY;

	void Load(std::string filename);

private:
	sf::Texture* texture;
};