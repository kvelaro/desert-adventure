#include "pch.h"
#include "PlayState.h"


PlayState::PlayState()
{
	int desktopWidth = Game::getInstance()->getDesktopWidth();
	int desktopHeight = Game::getInstance()->getDesktopHeight();

	StaticImage *backgoundImage = new StaticImage("assets/img/desert.jpg", 0, 0, 1, 1);
	m_gameObjects.push_back(backgoundImage);
}


PlayState::~PlayState()
{
}

void PlayState::handleInput()
{
}

void PlayState::update()
{
	for (vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void PlayState::draw()
{
	for (vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

void PlayState::onEnter()
{
}

void PlayState::onExit()
{
}

string PlayState::getStateID()
{
	return m_stateID;
}
