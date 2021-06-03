#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class ScoreText : public sf::Text
{
public:
	ScoreText() 
	{
		sf::Font* font = new sf::Font();
		//font = new sf::Font();
		font->loadFromFile("Fonts\\PressStart2P-Regular.ttf");

		this->setString("Score: 0");
		this->setFont(*font);
		this->setCharacterSize(60);
		this->setPosition(40, 40);
	};
	void UpdateScore();

	//sf::Font* font;// = new sf::Font();

	int value;
};

