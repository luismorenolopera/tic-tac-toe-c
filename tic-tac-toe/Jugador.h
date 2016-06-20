#pragma once
class Jugador
{
private:
	unsigned short numero;
	char simbolo;
	int victorias;
	float porVictorias;
public:
	Jugador(unsigned short num);
	~Jugador(void);
	void addVictoria();
	char getSimbolo();
	unsigned short getNumero();
	int getVictorias();
	float getPorVictorias();
	void setPorVictorias(int nPartidas);
	void setSimbolo(char sim);
};
