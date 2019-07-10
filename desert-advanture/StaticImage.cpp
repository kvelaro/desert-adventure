#include "pch.h"
#include "StaticImage.h"
#include "Game.h"

StaticImage::StaticImage(string path, int positionX, int positionY, double scaleX, double scaleY)
{
	m_textureImage.loadFromFile(path);	
	m_positionX = positionX;
	m_positionY = positionY;
	m_scaleX = scaleX;
	m_scaleY = scaleY;
	m_spriteImage.setTexture(m_textureImage);
}

StaticImage::~StaticImage()
{

}

void StaticImage::handleInput()
{
}

void StaticImage::update()
{
	m_spriteImage.setScale(m_scaleX, m_scaleY);
	m_spriteImage.setPosition(m_positionX, m_positionY);
}

void StaticImage::draw()
{
	Game::getInstance()->getWindow()->draw(m_spriteImage);
}
