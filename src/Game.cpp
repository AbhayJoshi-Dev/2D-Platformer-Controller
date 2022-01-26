#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

#include"Game.h"

Game::Game()
	:window(), gameRunning(true), player(Vector(400.f, 300.f)), ground(Vector(0.f, 575.f))
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

	player.SetTexture(window.LoadTexture("res/gfx/Player.png"));
	ground.SetTexture(window.LoadTexture("res/gfx/Ground.png"));
}

void Game::GameLoop()
{
	while (gameRunning)
	{
		utils::FPS();

		startTicks = SDL_GetTicks();

		newTime = utils::HireTimeInSeconds();
		frameTime = newTime - currentTime;
		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= timeStep)
		{
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_QUIT:
					gameRunning = false;

				case SDL_KEYDOWN:
					if (event.key.keysym.sym == SDLK_SPACE)
						player.Jump();
				}
			}

			accumulator -= timeStep;
		}

		alpha = accumulator / timeStep;

		window.Clear();

		if (utils::IsCollision(player, ground))
		{
			player.Collision(ground);
		}

		window.Render(player);
		window.Render(ground);
		player.Update();

		window.Display();

		frameTicks = SDL_GetTicks() - startTicks;
		if (frameTicks < 1000 / window.GetRefreshRate())
			SDL_Delay(1000 / window.GetRefreshRate() - frameTicks);
	}

	window.CleanUp();
}