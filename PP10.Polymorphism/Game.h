
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
	//GameObject m_go;
	//Player m_player;



private:
	//SDL_Texture * m_pTexture;
	//SDL_Rect m_sourceRectangle;
	//SDL_Rect m_destinationRectangle;
	SDL_Window * m_pWindow;
	SDL_Renderer*m_pRenderer;
	//TextureManager m_textureManager;
	int m_currentFrame;
	int m_currentFrame2;
	bool m_bRunning;

	std::vector<GameObject*> m_gameObjects;

	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;

};