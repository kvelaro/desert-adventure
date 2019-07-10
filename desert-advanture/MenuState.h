#pragma once
#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "Game.h"

using namespace sf;
class MenuState :
	public GameState
{
	Texture m_textureBackground;
	Texture m_texturePlayButton;
	Texture m_textureSoundButton;
	Texture m_textureExitButton;
	Texture m_textureActivePlayButton;
	Texture m_textureActiveSoundButton;
	Texture m_textureActiveExitButton;
	Sprite m_spriteBackground;
	Sprite m_spritePlayButton;
	Sprite m_spriteSoundButton;
	Sprite m_spriteExitButton;
	Vector2i m_mousePosition;
public:
	MenuState();
	~MenuState();
	virtual void handleInput();
	virtual void update();
	virtual void draw();
};

