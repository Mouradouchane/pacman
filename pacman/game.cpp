
#ifndef GAME_CPP
#define GAME_CPP

#include "game.hpp"

namespace game {

	// game variables
	std::string title = "pacman";
	uint32_t status = MENU;
	float version = 1.0;
	
	bool running = true;

}

bool game::init() {

	if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
		MessageBeep(MB_ICONERROR);
		MessageBoxA(NULL, "failed to init sdl", game::title.c_str(), MB_OKCANCEL | MB_ICONERROR);
		return INIT_FAIL;
	}

	window = SDL_CreateWindow(
		game::title.c_str(), config::window_x, config::window_y,
		config::width, config::height,
		(config::full_screen ? SDL_WINDOW_FULLSCREEN : 0) | SDL_WINDOW_OPENGL
	);

	if (window == nullptr) {
		MessageBeep(MB_ICONERROR);
		MessageBoxA(NULL, "failed to create window", game::title.c_str(), MB_OKCANCEL | MB_ICONERROR);
		return INIT_FAIL;
	}

	window_surface = SDL_GetWindowSurface(window);

	if (window_surface == nullptr) {
		MessageBeep(MB_ICONERROR);
		MessageBoxA(NULL, "failed to get window surface", game::title.c_str(), MB_OKCANCEL | MB_ICONERROR);
		return INIT_FAIL;
	}

	if (TTF_Init() != 0) {
		MessageBeep(MB_ICONERROR);
		MessageBoxA(NULL, "failed to init sdl_ttf", game::title.c_str(), MB_OKCANCEL | MB_ICONERROR);
		return INIT_FAIL;
	}

	cool_font   = TTF_OpenFont(cool_font_path, font_size_at_load);
	normal_font = TTF_OpenFont(normal_font_path, font_size_at_load);

	if (cool_font == nullptr || normal_font == nullptr) {
		MessageBeep(MB_ICONERROR);
		MessageBoxA(NULL, "failed to load fonts", game::title.c_str(), MB_OKCANCEL | MB_ICONERROR);
		return INIT_FAIL;
	}

	return INIT_SUCCESS;
}

// free allocated resources , save player progress , ...
void game::close() {

	SDL_FreeSurface(window_surface);
	window_surface = nullptr;

	SDL_DestroyWindow(window);
	window = nullptr;

	TTF_CloseFont(cool_font);
	cool_font = nullptr;

	TTF_CloseFont(normal_font);
	normal_font = nullptr;

	TTF_Quit();
	SDL_Quit();
}

// game main loop 
void game::run() {

	SDL_Event event = {0};

	while (game::running) {

		// handle inputs
		while ( SDL_PollEvent(&event) ) {

			if (event.type == SDL_QUIT) {
				game::running = false;
			}

		} 

		// handle physics

		// render

		// fps contol

	}

}

#endif