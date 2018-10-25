#include "Enemy.h"
#include "GameObject.h"

Enemy::Enemy(const LoaderParams* pParams);
SDLGameObject(pParams)
{
}

Enemy::Enemy(const LoaderParams * pParams)
{
}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	m_y += 1;
	m_x += 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
}

void Player::clean()
{

}