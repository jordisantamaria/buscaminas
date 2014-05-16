#include "Tablero.h"

CTablero::CTablero(void)
{
	width = 0;
	height = 0;
	minas = 0;
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			casella[i][j].setDestapat(false);
			casella[i][j].setnumMinasProperas(0);
		}
	}
}
CTablero::CTablero(int width, int height, int minas)
{
	this->width = width;
	this->height = height;
	this->minas = minas;

	for(int i=0; i<width; i++)
	{
		for(int j=0; j<height; j++)
		{
			casella[i][j].setDestapat(false);
			casella[i][j].setnumMinasProperas(0);
		}
	}
}

void CTablero::draw()
{
	int i = 0;
	int j = 0;

	while(i<height)
{
	cout << casella[i][j].getNumMinasProperas();
	j++;
	if(j==width-1)
	{
		j=0;
		i++;
		cout <<endl;
	}
}
}
CTablero::~CTablero(void)
{
}
