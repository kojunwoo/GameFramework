
#pragma once

#include <iostream>
#include <SDL.h>
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"

class Game
{
public:
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
	void quit();

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	SDL_Renderer* getRenderer()const { return m_pRenderer; }

private:
	static Game* s_pInstance;

	SDL_Window * m_pWindow;
	SDL_Renderer*m_pRenderer;

	int m_currentFrame;
	int m_currentFrame2;
	bool m_bRunning;

	std::vector<GameObject*> m_gameObjects;
};

typedef Game TheGame;