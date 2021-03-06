#pragma once

#include <iostream>
#include <SDL.h>
#include "TextureManager.h"

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
	//SDL_Texture * m_pTexture;
	//SDL_Rect m_sourceRectangle;
	//SDL_Rect m_destinationRectangle;
	SDL_Window * m_pWindow;
	SDL_Renderer*m_pRenderer;
	TextureManager m_textureManager;
	int m_currentFrame;
	bool m_bRunning;
};