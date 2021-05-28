#include "ObjectSprite.h"

ObjectSprite::ObjectSprite()
{
	//this->texture = new sf::Texture();
	//this->Load("GraphicsTest/car from bottom.png");
}

void ObjectSprite::Load(std::string filename)
{
	//this->texture->loadFromFile("grafika\\" + filename); //loadFromFile("grafika\\background.jpg"
	this->texture->loadFromFile(filename);
	this->setTexture(*this->texture);
}