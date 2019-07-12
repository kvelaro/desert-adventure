#pragma once
#include "Helper.h"
#include "Game.h"
#include "GameState.h"
#include "StaticImage.h"
#include "Player.h"
#include "Cactus.h"

class PlayState : public GameState
{
	string m_stateID = "PLAY";
	bool m_doNotUpdate = false;
public:
	PlayState();
	~PlayState();
	virtual void handleInput();
	virtual void update();
	virtual void draw();
	virtual void onEnter();
	virtual void onExit();
	virtual string getStateID();	
};

