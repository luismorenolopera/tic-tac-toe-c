#pragma once
#include <iostream>

using namespace std;

class Juego
{
private:
	unsigned short turno;  // almacena el turno del jugador
	bool gameOver;
	bool salir;
public:
	Juego(void);
	~Juego(void);
	void setTurno(unsigned short tur);
	unsigned short getTurno();
	bool getGameOver();
	bool getSalir();
	void setGameOver(bool game);
	void setSalir(bool sal);
};
