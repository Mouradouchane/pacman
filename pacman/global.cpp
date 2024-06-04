
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

std::string root_path = "";
const char* cool_font_path   = "C:\\Users\\dev\\Desktop\\cpp\\pacman\\pacman_project\\build\\x86\\fonts\\pacfont_cool.ttf";
const char* normal_font_path = "C:\\Users\\dev\\Desktop\\cpp\\pacman\\pacman_project\\build\\x86\\fonts\\pacfont_normal.ttf";

void get_root_path() {

	const char temp[1024] = {};

	GetModuleFileNameA(NULL, (LPSTR)temp, 1024);

	std::string::size_type pos = std::string(temp).find_last_of("\\/");
	root_path = std::string(temp).substr(0, pos);

}


#endif
