
/*
	here all the global variables
*/

#ifndef GLOBAL_CPP
#define GLOBAL_CPP

#include "global.hpp"

SDL_Window*  window = nullptr;
SDL_Surface* window_surface = nullptr;

TTF_Font* cool_font   = nullptr;
TTF_Font* normal_font = nullptr;

int font_size_at_load = 72;
const char* cool_font_path   = "fonts\pacfont_cool.ttf\0";
const char* normal_font_path = "fonts\pacfont_normal.ttf\0";

#endif
