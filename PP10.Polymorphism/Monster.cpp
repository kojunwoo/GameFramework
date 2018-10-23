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
	m_x += 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}