#include "Tablero.h"


Tablero::Tablero(void)
{
}

Tablero::~Tablero(void)
{
}

void Tablero::setDimension(unsigned short dim)
{
  this->dimension = dim;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      this->tablero[i][j] = ' ';
    }
  }
}

void Tablero::setFicha(int x, int y, char simbolo)
{
  this->tablero[x][y] = simbolo;
}
void Tablero::dibujar()
{
  cout << "\n\n\n\n";
  cout << "\t\t\t\t\t\t"<<flush;
  cout << " "<<flush;
  for (int i = 0; i < this->dimension; i++) { cout << " " << i + 1 << flush; }
  cout << "\n";
  for (int i = 0; i < this->dimension; i++) {
    cout << "\t\t\t\t\t\t"<<flush;
    cout << i + 1 << flush;
    cout << "|" << flush;
    for (int j = 0; j < this->dimension; j++) {
      cout << this->tablero[i][j] << "|" << flush;
    }
    cout <<"\n";
  }
}

char Tablero::getPosicion(int fila, int col) {
  return this->tablero[fila][col];
}

int Tablero::calcularResultado(char s1)
{
 // calculo por filas
char anterior;
  for (int i = 0; i < this->dimension; i++) {
    anterior = this->tablero[i][0];
    for (int j = 0; j < this->dimension; j++) {
      if (this->tablero[i][j] == ' ' || this->tablero[i][j] != anterior) {
        break;
      } else if(this->tablero[i][j] == anterior && j + 1 == this->dimension) {
        return s1 == anterior ? 1 : 2;
      }
      anterior = this->tablero[i][j];
    }
  }

 // calculo por columnas
  for (int j = 0; j < this->dimension; j++) {
    anterior = this->tablero[0][j];
    for (int i = 0; i < this->dimension; i++) {
      if (this->tablero[i][j] == ' ' || this->tablero[i][j] != anterior) {
        break;
      } else if(this->tablero[i][j] == anterior && i + 1 == this->dimension) {
        return s1 == anterior ? 1 : 2;
      }
      anterior = this->tablero[i][j];
    }
  }

  // calculo diagonal principal
  anterior = this->tablero[0][0];
  for (int i = 0; i < this->dimension; i++) {
    if (this->tablero[i][i] == ' ' || this->tablero[i][i] != anterior) {
      break;
    } else if(this->tablero[i][i] == anterior && i + 1 == this->dimension) {
        return s1 == anterior ? 1 : 2;
      }
    anterior = this->tablero[i][i];
  }

  // calculo diagonal secundaria
  anterior = this->tablero[0][this->dimension - 1];
  for (int i = 0; i < this->dimension; i++) {
    if (this->tablero[i][this->dimension-i-1] == ' ' || this->tablero[i][this->dimension-i-1] != anterior) {
      break;
    } else if(this->tablero[i][this->dimension-i-1] == anterior && i + 1 == this->dimension) {
        return s1 == anterior ? 1 : 2;
      }
    anterior = this->tablero[i][this->dimension-i-1];
  }

    // calculo empate
  for (int i = 0; i < this->dimension; i++) {
    for (int j = 0; j < this->dimension; j++) {
      if (this->tablero[i][j] == ' ') {
        break;
      } else if(this->tablero[i][j] != ' ' && j + 1 == this->dimension && i + 1 == this->dimension) {
        return 3;
      }
    }
  }

  return 0;
}
