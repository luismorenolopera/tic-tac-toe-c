#pragma once
#include "iostream"

using namespace std;

class Tablero
{
private:
	char tablero[6][6];
	unsigned short dimension;

public:
	Tablero(void);
	~Tablero(void);
	void setDimension(unsigned short dim);
	void setFicha(int x, int y, char valor);
	void dibujar();
	char getPosicion(int fila, int col);
	int calcularResultado(char s1);
};
