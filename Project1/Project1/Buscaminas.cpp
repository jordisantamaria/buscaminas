#include "MenuScreen.h"
#include "Tablero.h"
#include <iostream>




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
		;
		cout << "DIFICULTAT 1" <<endl;
		break;
	case 2:
		dificultatGame = 2;
		
		cout << "DIFICULTAT 2" <<endl;
		break;
	case 3:
		dificultatGame = 3;
		
		cout << "DIFICULTAT 3" <<endl;
		break;
	case 4:
		estatActual = SALIR;		
		break;
	default:
		dificultatGame = -1;
		cout << "Dificultat Incorrecte" <<endl;
		menu(estatActual,dificultatGame );
		break;
	}



}
int main()
{
	int state = MENU;
int dificultat = -1;


CTablero tabler;
menu(state,dificultat );

system("CLS");
tabler = CTablero(9,9,10);

while(state != SALIR)
{

tabler.draw();
tabler.moviment(state);
}



	system("PAUSE");
}
