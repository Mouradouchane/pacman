
#include "includes.hpp"

int main(int argv, char** args){

	if (game::init() != INIT_FAIL) return EXIT_FAILURE;

	game::run();

	game::close();
	return EXIT_SUCCESS;
}

