#pragma once
#include "PauseScreenSprite.h"
#include "Utilities.h"

class PauseScreenGraphics
{
public:
	PauseScreenGraphics() {
		this->pauseScreenSprite = new PauseScreenSprite();

		sf::Font* font = new sf::Font();
		font->loadFromFile("Fonts\\PressStart2P-Regular.ttf");

		this->mainText = new sf::Text;
		this->mainText->setString("Pauza");
		this->mainText->setFont(*font);
		this->mainText->setCharacterSize(80);
		this->mainText->setFillColor(sf::Color::Red);
		//this->mainText.setPosition(40, 40);

		sf::FloatRect mainTextRect = this->mainText->getLocalBounds();
		this->mainText->setOrigin(mainTextRect.width / 2, mainTextRect.height / 2);
		this->mainText->setPosition(sf::Vector2f(Utilities::screenResolutionX / 2, Utilities::screenResolutionY / 3));
		
		this->descriptionText = new sf::Text;
		this->descriptionText->setString("Enter - powrót do gry\n\nEscape - wyjscie z gry");
		this->descriptionText->setFont(*font);
		this->descriptionText->setCharacterSize(40);
		this->descriptionText->setFillColor(sf::Color::Red);
		//this->descriptionText.setPosition(40, 40);

		sf::FloatRect descriptionTextRect = this->descriptionText->getLocalBounds();
		this->descriptionText->setOrigin(descriptionTextRect.width / 2, descriptionTextRect.height / 2);
		this->descriptionText->setPosition(sf::Vector2f(Utilities::screenResolutionX / 2, Utilities::screenResolutionY / 2));
	};

	PauseScreenSprite* pauseScreenSprite;
	sf::Text* mainText;
	sf::Text* descriptionText;
	//sf::Font font;
};

