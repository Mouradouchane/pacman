
#ifndef GAME_HPP
#define GAME_HPP

#include "includes.hpp"

namespace game {

	extern std::string title;
	extern uint32_t status;
	extern float version;
	extern bool running;

	bool init();
	void close();
	void run();

}

#endif 