#pragma once

#include<SDL.h>
#include<SDL_image.h>

class RenderWindow
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
public:
	RenderWindow();
	void CreateWindow(const char* title, int w, int h);
	SDL_Texture* LoadTexture(const char* filePath);
	void Clear();
	void Display();
	void CleanUp();
};