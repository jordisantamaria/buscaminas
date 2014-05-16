#include "MenuScreen.h"
#include "Tablero.h"


enum estatsGame{
	MENU,
	GAMEPLAY,
	SALIR
};

void menu(int &estatActual, int &dificultatGame )
{
	int dificultat;


	cout << "Que nivel de dificultad desea?" <<endl;
	cout << "Nivel 1 : mapa 9x9, 10 minas" <<endl;
	cout << "Nivel 2 : mapa 16x16, 40 minas" <<endl;
	cout << "Nivel 3 : mapa 16x30, 99 minas" <<endl;
	cout << "4 : salir" <<endl;

	cin >> dificultat;

	switch(dificultat)
	{
	case 1:
		dificultatGame = 1;
		estatActual = GAMEPLAY;
		cout << "DIFICULTAT 1" <<endl;
		break;
	case 2:
		dificultatGame = 2;
		estatActual = GAMEPLAY;
		cout << "DIFICULTAT 2" <<endl;
		break;
	case 3:
		dificultatGame = 3;
		estatActual = GAMEPLAY;
		cout << "DIFICULTAT 3" <<endl;
		break;
	case 4:
		estatActual = SALIR;		
		break;
	}


	
	if( dificultat<0 && dificultat >4)
	{
		cout << "OPCIO INCORRECTE" <<endl;
		menu(estatActual,dificultatGame );
	}


}
int main()
{
	int state = MENU;

int dificultat = -1;

//CMenuScreen menu;
CTablero tabler;
system("CLS");
menu(state,dificultat );
tabler = CTablero(9,9,10);
do
{

tabler.draw();
tabler.moviment();
}while((state != SALIR));



	system("PAUSE");
}
