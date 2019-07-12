#include "pch.h"
#include "Player.h"

Player::Player(string path, int positionX, int positionY, double scaleX, double scaleY) : StaticImage(path, positionX, positionY, scaleX, scaleY)
{
	m_initialPositionX = positionX;
	m_initialPositionY = positionY;
	m_positionX = m_initialPositionX;
	m_positionY = m_initialPositionY;
	m_spriteImage.setPosition(m_positionX, m_positionY);
	m_spriteImage.setOrigin(25, 35);
	m_spriteImage.setScale(m_scaleX, m_scaleY);	
	cout << "init => " << m_initialPositionY << endl;
}

Player::~Player()
{
}



void Player::handleInput()
{
	if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::Space)) {
		m_jumpNeeded = true;
	}
}

void Player::update()
{
	this->drawCurrentFrame();
	if (m_jumpNeeded)
	{
		this->drawJump();
	}
}

void Player::drawCurrentFrame()
{
	Time elapsedTime = clock.getElapsedTime();
	int currentFrame = (elapsedTime.asMilliseconds() / 100) % 6;
	m_spriteImage.setTextureRect(IntRect(currentFrame * 50, 0, 50, 70));
}

void Player::drawJump()
{
	Vector2f spriteCurrentPosition = m_spriteImage.getPosition();
	//if the player jumped and it's direction is up
	if (m_jumpDirectionUp) {
		m_speedUp.y = -20;		
		if (spriteCurrentPosition.y >= m_initialPositionY - m_maxJumpY)
		{
			m_spriteImage.setPosition(m_positionX, spriteCurrentPosition.y + m_speedUp.y);
		}
		else {
			m_jumpDirectionUp = false;
		}
	}
	if (!m_jumpDirectionUp)
	{
		m_speedUp.y = 20;
		if (m_initialPositionY >= spriteCurrentPosition.y)
		{
			float newYDirection = spriteCurrentPosition.y + m_speedUp.y;
			if (newYDirection >= m_initialPositionY) {
				newYDirection = m_initialPositionY;
				m_jumpNeeded = false;
				m_jumpDirectionUp = true;
			}
			cout << "newYDirection => " << newYDirection << endl;
			m_spriteImage.setPosition(m_positionX, newYDirection);
		}
	}
}

string Player::getID()
{
	return m_id;
}

FloatRect Player::getRect()
{
	return m_spriteImage.getGlobalBounds();
}

void Player::draw()
{
	Game::getInstance()->getWindow()->draw(m_spriteImage);
}
