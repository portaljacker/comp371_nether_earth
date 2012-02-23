//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment 2
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the Tile class header. This class can draw regular tiles or tiles with pits.

#pragma once
class Tile
{
public:
	void draw();
	void drawHole();
	void drawHoleEdge();
	Tile();
	//Tile(double p1, double p2, double p3, double p4, double p5, double p6, double p7, double p8);
	~Tile(void);
};
