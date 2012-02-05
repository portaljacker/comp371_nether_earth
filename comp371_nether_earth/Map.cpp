#include "Map.h"


Map::Map(void)
{
	for(int i = 0; i < 50; i++)
	{
		for(int j = 0; j < 50; j++)
		{
			grid[i][j][0] = 't';
		}
	}
}

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
