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
	//this->gameLogic->Update();
	this->gameGraphics->Update(window, this->gameLogic->Update());

}

//void GameState::Render(sf::RenderWindow* window)
//{
	
//}

void GameState::Destroy(sf::RenderWindow* window)
{
	
}