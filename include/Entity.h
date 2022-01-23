#pragma once

#include<SDL.h>

#include"Vector.h"

class Entity
{
private:
	Vector position;
	SDL_Texture* texture;
	SDL_Rect currentFrame;
public:
	Entity(const Vector& pos);
	Vector GetPosition();
	void SetPosition(Vector pos);
	void SetTexture(SDL_Texture* tex);
	SDL_Rect GetCurrentFrame();
	SDL_Texture* GetTexture();
};