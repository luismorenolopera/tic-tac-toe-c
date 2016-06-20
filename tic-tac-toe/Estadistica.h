#pragma once

class Estadistica
{
private:
	int nPartidas;
	int nEmpates;
	float porEmpates;
public:
	Estadistica(void);
	~Estadistica(void);
	void addEmpate();
	void addPartida();
	int getNPartidas();
	int getNEmpates();
	float getPorEmpates();
	void setPorEmpates();
};
