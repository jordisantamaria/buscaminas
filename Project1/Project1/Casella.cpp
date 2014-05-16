#include "Casella.h"


Casella::Casella(void)
{
}

void Casella::setnumMinasProperas(int num)
{
	numMinasProperas = num;
}
int Casella::getNumMinasProperas()
{
	return numMinasProperas;
}

void Casella::setDestapat(bool estat)
{
	destapat = estat;
}
bool Casella::getDestapat()
{
	return destapat;
}

Casella::~Casella(void)
{
}
