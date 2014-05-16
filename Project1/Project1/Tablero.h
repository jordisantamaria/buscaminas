#pragma once

#include "Casella.h"

class CTablero
{
public:
	CTablero(void);
	CTablero(int width, int height, int minas);
	~CTablero(void);

	void draw();
	void moviment();
	void destaparCasella(int x, int y);

private:

	void demanarCoordenadaX(int &x);
	void demanarCoordenadaY(int &y);
	int width;
	int height;
	int minas;
	Casella casella[10][10];

};

