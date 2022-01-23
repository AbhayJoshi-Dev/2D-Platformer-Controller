#include"Entity.h"

Entity::Entity(const Vector& pos)
	:position(pos), texture(NULL)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 0;
	currentFrame.h = 0;
}

Vector Entity::GetPosition()
{
	return position;
}

void Entity::SetPosition(Vector pos)
{
	position = pos;
}

void Entity::SetTexture(SDL_Texture* tex)
{
	texture = tex;
	SDL_QueryTexture(texture, NULL, NULL, &currentFrame.w, &currentFrame.h);
}

SDL_Rect Entity::GetCurrentFrame()
{
	return currentFrame;
}

SDL_Texture* Entity::GetTexture()
{
	return texture;
}