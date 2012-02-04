#include "Map.h"


Map::Map(void)
{
	for(int i = 0; i < 50; i++)
	{
		for(int j = 0; j < 50; j++)
		{
			grid[i][j] = 't';
		}
	}
}

char Map::getChar(int i, int j)
{
	return grid[i][j];
}


Map::~Map(void)
{
}
