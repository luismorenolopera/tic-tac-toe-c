#include "Estadistica.h"


Estadistica::Estadistica(void)
{
  this->nPartidas = 0;
	this->nEmpates = 0;
}


Estadistica::~Estadistica(void)
{

}

void Estadistica::addEmpate()
{
  this->nEmpates += 1;
}

void Estadistica::addPartida()
{
  this->nPartidas += 1;
}

int Estadistica::getNPartidas()
{
  return this->nPartidas;
}

int Estadistica::getNEmpates()
{
  return this->nEmpates;
}

float Estadistica::getPorEmpates()
{
  return this->porEmpates;
}

void Estadistica::setPorEmpates()
{
  this->porEmpates = this->nEmpates * 100 / this->nPartidas;
  if (this->nEmpates == 0) {
    this->porEmpates = 0;
  }
}
