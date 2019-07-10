#pragma once
class GameState
{
public:
	GameState();
	~GameState();
	virtual void handleInput() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};

