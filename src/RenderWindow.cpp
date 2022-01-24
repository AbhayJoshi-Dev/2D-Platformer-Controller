#include<iostream>

#include"RenderWindow.h"

RenderWindow::RenderWindow()
	:window(NULL), renderer(NULL)
{

}

void RenderWindow::CreateWindow(const char* title, int w, int h)
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);

	if (window == NULL)
		std::cout << "Error: SDL window not created. " << SDL_GetError() << std::endl;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL)
		std::cout << "Error: Renderer not created. " << SDL_GetError() << std::endl;
}

SDL_Texture* RenderWindow::LoadTexture(const char* filePath)
{
	SDL_Texture* tex = NULL;

	tex = IMG_LoadTexture(renderer, filePath);

	if (tex == NULL)
		std::cout << "Error: Texture failed to laod. " << IMG_GetError() << std::endl;

	return tex;
}

void RenderWindow::Render(Entity& entity)
{
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = entity.GetCurrentFrame().w;
	src.h = entity.GetCurrentFrame().h;

	SDL_Rect dst;
	dst.x = (int)entity.GetPosition().GetX();
	dst.y = (int)entity.GetPosition().GetY();
	dst.w = src.w;
	dst.h = src.h;

	SDL_RenderCopy(renderer, entity.GetTexture(), &src, &dst);
}

void RenderWindow::Clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::Display()
{
	SDL_RenderPresent(renderer);
}

void RenderWindow::CleanUp()
{
	SDL_DestroyWindow(window);
}

int RenderWindow::GetRefreshRate()
{
	int displayIndex = SDL_GetWindowDisplayIndex(window);
	SDL_DisplayMode mode;
	SDL_GetDisplayMode(displayIndex, 0, &mode);
	return mode.refresh_rate;
}