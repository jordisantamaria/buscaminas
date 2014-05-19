#pragma once

#include "Casella.h"

enum estatsGame{
	MENU,
	GAMEPLAY,
	SALIR
};

const int MINA = 9;
const int CASELLA_SENSE_DESTAPAR = 178;
class CTablero
{
public:
	CTablero(void);
	CTablero(int width, int height, int minas);
	~CTablero(void);

	void draw();
	void moviment(int &state);
	

private:

	int numAleatori (int maxNum);
	void demanarCoordenadaX(int &x);
	void demanarCoordenadaY(int &y);
	void destaparCasella(int x, int y, int &estat);
	int setNumMinas(int x, int y);
	void inicialitzarMinas();
	void inicialitzarnumMinasAdjacents();
	int min(int num, int min);
	int max(int num, int max);
	

	int width;
	int height;
	int minas;
	Casella casella[10][10];

};

