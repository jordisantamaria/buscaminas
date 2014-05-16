#pragma once

#include <iostream>



using namespace std;
class CMenuScreen
{
public:
	CMenuScreen(void);
	~CMenuScreen(void);

	void show(int &estatActual, int &dificultatGame);

private:

	bool quit;
	int dificultat;
};

