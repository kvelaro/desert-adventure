#pragma once
#include <iostream>
#include <string>
#include "Game.h"
#include "StaticImage.h"
using namespace std;
class Player : public StaticImage {
	Clock clock;
	bool m_jumpNeeded = false;
	int m_initialPositionX;
	int m_initialPositionY;
	Vector2f m_speedUp;
	int m_maxJumpY = 600;
	bool m_jumpDirectionUp = true;
protected:
	string m_id = "PLAYER";
public:
	Player(string path, int positionX, int positionY, double scaleX, double scaleY);
	~Player();
	virtual void handleInput();
	virtual void update();
	virtual void draw();
	void drawCurrentFrame();
	void drawJump();
	virtual string getID();
	FloatRect getRect();	
};

