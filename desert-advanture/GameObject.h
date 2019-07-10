#pragma once
class GameObject
{
public:
	virtual void handleInput() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};

