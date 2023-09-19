#include "MyLibrary.h"

#include "SDL2/SDL.h"

namespace MyLibrary
{
	void InitializeLibrary()
	{
		SDL_Init(SDL_INIT_VIDEO);
	}
	void DeinitializeLibrary()
	{
		SDL_Quit();
	}

	void* CreateWindow()
	{
		return SDL_CreateWindow("Marko", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	}
	void DestroyWindow(void* window)
	{
		SDL_DestroyWindow((SDL_Window*)window);
	}
}