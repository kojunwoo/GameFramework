
#pragma once

#include <iostream>
#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

class Game
{
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }



private:

	Game();

	static Game* s_pInstance;

	typedef Game TheGame;

	Game* Game::s_pInstance = 0;
	SDL_Renderer*getRenderer()const { return m_pRenderer; }


	SDL_Window * m_pWindow;
	SDL_Renderer*m_pRenderer;

	int m_currentFrame;
	int m_currentFrame2;
	bool m_bRunning;

	std::vector<GameObject*> m_gameObjects;

	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;
	GameObject* m_monster;
	GameObject* m_monster2;

};