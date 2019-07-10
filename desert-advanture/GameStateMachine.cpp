#include "pch.h"
#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState * pState)
{
	m_gameStates.push_back(pState);
	pState->onEnter();
}

void GameStateMachine::changeState(GameState * pState)
{
	if (!m_gameStates.empty())
	{
		if (m_gameStates.back()->getStateID() != pState->getStateID())
		{
			this->pushState(pState);
		}
	}
	else {
		this->pushState(pState);
	}
}

void GameStateMachine::popState()
{
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->onExit();
		delete m_gameStates.back();
		m_gameStates.pop_back();
	}
}

GameState * GameStateMachine::getCurrentState()
{
	if (!m_gameStates.empty())
	{
		return m_gameStates.back();
	}
	return nullptr;
}


