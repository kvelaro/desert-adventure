#pragma once
#include "Game.h"
#include "StaticImage.h"

class Cactus : public StaticImage
{
private:
	int m_speedFactor;
	float m_scaleFactor;
protected:
	string m_id = "CACTUS";
public:
	Cactus(string path, int positionX, int positionY, double scaleX, double scaleY);
	~Cactus();
	virtual void handleInput();
	virtual void update();
	virtual void draw();
	virtual string getID();
	FloatRect getRect();
};

