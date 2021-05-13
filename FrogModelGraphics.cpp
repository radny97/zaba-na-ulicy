#include "FrogModelGraphics.h"

FrogModelGraphics::FrogModelGraphics()
{
	this->texture = new sf::Texture();
	this->Load("player.png");
}

void FrogModelGraphics::Load(std::string filename)
{
	//this->texture->loadFromFile("grafika\\" + filename); //loadFromFile("grafika\\background.jpg"
	this->texture->loadFromFile(filename);
	this->setTexture(*this->texture);
}