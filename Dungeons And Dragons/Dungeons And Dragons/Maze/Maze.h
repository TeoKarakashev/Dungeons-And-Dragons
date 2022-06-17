#pragma once
#include "MazeGenerator/MazeGenerator.h"
#include "../Entities/Hero/HeroContainer/HeroContainer.h"
#include "../Helpers/Pair/Pair.hpp"
#include "../Helpers/ArrayList/ArrayList.hpp"
#define WIDTH_INCREASE 5
#define HEIGHT_INCREASE 3
class Maze {

	unsigned height;
	unsigned width;
	unsigned currentLevel;
	char** grid;
	char previousStateOfCurrentHeroPosition;

	HeroContainer heroEntity;
	Pair<int, int> heroCoordinates;
	ArrayList<Pair<int, int>> treasuresCoordiantes;
	ArrayList<Pair<int, int>> monstersCoordiantes;

	void free();
	void copyFrom(const Maze& other);
	bool isValidMove(int x, int y);
	void generateMonsters();
	void generateTreasures();
	void visualizeMaze() const;
	void generateMaze(unsigned height, unsigned width);
public:
	Maze();
	Maze(const Maze& other);
	Maze& operator=(const Maze& other);
	~Maze();

	void setHero(const Hero& hero);
	bool isOnTheExit() const;
	void generateLevel();
	const Pair<int, int> getHeroCords() const;
	bool moveHero(int x, int y);
	void visualizeCurrentState() const;
};