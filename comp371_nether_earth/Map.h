#pragma once
class Map
{
private:
	char grid[50][50][3];

public:
	Map(void);
	~Map(void);
	char getChar(int i, int j);
};

