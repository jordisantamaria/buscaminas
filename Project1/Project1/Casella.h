#pragma once

#include <iostream>

using namespace std;
class Casella
{
public:
	Casella(void);
	~Casella(void);

	void setnumMinasProperas(int num);
	int getNumMinasProperas();

	void setDestapat(bool estat);
	bool getDestapat();


private:

	int numMinasProperas;
	bool destapat;
};

