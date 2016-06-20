#include "Jugador.h"


Jugador::Jugador(unsigned short num)
{
  this->numero = num;
  this->victorias = 0;
}


Jugador::~Jugador(void)
{
}

void Jugador::addVictoria()
{
  this->victorias += 1;
}

char Jugador::getSimbolo()
{
  return this->simbolo;
}

unsigned short Jugador::getNumero()
{
  return this->numero;
}

int Jugador::getVictorias()
{
  return this->victorias;
}

float Jugador::getPorVictorias()
{
  return this->porVictorias;
}

void Jugador::setPorVictorias(int nPartidas)
{
  this->porVictorias = (float)this->victorias * 100 / nPartidas;
}

void Jugador::setSimbolo(char sim)
{
  this->simbolo = sim;
}
