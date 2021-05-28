#pragma once

enum velocity
{
	verySlowVelocity = 1,
	slowVelocity = 3,
	mediumVelocity = 5,
	fastVelocity = 7,
	veryFastVelocity = 9
};

enum class CollisionType
{
	noCollision = 0,
	frogCarCollision = 1,
	carCarColision = 2
};

enum class SubStateOfGame
{
	game = 0,
	pause = 1,
	gameOver = 2,
	nextLevel = 3
};