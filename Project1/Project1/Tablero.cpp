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
	inicialitzarMinas();
}

void CTablero::inicialitzarMinas()
{
	int randomX, randomY;
	int numMinas = 0;

	while(numMinas<minas)
	{
		randomX = numAleatori(width-1);
		randomY = numAleatori(height-1);
		if(casella[randomX][randomY].getNumMinasProperas() == 0)
		{
		casella[randomX][randomY].setnumMinasProperas(MINA);
		numMinas++;
		}
	}
}

void CTablero::draw()
{
	char c = CASELLA_SENSE_DESTAPAR;
	int i = 0;
	int j = 0;

	while(j<height)
	{
		//Si encara no s'ha destapat, dibuixa el caracter de CASELLA_SENSE_DESTAPAR
		if(casella[i][j].getDestapat() == false)
		{
			cout << c;
		//si está destapada, dibuixa el numero de minas adjacents.
		}else
		{
			cout <<casella[i][j].getNumMinasProperas();
		}
		i++;
		//si ha arribat a la ultima columna, fes un salt de linia i continua per la seguent fila.
		if(i==width-1)
		{
			i=0;
			j++;
			cout <<endl;
		}
	}
}

void CTablero::moviment(int &state)
{
	int x, y;
	demanarCoordenadaX(x);
	demanarCoordenadaY(y);
	state = destaparCasella(x,y);
}
void CTablero::setNumMinasProperas(int x, int y)
{

	int numMinasAdjacents = 0;
	int i = x-1;
	int j = y-1;
	while(i<=x+1)
	{
		
			if(casella[i][j].getNumMinasProperas() == MINA)
			{
				numMinasAdjacents++;
			}
			j++;
		if(j==y+1)
		{
			i++;
			j=y-1;
		}
		
	}
	casella[x][y].setnumMinasProperas(numMinasAdjacents);
	cout << "El numero de minas properas es" << numMinasAdjacents<<endl;
}

int CTablero::min(int num, int min)
{
	if(num < min)
	{
	return min;
	}else{
		return num;
	}
}
int CTablero::max(int num, int max)
{
	if(num > max)
	{
	return max;
	}else{
		return num;
	}
}


int CTablero::destaparCasella(int x, int y)
{
	int posX = x-1;
	int posY = y-1;

	// SI HI HA MINA EN AQUELLA POSICIO, MOSTRA EL TAULER DE NOU I ACABA LA PARTIDA
	if(casella[posX][posY].getNumMinasProperas() == MINA)
	{
		casella[posX][posY].setDestapat(true);
		draw();
		cout << "Aquesta casella era una bomba, GAME OVER" <<endl;
		return SALIR;
	}

	// SINO, DESTAPA AQUELLA CASELLA I LI ASIGNA EL NUMERO CORRESPONENT, SI AQUELLA CASELLA NO TE MINAS PROPERAS, CRIDA RECURSIVITAT A LES ADJACENTS.
	else
	{
	setNumMinasProperas(posX, posY);

	casella[posX][posY].setDestapat(true);
	cout << "La casella" <<x << y << "destapat = " << casella[x][y].getDestapat() <<endl;

	// RECURSIVITAT PER A LES CASELLES VEINES

	if(casella[posX][posY].getNumMinasProperas() ==0)
	{
		for(int i = min(posX-1, 0); i <= max(posX+1, width-1); i++)
		{
			for(int j = min(posY-1, 0); j <= max(posY+1, height-1); j++)
			{
				if(casella[posX][posY].getDestapat() == false)
				{
					destaparCasella(i, j);
				}
			}
		}
	}


	}
	return GAMEPLAY;
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

int CTablero::numAleatori (int maxNum)
{
	
//	std::srand(std::time(0));//PARA QUE LA SEGUENCIA DE NUMEROS ALEATORIOS NO SEA SIEMPRE LA MISMA
	return (rand() % maxNum);
}
CTablero::~CTablero(void)
{
}
