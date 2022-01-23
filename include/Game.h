#pragma once

#include"RenderWindow.h"

class Game
{
private:
	RenderWindow window;
	bool gamerunning;
	SDL_Event event;
public:
	Game();
	void Init();
	void GameLoop();
};