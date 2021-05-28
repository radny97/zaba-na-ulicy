#include "ScoreText.h"

void ScoreText::UpdateScore()
{
	this->setString("Score: " + std::to_string(this->value));
}