#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameStateMachine.h"
#include "MenuState.h"
using namespace std;
using namespace sf;

class Game{
	int m_desktopWidth;
	int m_desktopHeight;
	static Game* spInstance;	
	RenderWindow *m_window;
	GameStateMachine* m_gameStateMachine;	
	
public:
	static Game* getInstance();
	void init(string title);
	bool isRunning();
	void handleInput();
	void update();
	void draw();
	void quit();
	RenderWindow* getWindow();
	int getDesktopWidth();
	int getDesktopHeight();
	GameStateMachine* getStateMachine();
};

