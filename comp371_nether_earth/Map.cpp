//Comp371_w12 PA1
//Prof. S. Mokhov
//Team 4
//Jordan V. 
//Taras K. 6901204
//Gianni T.
//Sebastien S.
//This is the map implimentation file.

#include "Map.h"


Map::Map(void) //Various tiles and objects are preset here for testing.
{
	for(int i = 0; i < 50; i++)
	{
		for(int j = 0; j < 50; j++)
		{
			grid[i][j][0] = 't';
		}
	}

	//Some rubble
	grid[0][0][0] = 's';
	grid[1][0][0] = 's';
	grid[2][0][0] = 's';
	grid[3][0][0] = 's';
	grid[4][0][0] = 's';
	grid[5][0][0] = 's';
	grid[6][0][0] = 's';
	grid[7][0][0] = 's';

	grid[20][0][0] = 'm';
	grid[20][1][0] = 'm';
	grid[20][2][0] = 'm';
	grid[20][3][0] = 'm';
	grid[20][4][0] = 'm';
	grid[20][5][0] = 'm';
	grid[20][6][0] = 'm';
	grid[20][7][0] = 'm';

	grid[15][5][0] = 'l';
	grid[15][6][0] = 'l';
	grid[15][7][0] = 'l';
	grid[16][8][0] = 'l';
	grid[16][9][0] = 'l';
	grid[17][9][0] = 'l';
	grid[18][9][0] = 'l';
	grid[18][9][0] = 'l';

	//Horizontal pit
	grid[6][10][0] = 'w';
	grid[7][10][0] = 'h';
	grid[8][10][0] = 'h';
	grid[9][10][0] = 'e';

	//Vertical pit
	grid[30][6][0] = 'n';
	grid[30][7][0] = 'v';
	grid[30][8][0] = 'v';
	grid[30][9][0] = 'v';
	grid[30][10][0] = 'v';
	grid[30][11][0] = 'v';
	grid[30][12][0] = 'd';

}

//Methods to read contents of a particular index. in array.
char Map::getChar(int i, int j)
{
	return grid[i][j][0];
}

char Map::getChar(int i, int j, int k)
{
	return grid[i][j][k];
}

Map::~Map(void)
{
}
