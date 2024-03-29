
#ifndef CONFIG_CPP
#define CONFIG_CPP

#include "config.hpp"

namespace config {

	int window_x = 0;
	int window_y = 0;

	int width  = 800;
	int height = 600;

	bool full_screen = true;

	uint32_t max_fps = 30;
	float frame_time = 1000 / max_fps;

}

#endif 