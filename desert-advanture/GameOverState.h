#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameState.h"
#include "Game.h"
#include "StaticText.h"

using namespace std;
using namespace sf;
class GameOverState : public GameState
{
	string m_stateID = "GAMEOVER";
protected:
	SoundBuffer m_gameOverSoundBuffer;
	Sound m_gameOverSound;
public:
	GameOverState();
	~GameOverState();
	virtual void handleInput();
	virtual void update();
	virtual void draw();
	virtual void onEnter();
	virtual void onExit();
	virtual string getStateID();
};

