#pragma once
#include <SFML/Graphics.hpp>
#include "ApplicationState.h"

class StateMachine
{
public:
	StateMachine()
	{
		this->state = NULL;
	}
	void SetWindow(sf::RenderWindow* window)
	{
		this->window = window;
	}
	void SetState(ApplicationState* state)
	{
		if (this->state != NULL)
		{
			this->state->Destroy(this->window);
		}

		this->state = state;
		if (this->state != NULL)
		{
			this->state->Initialize(this->window);
		}
	}
	void Update()
	{
		if (this->state != NULL)
		{
			this->state->Update(this->window);
		}
	}
	void Render()
	{
		if (this->state != NULL)
		{
			this->state->Render(this->window);
		}
	}
	~StateMachine()
	{
		if (this->state != NULL)
		{
			this->state->Destroy(this->window);
		}
	}
private:
	sf::RenderWindow* window;
	ApplicationState* state;
};