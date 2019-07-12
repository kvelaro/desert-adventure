#include "pch.h"
#include "Cactus.h"


Cactus::Cactus(string path, int positionX, int positionY, double scaleX, double scaleY): StaticImage(path, positionX, positionY, scaleX, scaleY)
{
	srand((int)time(0));
	m_scaleFactor = rand() % 10 / 10.0;
	float m_scaleFactor = rand() % 10 / 10.0;
	if (m_scaleFactor > 0.5)
	{
		m_scaleFactor = 0.5;
	}
	m_spriteImage.setScale(m_scaleFactor, m_scaleFactor);

	FloatRect spriteRect = m_spriteImage.getGlobalBounds();
	m_spriteImage.setOrigin(0, 0);
	m_spriteImage.setPosition(m_positionX, m_positionY);

	//@todo for now
	m_speedFactor = 20;
}

Cactus::~Cactus()
{
}

void Cactus::handleInput()
{
}

void Cactus::update()
{
	Vector2f spriteCurrentPosition = m_spriteImage.getPosition();
	
	//object on the screen
	if (spriteCurrentPosition.x >= 0 && spriteCurrentPosition.x <= Game::getInstance()->getDesktopWidth()) {		
		FloatRect spriteRect = m_spriteImage.getGlobalBounds();
		m_spriteImage.setPosition(spriteCurrentPosition.x - m_speedFactor, Game::getInstance()->getDesktopHeight() - (spriteRect.height - 20));
	}
	//create new one
	else {		
		float m_scaleFactor = rand() % 10 / 10.0;		
		if (m_scaleFactor > 0.5)
		{
			m_scaleFactor = 0.5;
		}
		m_spriteImage.setScale(m_scaleFactor, m_scaleFactor);
		FloatRect spriteRect = m_spriteImage.getGlobalBounds();
		m_spriteImage.setPosition(m_positionX, Game::getInstance()->getDesktopHeight() - (spriteRect.height - 20));
	}
}

void Cactus::draw()
{
	Game::getInstance()->getWindow()->draw(m_spriteImage);
}

string Cactus::getID()
{
	return m_id;
}

FloatRect Cactus::getRect()
{
	return m_spriteImage.getGlobalBounds();
}
