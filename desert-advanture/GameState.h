#pragma once
#include <iostream>
#include <vector>
#include "GameObject.h"
using namespace std;
class GameState
{
protected:
	vector<GameObject*> m_gameObjects;
public:
	GameState();
	~GameState();
	virtual void handleInput() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};

