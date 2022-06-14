#include "Engine.h"



void Engine::run() {
	Maze maze;
	maze.generateLevel();
	maze.visualizeCurrentState();

	while (!_kbhit()) {
		Pair<int, int> heroCords = maze.getHeroCords();
		int ch = _getch();
		switch (ch)
		{
		case 'w':
			if (maze.moveHero(heroCords.c_first() - 1, heroCords.c_second() )) {
				maze.visualizeCurrentState();
			}
			break;
		case 'a':
			if (maze.moveHero(heroCords.c_first(), heroCords.c_second() - 1)) {
				maze.visualizeCurrentState();
			}
			break;
		case 's':
			if (maze.moveHero(heroCords.c_first() + 1, heroCords.c_second())) {
				maze.visualizeCurrentState();
			}
			break;
		case 'd':
			if (maze.moveHero(heroCords.c_first(), heroCords.c_second() + 1)) {
				maze.visualizeCurrentState();
			}
			break;
		case 'q':
			if (maze.isOnTheExit()) {
				maze.generateLevel();
				maze.visualizeCurrentState();
			}
			break;
		default:
			break;
		}

	}

}
