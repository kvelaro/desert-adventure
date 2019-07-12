#include "pch.h"
#include "PlayState.h"
#include "Score.h"

PlayState::PlayState()
{
	int desktopWidth = Game::getInstance()->getDesktopWidth();
	int desktopHeight = Game::getInstance()->getDesktopHeight();

	StaticImage *backgoundImage = new StaticImage("assets/img/desert.jpg", 0, 0, 1, 1);
	m_gameObjects.push_back(backgoundImage);

	StaticText *scoreText = new Score("assets/fonts/DMSerifDisplay-Regular.ttf", "Score:", 100, Color::Black, 200, 100);
	m_gameObjects.push_back(scoreText);

	Cactus *cactus = new Cactus("assets/img/cactus.png", desktopWidth, desktopHeight - 150, 1, 1);
	m_gameObjects.push_back(cactus);

	Player *playerImage = new Player("assets/img/player.png", desktopWidth / 2 - 50, desktopHeight - 70, 2, 2);
	m_gameObjects.push_back(playerImage);
}


PlayState::~PlayState()
{
}

void PlayState::handleInput()
{
	//Handle game-object specific events - does it needed?
	for (vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->handleInput();
	}	
	//handle state-specific events
	if (Keyboard::isKeyPressed(Keyboard::P))
	{
		m_doNotUpdate = !m_doNotUpdate;
	}
	
}

void PlayState::update()
{
	if (!m_doNotUpdate)
	{
		GameObject* playerObject = nullptr;
		GameObject* cactusObject = nullptr;
		for (vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
		{
			m_gameObjects[i]->update();
			string id = m_gameObjects[i]->getID();
			if (id == "PLAYER")
			{
				playerObject = m_gameObjects[i];
			}
			if (id == "CACTUS")
			{
				cactusObject = m_gameObjects[i];
			}
		}
		//collision detection
		FloatRect playerRect = playerObject->getRect();
		FloatRect cactusRect = cactusObject->getRect();
		if (Helper::collision(playerRect, cactusRect))
		{
			Game::getInstance()->getStateMachine()->changeState(new GameOverState());
		}		
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
