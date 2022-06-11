#pragma once
#include "MazeGenerator/MazeGenerator.h"
#include "../Helpers/Pair/Pair.hpp"
#include "../Helpers/ArrayList/ArrayList.hpp"
class Maze {

	unsigned height;
	unsigned width;
	char** grid;


	Pair<int, int> heroCoordinates;
	ArrayList<Pair<int, int>> treasuresCoordiantes;
	ArrayList<Pair<int, int>> monstersCoordiantes;

	void free();
	void copyFrom(const Maze& other);

	void generateMonsters();
	void generateTreasures();

public:
	Maze();
	Maze(const Maze& other);
	Maze& operator=(const Maze& other);
	~Maze();

	void generateMaze(unsigned height, unsigned width);


	void visualizeMaze() const;
};