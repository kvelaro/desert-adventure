#include "pch.h"
#include "Game.h"

Game* Game::spInstance = nullptr;

Game* Game::getInstance()
{
	if (spInstance == nullptr)
	{
		spInstance = new Game();
	}
	return spInstance;
}

void Game::init(string title)
{
	m_desktopWidth = VideoMode::getDesktopMode().width;
	m_desktopHeight = VideoMode::getDesktopMode().height;
	VideoMode vm(m_desktopWidth, m_desktopHeight);
	m_window = new RenderWindow(vm, title);
	m_gameState = new MenuState();
}

bool Game::isRunning() 
{
	return m_window->isOpen();
}

void Game::handleInput()
{
	m_gameState->handleInput();
}

void Game::update()
{
	m_gameState->update();
}

void Game::draw()
{
	m_window->clear();
	m_gameState->draw();
	m_window->display();
}

RenderWindow* Game::getWindow()
{
	return m_window;
}

int Game::getDesktopWidth()
{
	return m_desktopWidth;
}

int Game::getDesktopHeight()
{
	return m_desktopHeight;
}

void Game::quit() {
	m_window->close();
}