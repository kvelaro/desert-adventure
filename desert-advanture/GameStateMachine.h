#pragma once
#include <iostream>
#include <vector>
#include "GameState.h"
using namespace std;

class GameStateMachine
{
	vector<GameState *> m_gameStates;
public:
	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();
	GameState *getCurrentState();
};

