#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
using namespace std;
using namespace sf;
class StaticImage :
	public GameObject
{
protected:
	Texture m_textureImage;
	Sprite m_spriteImage;	
	int m_positionX;
	int m_positionY;
	double m_scaleX;
	double m_scaleY;
	string m_id	= "STATICIMAGE";

public:
	StaticImage(string path, int positionX, int positionY, double scaleX, double scaleY);
	~StaticImage();
	virtual void handleInput();
	virtual void update();
	virtual void draw();
	virtual string getID();
	Sprite *getSprite();
	FloatRect getRect();
};

