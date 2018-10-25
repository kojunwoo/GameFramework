#include "Player.h"
#include "GameObject.h"

Player::Player(const LoaderParams* pParams);
SDLGameObject(pParams)
{
}

Player::Player(const LoaderParams * pParams)
{
}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{
	m_x -= 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
}

void Player::clean()
{

}