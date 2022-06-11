#include "Engine.h"

void Engine::run() {
	Maze ma;
	ma.generateMaze(23, 13);
	ma.visualizeMaze();

	while (!_kbhit()){
		int ch = _getch();
		if (ch == 'a') {
			std::cout << "yes";
		}
	}

}
