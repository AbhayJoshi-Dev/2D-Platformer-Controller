#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

#include"Game.h"

Game::Game()
	:window(), gameRunning(true), player(Vector(400.f, 300.f)), ground(Vector(0.f, 575.f)), isKeyHold_D(false), 
	platform(Vector(450.f, 400.f)), platform2(Vector(250.f, 420.f))
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
	platform.SetTexture(window.LoadTexture("res/gfx/Platform.png"));
	platform2.SetTexture(window.LoadTexture("res/gfx/Platform2.png"));
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
					break;

				case SDL_KEYDOWN:
					if (player.isGround && event.key.keysym.sym == SDLK_SPACE)
					{
						player.Jump();
					}

					if (event.key.keysym.sym == SDLK_d)
					{
						isKeyHold_D = true;
					}

					if (event.key.keysym.sym == SDLK_a)
						isKeyHold_A = true;

					break;

				case SDL_KEYUP:
					if (event.key.keysym.sym == SDLK_d)
						isKeyHold_D = false;
					if (event.key.keysym.sym == SDLK_a)
						isKeyHold_A = false;

					break;
				}
			}

			accumulator -= timeStep;
		}

		alpha = accumulator / timeStep;

		window.Clear();


		if (isKeyHold_D)
			player.Move(1);
		else if (isKeyHold_A)
			player.Move(-1);
		else
			player.deaccelerate = true;

		if (utils::IsCollision(player, ground))
		{
			player.Collision(ground);
		}
		else
		{
			player.isGround = false;
		}

		if (utils::IsCollision(player, platform))
		{
			player.Collide(platform);
		}

		if (utils::IsCollision(player, platform2))
		{
			player.Collide(platform2);
		}

		window.Render(player);
		window.Render(ground);
		window.Render(platform);
		window.Render(platform2);
		player.Update();

		window.Display();

		frameTicks = SDL_GetTicks() - startTicks;
		if (frameTicks < 1000 / window.GetRefreshRate())
			SDL_Delay(1000 / window.GetRefreshRate() - frameTicks);
	}

	window.CleanUp();
}