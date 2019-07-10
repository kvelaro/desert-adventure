#pragma once
#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "Game.h"
#include "PlayState.h"

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
	bool m_mouseButtonPressed = false;
	bool m_mouseButtonReleased = false;
	bool m_mouseButtonClicked = false;
	string m_stateID = "MENU";

public:
	MenuState();
	~MenuState();
	virtual void handleInput();
	virtual void update();
	virtual void draw();
	virtual void onEnter();
	virtual void onExit();
	virtual string getStateID();
	static void s_playCallback();
	static void s_soundCallback();
	static void s_exitCallback();
	bool isMouseClicked();
};

