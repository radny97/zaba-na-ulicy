#pragma once
#include <SFML/Graphics.hpp>
#include "ApplicationState.h"
#include "StateMachine.h"
#include "GameLogic.h"
#include "GameGraphics.h"

class GameState : public ApplicationState
{
public:
	GameState(StateMachine* core_state);

	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
//	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

private:
	StateMachine* stateMachine;
	GameLogic* gameLogic;
	GameGraphics* gameGraphics;

	sf::Sprite* background;  /*!< wskaŸnik na grafikê do za³adowania */
	sf::Texture* texture;  /*!< wskaŸnik na teksturê, która zostanie u¿yta jako t³o */
};
