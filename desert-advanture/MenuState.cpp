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
	MenuButton *playButton = new MenuButton("assets/img/play.png", "assets/img/play-active.png", desktopWidth / 2 - 75, desktopHeight / 2 - 275, 0.3, 0.3, s_playCallback);
	m_gameObjects.push_back(playButton);
	MenuButton *soundButton = new MenuButton("assets/img/sound.png", "assets/img/sound-active.png", desktopWidth / 2 - 75, desktopHeight / 2 - 75, 0.3, 0.3, s_soundCallback);
	m_gameObjects.push_back(soundButton);
	MenuButton *exitButton = new MenuButton("assets/img/exit.png", "assets/img/exit-active.png", desktopWidth / 2 - 75, desktopHeight / 2 + 125, 0.3, 0.3, s_exitCallback);
	m_gameObjects.push_back(exitButton);
}


MenuState::~MenuState()
{
}

void MenuState::handleInput()
{
	//Handle game-object specific events - does it needed?
	for (vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->handleInput();
	}
	//handle state-specific events
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		Game::getInstance()->quit();
	}
	if (m_mouseButtonClicked == true)
	{
		m_mouseButtonClicked = false;
	}

	Event event;
	// while there are pending events...
	while (Game::getInstance()->getWindow()->pollEvent(event))
	{
		switch (event.type)
		{
		case Event::MouseButtonPressed:
			m_mouseButtonPressed = true;
			break;
		case Event::MouseButtonReleased:
			m_mouseButtonReleased = true;
			break;
		default:
			break;
		}
		if (m_mouseButtonPressed && m_mouseButtonReleased)
		{
			m_mouseButtonPressed = false;
			m_mouseButtonReleased = false;
			m_mouseButtonClicked = true;
		}
	}
}

void MenuState::update()
{
	for (vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::draw()
{
	for (vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

void MenuState::onEnter()
{
}

void MenuState::onExit()
{
}

string MenuState::getStateID()
{
	return m_stateID;
}

void MenuState::s_exitCallback()
{
	Game::getInstance()->quit();
}

void MenuState::s_playCallback()
{
	Game::getInstance()->getStateMachine()->popState();
	Game::getInstance()->getStateMachine()->pushState(new PlayState);
}

void MenuState::s_soundCallback()
{

}

bool MenuState::isMouseClicked()
{
	return m_mouseButtonClicked;
}

