#include "Maze.h"

void Maze::free() {
	for (int i = 0; i < height; i++) {
		delete grid[i];
	}
	delete[] grid;
}

void Maze::copyFrom(const Maze& other) {
	height = other.height;
	width = other.width;
	grid = new char* [height];
	for (int i = 0; i < height; i++) {
		grid[i] = new char[width];
	}
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			grid[x][y] = other.grid[x][y];
		}
	}
}

void Maze::generateMonsters() {
	srand(time(0));
	int count = 0;
	while (count < 2) {
		int widthCord = (rand() % (width-2)) + 1;
		int heightCord = (rand() % (height-2)) + 1;
		if (grid[heightCord][widthCord] == ' ') {
			grid[heightCord][widthCord] = 'M';
			Pair<int, int> cords;
			cords.make_pair(heightCord, widthCord);
			monstersCoordiantes.add(cords);
			count++;
		}
	}
}

void Maze::generateTreasures() {
	srand(time(0));
	int count = 0;
	while (count < 2) {
		int widthCord = (rand() % (width - 2)) + 1;
		int heightCord = (rand() % (height - 2)) + 1;
		if (grid[heightCord][widthCord] == ' ') {
			grid[heightCord][widthCord] = 'T';
			Pair<int, int> cords;
			cords.make_pair(heightCord, widthCord);
			treasuresCoordiantes.add(cords);
			count++;
		}
	}
}

Maze::Maze() {
	height = 0;
	width = 0;
	grid = nullptr;
}

Maze::Maze(const Maze& other) {
	copyFrom(other);
}

Maze& Maze::operator=(const Maze& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Maze::~Maze() {
	free();
}

void Maze::generateMaze(unsigned width, unsigned height) {
	this->width = width;
	this->height = height;
	MazeGenerator generator;
	grid = generator.generateMaze(width, height);
	grid[1][1] = 'H';
	grid[height - 2][width - 2] = 'E';

	generateMonsters();
	generateTreasures();
}

void Maze::visualizeMaze() const {
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			std::cout << grid[i][j];
		}
		std::cout << std::endl;
	}
}
