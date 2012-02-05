//Comp371_w12 PA1
//Prof. S. Mokhov
//Team 4
//Jordan V. 
//Taras K. 6901204
//Gianni T.
//Sebastien S.
//This is the map class header. It contains an aray that stores map info.

#pragma once
class Map
{
private:
	char grid[50][50][3];

public:
	Map(void); //Default constructor for testing custom configurations.
	~Map(void);
	char getChar(int i, int j); //Checks specific array index.
	char getChar(int i, int j,int k);
};

