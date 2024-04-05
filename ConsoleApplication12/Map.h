#pragma once
#include<iostream>
#include "Player.h"
#define random(a,b) a+rand()% (b+1-a)

using namespace std;
class Map
{
	Player player;
	int heigh;
	int width;
	char** map= nullptr;
	char tiles[3] = { char(176), char(177), char(219) };
public:
	Map(int heigh, int width);
	void draw();
	void generationWater();
	void generation();
};

