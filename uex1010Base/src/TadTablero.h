/*
 * TadTablero.h
 *
 *  Created on: 28 de nov. de 2016
 *      Author: Angel Cañada y Carlos Guillen.
 */

#ifndef TADTABLERO_H_
#define TADTABLERO_H_
#include "TadCasilla.h"

#include "TadPieza.h"

const int MAX = 10;
typedef casilla Matriz[MAX][MAX];

struct Tablero {
	Matriz m;
	int tamano;
};
/*PRE:{3< tam <=10}
 *POST:{inicia el tablero}
 * Complejidad:O(1)
 */
void IniciarTablero(Tablero &t, int tam);

/*PRE:{Tablero inicializado}
 *POST:{Nos pinta por consola el tablero con una dimension tam}
 * Complejidad:O(n2)
 */
void mostrarTablero(Tablero t);

/*PRE:{Tablero y pieza inicializada}
 *POST:{Nos devuelve true si la pieza se puede colocar en la casilla que nos indican(fila,col) por parametros}
 * Complejidad:O(n2)
 */
bool SePuedeSituarPiezaZonaConcreta2(Tablero t, pieza p, int fila, int col);

/*PRE:{Tablero y pieza inicializada}
 *POST:{Pone valores en las casillas (correspondiente al color de la pieza) que ocupa la pieza generada}
 * Complejidad:O(n2)
 */
void rellenarPiezaEnTablero(Tablero &t, pieza p, int fila, int col);

/*PRE:{Tablero y piezas inicializadas}
 *POST:{}
 * Complejidad:O(n2)
 */
bool SePuedeSituarPieza(Tablero t, pieza p);

/*PRE:{Tablero inicializado}
 *POST:{Nos devuelve true la fila introducid por parametros esta llena }
 * Complejidad:O(n)
 */
bool estaFilaLlena(Tablero t, int fila);

/*PRE:{Tablero inicializado}
 *POST:{Nos devuelve true si hay alguna fila llena en el tablero}
 * Complejidad:O(n)
 */
bool cualquierFilaLlena(Tablero t);

/*PRE:{Tablero inicializado}
 *POST:{Vacia toda la fila que indicamos por parametro}
 * Complejidad:O(n)
 */
void VaciarFila(Tablero &t, int fila);

/*PRE:{Tablero inicializado}
 *POST:{Recorre todas las filas del tablero y va eliminando las que estan llenas}
 * Complejidad:O(n2)
 */
void VaciarTodasFilasLlenas(Tablero &t);

/*PRE:{Tablero inicializado}
 *POST:{Nos devuelve el tamaño del tablero}
 * Complejidad:O(1)
 */
int obtenerTamanio(Tablero t);

/*PRE:{Tablero inicializado}
 *POST:{Nos devuelve el numero de filas llenas del tablero}
 * Complejidad:O(n)
 */
int cuantasFilasLLenas(Tablero t);

/*PRE:{Tablero inicializado}
 *POST:{Pinta una pieza en el tablero}
 * Complejidad:O(n2)
 */
void pintarPieza(Tablero &t, pieza p, int fila, int col);

/*PRE:{Tablero inicializado}
 *POST:{Nos dice si una columna está llena o no del tablero}
 * Complejidad:O(n)
 */
bool estaColumnaLlena(Tablero t, int col);

/*PRE:{Tablero inicializado}
 *POST:{Vacia una columna concreta del tablero}
 * Complejidad:O(n)
 */
void VaciarColumna(Tablero &t, int col);





#endif /* TADTABLERO_H_ */
