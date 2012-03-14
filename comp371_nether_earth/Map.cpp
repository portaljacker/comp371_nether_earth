//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment 3
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
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
	grid[1][1][0] = 's';
	grid[2][1][0] = 's';
	grid[3][1][0] = 's';
	grid[4][1][0] = 's';
	grid[5][1][0] = 's';
	grid[6][1][0] = 's';
	grid[7][1][0] = 's';

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

	//Buildings
	grid[2][4][1] = '1';
	grid[4][4][1] = '2';
	grid[6][4][1] = '3';
	grid[8][4][1] = '4';
	
	//HQ
	drawHQ(7,17);
	/*	shouldn't be necessary due to dedicated function
	grid[6][15][1] = '2';
	grid[8][15][1] = '2';
	grid[5][16][1] = '2';
	grid[6][16][1] = '1';
	grid[7][16][1] = '2';
	grid[8][16][1] = '1';
	grid[9][16][1] = '2';
	grid[5][17][1] = '2';
	grid[6][17][1] = '1';
	grid[7][17][1] = '5';
	grid[8][17][1] = '1';
	grid[9][17][1] = '2';
	grid[6][18][1] = '1';
	grid[7][18][1] = '1';
	grid[8][18][1] = '1';
	grid[6][19][1] = '1';
	grid[8][19][1] = '1';*/

	//Controller
	grid[10][10][2] = '1';

	//Delimiters
	for (int i = 0; i < 50; i++)
		grid[i][0][1] = '6';
	for (int i = 0; i < 50; i++)
		grid[i][49][1] = '6';
	for (int j = 1; j < 49; j++)
		grid[0][j][1] = '6';
	for (int j = 1; j < 49; j++)
		grid[49][j][1] = '6';

	// Four courner light posts
	grid[0][0][1] = '%';
	grid[0][49][1] = '^';
	grid[49][0][1] = '&';
	grid[49][49][1] = '*';

	// Robot tests (with buildings for comparison)
	grid[38][3][1] = '7';
	grid[38][7][1] = 'b';
	grid[42][3][1] = '7';
	grid[42][7][1] = 'g';
	grid[46][3][1] = '7';
	grid[46][7][1] = 't';
	grid[35][3][1] = '7';
	grid[35][7][1] = 'e';
	grid[32][3][1] = '7';
	grid[32][7][1] = 'c';
	grid[32][10][1] = 'p';
	grid[35][10][1] = 'n';
	grid[39][9][1] = 'm';

	grid[33][20][1] = 'r';
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

void Map::drawHQ(int i, int j)
{
	grid[i-1][j-2][1] = '2';
	grid[i+1][j-2][1] = '2';

	grid[i-2][j-1][1] = '2';
	grid[i-1][j-1][1] = '2';
	grid[i][j-1][1] = '2';
	grid[i+1][j-1][1] = '2';
	grid[i+2][j-1][1] = '2';

	grid[i-2][j][1] = '2';
	grid[i-1][j][1] = '1';
	grid[i][j][1] = '@';	// center/drawing point
	grid[i+1][j][1] = '1';
	grid[i+2][j][1] = '2';

	grid[i-1][j+1][1] = '1';
	grid[i][j+1][1] = '1';
	grid[i+1][j+1][1] = '1';

	grid[i-1][j+2][1] = '1';
	grid[i+1][j+2][1] = '1';
}

void Map::drawF(int i, int j)
{
	grid[i-1][j][1] = '0';
	grid[i][j][1] = '$';	// center/drawing point
	grid[i+1][j][1] = '0';

	grid[i-1][j+1][1] = '0';
	grid[i+1][j+1][1] = '0';
}

Map::~Map(void)
{
}
