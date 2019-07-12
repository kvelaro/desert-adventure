#include "pch.h"
#include "MenuButton.h"

MenuButton::MenuButton(string path, string pathActive, int positionX, int positionY, double scaleX, double scaleY, void (*callback)())
{
	m_path = path;
	m_pathActive = m_pathActive;
	m_textureMenuButton.loadFromFile(path);
	m_textureActiveMenuButton.loadFromFile(pathActive);
	m_positionX = positionX;
	m_positionY = positionY;
	m_scaleX = scaleX;
	m_scaleY = scaleY;
	m_callback = callback;
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
	
	bool mouseOnTop = Helper::isMouseonTop(buttonRect);
	if (mouseOnTop)
	{
		m_spriteMenuButton.setTexture(m_textureActiveMenuButton);
		if (static_cast<MenuState*>(Game::getInstance()->getStateMachine()->getCurrentState())->isMouseClicked())
		{
			if (m_callback != nullptr)
			{
				m_callback();
			}
		}
	}
}

void MenuButton::draw()
{
	Game::getInstance()->getWindow()->draw(m_spriteMenuButton);
}

string MenuButton::getID()
{
	return m_id;
}

FloatRect MenuButton::getRect()
{
	return m_spriteMenuButton.getGlobalBounds();
}
