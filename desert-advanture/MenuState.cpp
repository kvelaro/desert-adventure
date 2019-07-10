#include "pch.h"
#include "MenuState.h"
#include "Helper.h"
#include "StaticImage.h"
#include "MenuButton.h"


MenuState::MenuState()
{		
	int desktopWidth = Game::getInstance()->getDesktopWidth();
	int desktopHeight = Game::getInstance()->getDesktopHeight();

	StaticImage *backgoundImage = new StaticImage("assets/img/desert.jpg", 0, 0, 1, 1);
	m_gameObjects.push_back(backgoundImage);
	MenuButton *playButton = new MenuButton("assets/img/play.png", "assets/img/play-active.png", desktopWidth / 2 - 75, desktopHeight / 2 - 275, 0.3, 0.3);
	m_gameObjects.push_back(playButton);
	MenuButton *soundButton = new MenuButton("assets/img/sound.png", "assets/img/sound-active.png", desktopWidth / 2 - 75, desktopHeight / 2 - 75, 0.3, 0.3);
	m_gameObjects.push_back(soundButton);
	MenuButton *exitButton = new MenuButton("assets/img/exit.png", "assets/img/exit-active.png", desktopWidth / 2 - 75, desktopHeight / 2 + 125, 0.3, 0.3);
	m_gameObjects.push_back(exitButton);
}


MenuState::~MenuState()
{
}

void MenuState::handleInput()
{
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		Game::getInstance()->quit();
	}

	Event event;

	// while there are pending events...
	while (Game::getInstance()->getWindow()->pollEvent(event))
	{		
		switch (event.type)
		{		
		case Event::MouseButtonPressed:	
				m_mousePosition = Mouse::getPosition();
				break;			
		default:
			break;
		}
	}

}

void MenuState::update()
{
	for (vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	m_spriteBackground.setTexture(m_textureBackground);
	m_spriteBackground.setPosition(0, 0);
}

void MenuState::draw()
{
	Game::getInstance()->getWindow()->draw(m_spriteBackground);
	for (vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

