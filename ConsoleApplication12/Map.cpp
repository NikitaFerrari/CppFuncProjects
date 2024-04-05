#include "Map.h"
Map::Map(int heigh, int width):
	player('@',0,0)
{
	this->heigh = heigh;
	this->width = width;
	map = new char* [heigh];
	for (int i = 0; i < heigh; i++) {
		map[i] = new char[width];
	}
}

void Map::draw()
{
	for (int i = 0; i < heigh; i++) {
		for (int j = 0; j < width; j++) {
			cout <<map[i][j];
		}
		cout << endl;
	}

}

void Map::generationWater()
{
	//up
	int k = random(2, 5);
	for (int j = 0; j < width; j++) {
		for (int i = 0; i < k; i++) {
			map[i][j] = tiles[0];
		}
		int flag = random(0, 1);
		if (map[k][j - 1] != tiles[0]) {
			if (flag) {
				if (k < 5)k++;
			}
			else {
				if (k > 2)k--;
			}
		}
	}


	//left
	k = random(2, 5);
	for (int i = 0; i < heigh; i++) {
		for (int j = 0; j < k; j++) {
			map[i][j] = tiles[0];
		}
		int flag = random(0, 1);
		if (map[k][i - 1] != tiles[0]) {
			if (flag) {
				if (k < 7)k++;
			}
			else {
				if (k > 2)k--;
			}
		}
	}

	//down
	k = random(2, 5);
	for (int j = 0; j < width; j++) {
		for (int i= heigh-1;i > heigh-1-k; i--) {
			map[i][j] = tiles[0];
		}
		int flag = random(0, 1);
		if (map[k][j - 1] != tiles[0]) {
			if (flag) {
				if (k < 7)k++;
			}
			else {
				if (k > 2)k--;
			}
		}
	}

	//right
	k = random(2, 5);
	for (int j = 0; j < heigh; j++) {
		for (int i= width - 1; i > width - 1 - k; i--) {
			map[j][i] = tiles[0];
		}
		int flag = random(0, 1);
		if (map[k][j - 1] != tiles[0]) {
			if (flag) {
				if (k < 7)k++;
			}
			else {
				if (k > 2)k--;
			}
		}
	}
}

void Map::generation()
{

	for (int i = 0; i < heigh; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = tiles[1];
		}
	}
	generationWater();
	

		




	
}
