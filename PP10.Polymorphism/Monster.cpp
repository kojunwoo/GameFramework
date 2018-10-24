#include "Monster.h"

void Monster::load(int x, int y, int width, int height, std::string textureID)
{
	GameObject::load(x, y, width, height, textureID);
}

void Monster::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
}

void Monster::clean()
{

}
void Monster::update()
{
	GameObject::movingspeed();
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}



void Monster2::load(int x, int y, int width, int height, std::string textureID)
{
	GameObject::load(x, y, width, height, textureID);
}

void Monster2::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
}

void Monster2::clean()
{

}
void Monster2::update()
{
	GameObject::movingspeed();
		
		m_currentFrame = int(((SDL_GetTicks() / 100) % 7));
}


void GameObject::movingspeed()
{
	if (new Monster)
	{
		m_x += 1;
	}

}