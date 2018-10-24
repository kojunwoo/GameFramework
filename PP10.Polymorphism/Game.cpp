#include "Game.h"

bool Game::init(const char*title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{


		m_pWindow = SDL_CreateWindow("PP10.Polymorphism",

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
	TheTextureManager::Instance()->load("assets/animate2-alpha.png", "animate2", m_pRenderer);
	TheTextureManager::Instance()->load("assets/eyemonster.png", "animate3", m_pRenderer);
	
	SDL_SetRenderDrawColor(m_pRenderer, 200, 200, 255, 100);


	m_go = new GameObject();
	m_player = new Player();
	m_enemy = new Enemy();
	m_monster = new Monster();
	m_monster2 = new Monster2();

	m_go->load(100, 100, 43, 110, "animate");
	m_player->load(300, 300, 43, 110, "animate");
	m_enemy->load(0, 0, 43, 110, "animate");
	m_monster->load(200, 200, 71, 46, "animate3");
	m_monster2->load(300, 300, 71, 46, "animate3");


	m_gameObjects.push_back(m_go);
	m_gameObjects.push_back(m_player);
	m_gameObjects.push_back(m_enemy);
	m_gameObjects.push_back(m_monster);
	m_gameObjects.push_back(m_monster2);


	m_bRunning = true;
	return true;
}

void Game::render()
{
	
	SDL_RenderClear(m_pRenderer);
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw(m_pRenderer);
	}
	SDL_RenderPresent(m_pRenderer);
}

void Game::update() {
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
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