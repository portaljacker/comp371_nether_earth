//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment Final Build
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the light post constructing header file

#pragma once

// Header file pertaining to the construction of a light post
// object 

class lightPostConstruct
{

public:

	// Constructor
	lightPostConstruct(void);

	// Destructor
	~lightPostConstruct(void);

	// Draw function for the light post
	void draw();

	// Light defining initializing function
	void createLight();
};

