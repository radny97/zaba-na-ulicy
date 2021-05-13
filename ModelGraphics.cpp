#include "ModelGraphics.h"

ModelGraphics::ModelGraphics()
{
	this->texture = new sf::Texture();
	this->Load("player.png");
}

void ModelGraphics::Load(std::string filename)
{
	//this->texture->loadFromFile("grafika\\" + filename); //loadFromFile("grafika\\background.jpg"
	this->texture->loadFromFile(filename);
	this->setTexture(*this->texture);
}