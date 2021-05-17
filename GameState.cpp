#include "GameState.h"

GameState::GameState(StateMachine* stateMachine)
{
	this->stateMachine = stateMachine;
}

void GameState::Initialize(sf::RenderWindow* window)
{
	this->gameLogic = new GameLogic();
	this->gameGraphics = new GameGraphics();
}

void GameState::Update(sf::RenderWindow* window)
{
	this->gameLogic->UpdateLogic();

	this->gameGraphics->Update(this->gameLogic->GetAllObjects());
	this->gameGraphics->Render(window);
}

void GameState::Destroy(sf::RenderWindow* window)
{
	delete this->gameLogic;
	delete this->gameGraphics;
}