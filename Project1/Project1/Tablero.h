#pragma once

#include "Casella.h"

class CTablero
{
public:
	CTablero(void);
	CTablero(int width, int height, int minas);
	~CTablero(void);

	void draw();

private:
	int width;
	int height;
	int minas;
	Casella casella[10][10];

};

