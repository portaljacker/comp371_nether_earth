//Comp371_w12 PA1
//Prof. S. Mokhov
//Team 4
//Jordan V. 
//Taras K. 6901204
//Gianni T.
//Sebastien S.
//This is the Tile class header. This class can draw regular tiles or tiles with pits.

#pragma once
class Tile
{
private:
	/*
	//vertices (ex: ttr = top-top-right) for input coordinates version of draw. Not used in this build


	double ttrx;
	double ttry;
	double ttrz;
	double ttlx;
	double ttly;
	double ttlz;
	double tblx;
	double tbly;
	double tblz;
	double tbrx;
	double tbry;
	double tbrz;
	double btrx;
	double btry;
	double btrz;
	double btlx;
	double btly;
	double btlz;
	double bblx;
	double bbly;
	double bblz;
	double bbrx;
	double bbry;
	double bbrz;

	//team number vertices
	//long bar
	double ltrx;
	double ltry;
	double ltrz;

	double ltlx;
	double ltly;
	double ltlz;

	double lblx;
	double lbly;
	double lblz;

	double lbrx;
	double lbry;
	double lbrz;

	//short bar
	double strx;
	double stry;
	double strz;

	double stlx;
	double stly;
	double stlz;

	double sblx;
	double sbly;
	double sblz;

	double sbrx;
	double sbry;
	double sbrz;

	//horizontal bar
	double htrx;
	double htry;
	double htrz;

	double htlx;
	double htly;
	double htlz;

	double hblx;
	double hbly;
	double hblz;

	double hbrx;
	double hbry;
	double hbrz;*/

public:
	void draw();
	void drawHole();
	void drawHoleEdge();
	Tile();
	//Tile(double p1, double p2, double p3, double p4, double p5, double p6, double p7, double p8);
	~Tile(void);
};
