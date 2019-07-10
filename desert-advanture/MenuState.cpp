#include "pch.h"
#include "MenuState.h"
#include "Helper.h"


MenuState::MenuState()
{	
	m_textureBackground.loadFromFile("assets/img/desert.jpg");
	m_texturePlayButton.loadFromFile("assets/img/play.png");
	m_textureSoundButton.loadFromFile("assets/img/sound.png");
	m_textureExitButton.loadFromFile("assets/img/exit.png");

	m_textureActivePlayButton.loadFromFile("assets/img/play-active.png");
	m_textureActiveSoundButton.loadFromFile("assets/img/sound-active.png");
	m_textureActiveExitButton.loadFromFile("assets/img/exit-active.png");
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
	int desktopWidth = Game::getInstance()->getDesktopWidth();
	int desktopHeight = Game::getInstance()->getDesktopHeight();

	m_spriteBackground.setTexture(m_textureBackground);
	m_spriteBackground.setPosition(0, 0);

	m_mousePosition = Mouse::getPosition();

	FloatRect playRect = m_spritePlayButton.getGlobalBounds();
	FloatRect soundRect = m_spriteSoundButton.getGlobalBounds();
	FloatRect exitRect = m_spriteExitButton.getGlobalBounds();
	
	m_spritePlayButton.setScale(0.3, 0.3);
	m_spritePlayButton.setOrigin(playRect.width / 2, playRect.height / 2);
	m_spritePlayButton.setPosition(desktopWidth / 2 - 75, desktopHeight / 2 - 275);
	m_spritePlayButton.setTexture(m_texturePlayButton);
	if(Helper::isMouseonTop(playRect))
	{
		m_spritePlayButton.setTexture(m_textureActivePlayButton);
	}
	
	m_spriteSoundButton.setScale(0.3, 0.3);
	m_spriteSoundButton.setOrigin(soundRect.width / 2, soundRect.height / 2);
	m_spriteSoundButton.setPosition(desktopWidth / 2 - 75, desktopHeight / 2 - 75);
	m_spriteSoundButton.setTexture(m_textureSoundButton);
	if (Helper::isMouseonTop(soundRect))
	{
		m_spriteSoundButton.setTexture(m_textureActiveSoundButton);
	}
	
	m_spriteExitButton.setScale(0.3, 0.3);
	m_spriteExitButton.setOrigin(exitRect.width / 2, exitRect.height / 2);
	m_spriteExitButton.setPosition(desktopWidth / 2 - 75, desktopHeight / 2 + 125);
	m_spriteExitButton.setTexture(m_textureExitButton);
	if (Helper::isMouseonTop(exitRect))
	{
		m_spriteExitButton.setTexture(m_textureActiveExitButton);
	}

}

void MenuState::draw()
{
	Game::getInstance()->getWindow()->draw(m_spriteBackground);
	Game::getInstance()->getWindow()->draw(m_spritePlayButton);
	Game::getInstance()->getWindow()->draw(m_spriteSoundButton);
	Game::getInstance()->getWindow()->draw(m_spriteExitButton);
}

