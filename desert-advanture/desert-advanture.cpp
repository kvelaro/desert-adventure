// desert-advanture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Game.h"

int main()
{
	Game *pGameInstance = Game::getInstance();
	pGameInstance->init("Desert adventure");
	while(pGameInstance->isRunning())
	{
		/*
		HANDLE PLAYER INPUT
		*/
		pGameInstance->handleInput();
		/*
		UPDATE SCENE
		*/
		pGameInstance->update();
		/*
		DRAW SCENE
		*/
		pGameInstance->draw();
	}

}