#pragma once
#include "Game.h"
#include "GameState.h"
#include "StaticImage.h"

class PlayState :
	public GameState
{
	string m_stateID = "PLAY";
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

