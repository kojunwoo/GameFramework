#pragma once
#include <string>
#include <vector>
#include "GameObject.h"

class GameState
{
protected:
	std::vector<GameObject*> m_gameObject;
public:
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void onEnter() = 0;
	virtual void onExit() = 0;
	virtual std::string getStateID() const = 0;
};