#pragma once
#include "GameState.h"

class GameStateMachine
{
public:
	void update();
	void render();
	void changeState(GameState* pStete);
	void pushState(GameState* pStete)
	{
		m_gameStates.push_back(pState);
		m_gameStates.back()->onEnter();
	}
	void popState();
private:
	GameState* m_currentState;
	GameState* m_prevState;
};

