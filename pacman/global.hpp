
/*
	here all the references to all global variables
*/

#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include "SDL.h"
#include "SDL_ttf.h"

extern SDL_Window*  window;
extern SDL_Surface* window_surface;

extern TTF_Font* cool_font;
extern TTF_Font* normal_font;

extern int font_size_at_load;
extern const char* cool_font_path;
extern const char* normal_font_path;

#endif 
