#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "GameObject.h"
#include "Helper.h"
using namespace std;
using namespace sf;

class MenuButton :
	public GameObject
{
	Texture m_textureMenuButton;
	Texture m_textureActiveMenuButton;
	Sprite m_spriteMenuButton;
	int m_positionX;
	int m_positionY;
	double m_scaleX;
	double m_scaleY;
	
public:
	MenuButton(string path, string pathActive, int positionX, int positionY, double scaleX, double scaleY);
	~MenuButton();
	virtual void handleInput();
	virtual void update();
	virtual void draw();

};

