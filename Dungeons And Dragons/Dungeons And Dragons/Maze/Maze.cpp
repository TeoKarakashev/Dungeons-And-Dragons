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

bool Maze::isValidMove(int x, int y)
{
	return grid[x][y] != '#';
}

void Maze::generateMonsters() {
	srand(time(0));
	int count = 0;
	while (count <= currentLevel ) {
		int widthCord = (rand() % (width - 2)) + 1;
		int heightCord = (rand() % (height - 2)) + 1;
		if (grid[heightCord][widthCord] == ' ') {
			grid[heightCord][widthCord] = 'M';
			Pair<int, int> cords;
			cords.set_pair(heightCord, widthCord);
			monstersCoordiantes.add(cords);
			count++;
		}
	}
}

void Maze::generateTreasures() {
	srand(time(0));
	int count = 0;
	while (count <= currentLevel) {
		int widthCord = (rand() % (width - 2)) + 1;
		int heightCord = (rand() % (height - 2)) + 1;
		if (grid[heightCord][widthCord] == ' ') {
			grid[heightCord][widthCord] = 'T';
			Pair<int, int> cords;
			cords.set_pair(heightCord, widthCord);
			treasuresCoordiantes.add(cords);
			count++;
		}
	}
}

Maze::Maze() {
	height = 0;
	width = 0;
	grid = nullptr;
	previousStateOfCurrentHeroPosition = ' ';
	currentLevel = 0;
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
	previousStateOfCurrentHeroPosition = ' ';
	heroCoordinates.set_pair(1, 1);
	grid[height - 2][width - 2] = 'E';

	generateTreasures();
	generateMonsters();
}

bool Maze::isOnTheExit() {
	return previousStateOfCurrentHeroPosition == 'E';
}

void Maze::generateLevel() {
	currentLevel++;
	if (currentLevel == 1) {
		generateMaze(11, 11);
	}
	else if (currentLevel == 2) {
		generateMaze(15, 11);
	}
	else {
		
		if ((width += WIDTH_INCREASE) % 2 == 0) {
			width++;
		};
		if ((height += HEIGHT_INCREASE) % 2 == 0) {
			height++;
		};
		generateMaze(width, height);
	}
}

const Pair<int, int> Maze::getHeroCords() const {

	return heroCoordinates;
}

bool Maze::moveHero(int x, int y) {
	if (isValidMove(x, y)) {
		grid[heroCoordinates.c_first()][heroCoordinates.c_second()] = previousStateOfCurrentHeroPosition;
		heroCoordinates.set_pair(x, y);
		previousStateOfCurrentHeroPosition = grid[x][y];
		grid[x][y] = 'H';
		return true;
	}
	return false;
}

void Maze::visualizeCurrentState() const {
	visualizeMaze();
	switch (previousStateOfCurrentHeroPosition) {
	case 'E':
		std::cout << "Congratulations! You made your way to the end of the current level! Do you want to procced? Press 1";
		break;
	case 'M':
		std::cout << "Ooh, a monster";
		break;
	case 'T':
		std::cout << "Ooh, a treasure";
		break;
	default:
		break;
	}
}

void Maze::visualizeMaze() const {
	system("cls");
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			std::cout << grid[i][j];
		}
		std::cout << std::endl;
	}
}
