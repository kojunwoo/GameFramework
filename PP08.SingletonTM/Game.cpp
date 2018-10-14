#include "Game.h"

bool Game::init(const char*title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{


		m_pWindow = SDL_CreateWindow("PP08.SingletonTM",

			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			640, 480, SDL_WINDOW_SHOWN);

		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
	}
	else {

		m_bRunning = false;
		return false;
	}

	TheTextureManager::Instance()->load("assets/dog sprite.png", "animate", m_pRenderer);
	TheTextureManager::Instance()->load("assets/New Piskel.png", "background", m_pRenderer);

	SDL_SetRenderDrawColor(m_pRenderer, 200, 200, 255, 100);


	m_bRunning = true;
	return true;
}

void Game::render()
{


	SDL_RenderClear(m_pRenderer);
	
	

	TheTextureManager::Instance()->draw("background", 0, 0, 640, 480, m_pRenderer);


	TheTextureManager::Instance()->drawFrame("animate", 300, 290, 43, 110, 1,
		m_currentFrame, m_pRenderer);
	
	

	SDL_RenderPresent(m_pRenderer);
}

void Game::update() {
	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
	m_currentFrame2 = int(((SDL_GetTicks() / 70) % 6));
}

void Game::clean()
{
	std::cout << "cleaning game\n";

	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}