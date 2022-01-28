#pragma once

#include"RenderWindow.h"
#include"Utils.h"
#include"Player.h"

class Game
{
private:
	RenderWindow window;
	bool gameRunning;
	SDL_Event event;

	const float timeStep = 0.01f;
	float accumulator = 0.0f;
	float currentTime = utils::HireTimeInSeconds();
	float newTime = 0.0f;
	float frameTime = 0.0f;
	float alpha = 0.0f;
	int startTicks = 0;
	int frameTicks = 0;

	Player player;

	Entity ground;

	bool isKeyHold_D;
	bool isKeyHold_A;

public:
	Game();
	void Init();
	void GameLoop();
};