#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

#include"Game.h"

Game::Game()
	:window(), gamerunning(true)
{

	Init();
	GameLoop();
}

void Game::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "Error: Failed to initialize SDL. " << SDL_GetError() << std::endl;

	if (!IMG_Init(IMG_INIT_PNG))
		std::cout << "Error: Failed to initialize SDL_image. " << IMG_GetError() << std::endl;

	window.CreateWindow("2D Platformer Controller", 800, 600);
}

void Game::GameLoop()
{
	while (gamerunning)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gamerunning = false;
		}
		window.Clear();

		window.Display();
	}

	window.CleanUp();
}