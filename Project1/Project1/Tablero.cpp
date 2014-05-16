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
	char c = 178;
	int i = 0;
	int j = 0;

	while(i<height)
{
	if(casella[i][j].getDestapat() == false)
	{
	cout << c;//casella[i][j].getNumMinasProperas();
	}else
	{
		cout <<casella[i][j].getNumMinasProperas();
	}
	j++;
	if(j==width-1)
	{
		j=0;
		i++;
		cout <<endl;
	}
}
}

void CTablero::moviment()
{
	int x, y;
	demanarCoordenadaX(x);
	demanarCoordenadaY(y);
	destaparCasella(x,y);
}

void CTablero::destaparCasella(int x, int y)
{
	casella[x-1][y-1].setDestapat(true);
	cout << "La casella" <<x << y << "destapat = " << casella[x][y].getDestapat() <<endl;
}
void CTablero::demanarCoordenadaX(int &x)
{
	cout << "Indica la coordenada X" <<endl;
	cin >>x;
	if(x < 0 || x>=width)
	{
		cout << "Coordenada x Incorrecte" <<endl;
		demanarCoordenadaX(x);
	}
}
void CTablero::demanarCoordenadaY(int &y)
{
	cout << "Indica la coordenada Y" <<endl;
	cin >>y;
	if(y < 0 || y>=height)
	{
		cout << "Coordenada Y Incorrecte" <<endl;
		demanarCoordenadaY(y);
	}
}
CTablero::~CTablero(void)
{
}
