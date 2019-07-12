#pragma once
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class GameObject
{
protected:
	string m_id;
public:
	virtual void handleInput() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual string getID() = 0;
	virtual FloatRect getRect() = 0;
};

