#include "pch.h"
#include "MenuButton.h"


MenuButton::MenuButton(string path, string pathActive, int positionX, int positionY, double scaleX, double scaleY)
{
	m_textureMenuButton.loadFromFile(path);
	m_textureActiveMenuButton.loadFromFile(pathActive);
	m_positionX = positionX;
	m_positionY = positionY;
	m_scaleX = scaleX;
	m_scaleY = scaleY;	
}


MenuButton::~MenuButton()
{
}

void MenuButton::handleInput()
{

}

void MenuButton::update()
{
	m_spriteMenuButton.setScale(m_scaleX, m_scaleY);
	m_spriteMenuButton.setPosition(m_positionX, m_positionY);
	FloatRect buttonRect = m_spriteMenuButton.getGlobalBounds();
	m_spriteMenuButton.setOrigin(buttonRect.width / 2, buttonRect.height / 2);
	m_spriteMenuButton.setTexture(m_textureMenuButton);
	if (Helper::isMouseonTop(buttonRect))
	{
		m_spriteMenuButton.setTexture(m_textureActiveMenuButton);
	}
}

void MenuButton::draw()
{
	Game::getInstance()->getWindow()->draw(m_spriteMenuButton);
}