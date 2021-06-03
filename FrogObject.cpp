#include "FrogObject.h"

//FrogObject::FrogObject()
//{
//}

void FrogObject::SetPosX(float x)
{
	this->posX = x - (Utilities::frogImageSizeX / 2);
}

bool FrogObject::CheckIfCollisionPointIsInBounds(Point point)
{
	if (point.coordinateX > this->posX
		&& point.coordinateX < this->posX + Utilities::frogImageSizeX
		&& point.coordinateY > this->posY + (Utilities::frogImageSizeY / 6)
		&& point.coordinateY < this->posY + ((5 * Utilities::frogImageSizeY) / 6)
		) {
		return true;
	}
	return false;
}

void FrogObject::UpdateObject()
{
	this->elapsedTime = this->timer.getElapsedTime();
	if (this->elapsedTime.asMilliseconds() > 2000 && this->waitAfterStart == true && this->stateOfFrog == StateOfFrog::wait)
	{
		this->timer.restart();
		this->waitAfterStart = false;
		this->stateOfFrog = StateOfFrog::normalStanding;
	}
	
	if (this->activateJump == true && this->stateOfFrog == StateOfFrog::normalStanding)
	{
		this->timer.restart();
		this->stateOfFrog = StateOfFrog::beforeAfterJump;
		
	}

	this->elapsedTime = this->timer.getElapsedTime();
	if (this->elapsedTime.asMilliseconds() > 500 && this->stateOfFrog == StateOfFrog::beforeAfterJump && this->activateJump == true)
	{
		if (this->destinationOfJump < this->posX)
		{
			this->velocity = velocity::fastVelocity;
			this->stateOfFrog = StateOfFrog::jumpForwards;
			this->collisional = false;
		}
		else if (this->destinationOfJump > this->posX)
		{
			this->velocity = - velocity::fastVelocity;
			this->stateOfFrog = StateOfFrog::jumpBackwards;
			this->collisional = false;
		}
	}

	if ((this->posX < this->destinationOfJump && this->stateOfFrog == StateOfFrog::jumpForwards) || (this->posX > this->destinationOfJump && this->stateOfFrog == StateOfFrog::jumpBackwards))
	{
		if (this->stateOfFrog == StateOfFrog::jumpForwards)
		{
			Player::getInstance().SetScore(Player::getInstance().GetScore() + 1);
			//this->player->score++;
		}
		if (this->stateOfFrog == StateOfFrog::jumpBackwards)
		{
			Player::getInstance().SetScore(Player::getInstance().GetScore() - 1);
			//this->player->score--;
		}
		
		SetPosX(this->destinationOfJump);
		this->velocity = 0;
		this->collisional = true;
		this->stateOfFrog = StateOfFrog::beforeAfterJump;
		this->activateJump = false;
		this->timer.restart();
	}

	this->elapsedTime = this->timer.getElapsedTime();
	if (this->elapsedTime.asMilliseconds() > 100 && this->stateOfFrog == StateOfFrog::beforeAfterJump && this->activateJump == false)
	{
		this->stateOfFrog = StateOfFrog::normalStanding;
	}

	if (this->activateDeath == true && this->stateOfFrog == StateOfFrog::normalStanding)
	{
		this->collisional = false;
		this->stateOfFrog = StateOfFrog::death;
		this->timer.restart();
	}

	this->elapsedTime = this->timer.getElapsedTime();
	if (this->elapsedTime.asMilliseconds() > 2000 && this->stateOfFrog == StateOfFrog::death && this->activateDeath == true)
	{
		SetPosX(this->destinationOfJump);
		this->activateDeath = false;
		this->stateOfFrog = StateOfFrog::normalStanding;
		this->collisional = true;
		if (Player::getInstance().GetLives() != 0)
		{
			Player::getInstance().SetLives(Player::getInstance().GetLives() - 1);
			//this->player->lives -= 1;
		}
		if (Player::getInstance().GetLives() != 0)
		{
			Player::getInstance().SetScore(Player::getInstance().GetScore() - this->scoreToDelete);
		}
		
		//player->score -= this->scoreToDelete;
	}

	Move();
}

void FrogObject::Move()
{
	this->posX -= this->velocity;
}

void FrogObject::Jump(float destination)
{

		this->destinationOfJump = destination;
		this->activateJump = true;
}

void FrogObject::Death(float XcoordinateOfStart, int scoreToDelete)
{
	this->destinationOfJump = XcoordinateOfStart;
	this->activateDeath = true;
	this->activateJump = false;
	this->scoreToDelete = scoreToDelete;
}