#include "pch.h"
#include "GameOverState.h"


GameOverState::GameOverState()
{
	int desktopWidth = Game::getInstance()->getDesktopWidth();
	int desktopHeight = Game::getInstance()->getDesktopHeight();

	
	m_gameOverSoundBuffer.loadFromFile("assets/sound/out_of_time.wav");	
	m_gameOverSound.setBuffer(m_gameOverSoundBuffer);	

	StaticImage *backgoundImage = new StaticImage("assets/img/desert.jpg", 0, 0, 1, 1);
	m_gameObjects.push_back(backgoundImage);

	StaticText *gameOverText = new StaticText("assets/fonts/DMSerifDisplay-Regular.ttf", "Game over", 150, Color::Red, desktopWidth / 2, desktopHeight / 2);
	m_gameObjects.push_back(gameOverText);

	StaticText *enterText = new StaticText("assets/fonts/DMSerifDisplay-Regular.ttf", "Press ENTER to restart game", 50, Color::Black, desktopWidth / 2, desktopHeight / 2 + 200);
	m_gameObjects.push_back(enterText);
	
	StaticText *escapeText = new StaticText("assets/fonts/DMSerifDisplay-Regular.ttf", "Press ESCAPE to quit game", 50, Color::Black, desktopWidth / 2, desktopHeight / 2 + 250);
	m_gameObjects.push_back(escapeText);
	m_gameOverSound.play();
}


GameOverState::~GameOverState()
{
}

void GameOverState::handleInput()
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
	if (Keyboard::isKeyPressed(Keyboard::Enter))
	{
		Game::getInstance()->getStateMachine()->changeState(new PlayState());
	}
}

void GameOverState::update()
{
	for (vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void GameOverState::draw()
{
	for (vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

void GameOverState::onEnter()
{
}

void GameOverState::onExit()
{
}

string GameOverState::getStateID()
{
	return string();
}
