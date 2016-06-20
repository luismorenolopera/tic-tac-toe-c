#include "Juego.h"


Juego::Juego(void)
{
  this->gameOver = false;
  this->salir = false;
}


Juego::~Juego(void)
{
}


void Juego::setTurno(unsigned short tur)
{
  this->turno = tur;
}

unsigned short Juego::getTurno()
{
  return this->turno;
}

bool Juego::getGameOver()
{
  return this->gameOver;
}

bool Juego::getSalir()
{
  return this->salir;
}

void Juego::setGameOver(bool game)
{
  this->gameOver = game;
}

void Juego::setSalir(bool sal)
{
  this->salir = sal;
}
