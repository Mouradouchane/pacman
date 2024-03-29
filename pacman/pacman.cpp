
#include "includes.hpp"

int main(int argv, char** args){

	if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
		MessageBoxA(NULL, "failed to init sdl", game::title.c_str() , MB_OKCANCEL);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

