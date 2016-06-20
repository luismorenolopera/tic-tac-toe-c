#include <iostream>
#include "Juego.h"
#include "Estadistica.h"
#include "Jugador.h"
#include "Tablero.h"

using namespace std;

int main()
{
	int dimension, col, fila;
	unsigned short turno;
	char simbolo, jugar;

	Juego juego;
	Estadistica estadistica;
	Jugador jugadorA(1), jugadorB(2);
	Tablero tablero;

	system("color 0B");

	while (!juego.getSalir()) {
		juego.setGameOver(false);

		do {
			cout << "Ingreseñ la dimension del tablero (3|4|5): ";
			cin >> dimension;
			if (dimension > 5 || dimension < 3)
				cout << "\n ERROR: Escoja una dimension en el rango dado" << endl;
		} while(dimension > 5 || dimension < 3);
		tablero.setDimension(dimension);

		do {
			cout << "\nQue jugador empezara la partida (1|2): ";
			cin >> turno;
			if (turno > 2 || turno < 1)
				cout << "\n ERROR: Escoja un Jugador en el rango dado" << endl;
		} while(turno > 2 || turno < 1);
		juego.setTurno(turno);

		do {
			cout << "\nElija el simbolo del jugador que inicia (O|X): ";
			cin >> simbolo;
			if (toupper(simbolo) != 'O' && toupper(simbolo) != 'X')
				cout << "\n ERROR: Escoja el caracter X o O" << endl;
		} while(toupper(simbolo) != 'O' && toupper(simbolo) != 'X');

		// asignacion del simbolo
		if (turno == 1) {
			jugadorA.setSimbolo(toupper(simbolo));
			if (toupper(simbolo) == 'X') {
				jugadorB.setSimbolo('O');
			} else {
				jugadorB.setSimbolo('X');
			}
		} else {
			jugadorB.setSimbolo(toupper(simbolo));
			if (toupper(simbolo) == 'X') {
				jugadorA.setSimbolo('O');
			} else {
				jugadorA.setSimbolo('X');
			}
		}
		system("cls");

		while(!juego.getGameOver()){
			cout << "Cantidad de partidas jugadas: " << estadistica.getNPartidas() << "\t\tVictorias Jugador 1: " << jugadorA.getVictorias()<<endl;
			cout << "Victorias Jugador 2: " << jugadorB.getVictorias() << "\t\tEmpates: " << estadistica.getNEmpates()<<endl;
			cout << "Turno: Jugador " << juego.getTurno();
			tablero.dibujar();
			cout << "\n\n\n\n";

			do {
				do
				{
					cout << "Ingresa la fila: ";
					cin >> fila;
					if(fila > dimension || fila < 1) {
						cout << " ERROR: fila fuera de rango intente de nuevo" << endl;
					}
				} while(fila > dimension || fila < 1);

				do
				{
					cout << "Ingresa la columna: ";
					cin >> col;
					if (col > dimension || col < 1) {
						cout << " ERROR: columna fuera de rango intente de nuevo" << endl;
					}
				} while(col > dimension || col < 1);

				if (tablero.getPosicion(fila - 1, col - 1) != ' ')
					cout << "ERROR: casilla ocupada" << endl;
			} while(tablero.getPosicion(fila - 1, col - 1) != ' ');

			juego.getTurno() == 1 ? tablero.setFicha(fila - 1, col - 1, jugadorA.getSimbolo()): tablero.setFicha(fila - 1, col - 1, jugadorB.getSimbolo());

			system("cls");
			tablero.dibujar();

			if (tablero.calcularResultado(jugadorA.getSimbolo()) == 1) {
					cout << "\t\t\t\t\t\t\n\nEl ganador es el jugador 1 " << jugadorA.getSimbolo();
					system("pause>nul");
					jugadorA.addVictoria();
					estadistica.addPartida();
					juego.setGameOver(true);
			} else if(tablero.calcularResultado(jugadorA.getSimbolo()) == 2) {
					cout << "\t\t\t\t\t\t\n\nEl ganador es el jugador 2 " << jugadorB.getSimbolo();
					system("pause>nul");
					jugadorB.addVictoria();
					estadistica.addPartida();
					juego.setGameOver(true);
			} else if(tablero.calcularResultado(jugadorA.getSimbolo()) == 3) {
					cout << "\t\t\t\t\t\t\n\nEmpate";
					system("pause>nul");
					estadistica.addEmpate();
					estadistica.addPartida();
					juego.setGameOver(true);

			}

			if (juego.getGameOver()) {
				cout << "\n\n  ¿Desea volver a jugar? (S/N): ";
				cin >> jugar;
				jugadorA.setPorVictorias(estadistica.getNPartidas());
				jugadorB.setPorVictorias(estadistica.getNPartidas());
				estadistica.setPorEmpates();
				if (toupper(jugar) == 'N') {
					cout << "Partidas jugadas: " << estadistica.getNPartidas() << endl;
					cout << "Victorias jugador 1: " << jugadorA.getVictorias() << endl;
					cout << "Porcentaje de victorias jugador 1: " << jugadorA.getPorVictorias() << "%" << endl;
					cout << "Victorias jugador 2: " << jugadorB.getVictorias() << endl;
					cout << "Porcentaje de victorias jugador 2: " << jugadorB.getPorVictorias() << "%" << endl;
					cout << "Empates: " << estadistica.getNEmpates() << endl;
					cout << "Porcentaje de empates: " << estadistica.getPorEmpates() << "%" << endl;
					juego.setSalir(true);
					system("pause>nul");
					system("cls");
				}
			}
			juego.getTurno() == 1 ? juego.setTurno(2) : juego.setTurno(1);
			system("cls");
		}
	}
	system("pause>nul");
	return 0;
}
