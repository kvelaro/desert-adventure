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
	m_window = new RenderWindow(vm, title, Style::Fullscreen);
	m_window->setFramerateLimit(60);
	m_gameStateMachine = new GameStateMachine();
	m_gameStateMachine->pushState(new MenuState());
}

bool Game::isRunning() 
{
	return m_window->isOpen();
}

void Game::handleInput()
{
	m_gameStateMachine->getCurrentState()->handleInput();
}

void Game::update()
{
	m_gameStateMachine->getCurrentState()->update();
}

void Game::draw()
{
	m_window->clear();
	m_gameStateMachine->getCurrentState()->draw();
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

GameStateMachine * Game::getStateMachine()
{
	return m_gameStateMachine;
}

void Game::quit() {
	m_window->close();
}

void Game::toggleSound()
{
	m_soundAllowed = !m_soundAllowed;
}