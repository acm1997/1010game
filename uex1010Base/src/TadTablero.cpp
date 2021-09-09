/*
 * TadTablero.cpp
 *
 *  Created on: 28 de nov. de 2016
 *      Author: usuario
 */

#include "TadTablero.h"
#include "TadPieza.h"
#include "TadCasilla.h"
#include "entorno.h"
#include <iostream>

using namespace std;

void IniciarTablero(Tablero &t, int tam) {
	int fila, col;

	t.tamano = tam;

	for (fila = 0; fila < tam; fila++) {
		for (col = 0; col < tam; col++) {
			Iniciar(t.m[col][fila]);
		}
	}
}

void mostrarTablero(Tablero t) {
	int fila, col;
	for (fila = 0; fila < t.tamano; fila++) {
		for (col = 0; col < t.tamano; col++) {
			if (EstaVacia(t.m[fila][col])) {
				cout << "[" << " " << "]";
			} else
				cout << "[" << ValorColorCasilla(t.m[fila][col]) << "]";
		}
		cout << endl;
	}
}

bool SePuedeSituarPiezaZonaConcreta2(Tablero t, pieza p, int fila, int col) {
	int i, j;
	bool puedo = false;
	i = fila;


	//Para ver si existe el tamaño necesario en el tablero
	if ((obtenerTamanio(t) - col) >= obtenerAnchoPieza(p) && (obtenerTamanio(t) - fila) >= obtenerAltoPieza(p)) {

		bool enc = true;

		//Para ver si ese espacio está ocupado
		while (i < (fila + obtenerAltoPieza(p)) && enc) {
			j = col;
			while (j < (col + obtenerAnchoPieza(p)) && enc) {
				if (!EstaVacia(t.m[i][j])) {
					enc = false;
				}
				j++;
			}
			i++;
		}
		if (enc) {
			puedo = true;
		}
	}
	return puedo;
}

void rellenarPiezaEnTablero(Tablero &t, pieza p, int fila, int col) {

	for (int i = fila; i < fila + obtenerAltoPieza(p); i++) {
		for (int j = col; j < col + obtenerAnchoPieza(p); j++) {
			PonerColorCasilla(t.m[i][j], obtenerColorPieza(p));
		}
	}
}

bool SePuedeSituarPieza(Tablero t, pieza p) {
	bool posible = false;
	int fila, col;

	for (fila = 0; fila < obtenerTamanio(t) && !posible; fila++) {
		for (col = 0; col < obtenerTamanio(t) && !posible; col++) {
			if (SePuedeSituarPiezaZonaConcreta2(t, p, fila, col)) {
				posible = true;
			}
		}
	}
	return posible;
}

bool estaFilaLlena(Tablero t, int fila) {

	bool llena = false;
	int col = 0;
	int cont = 0;

	for (col = 0; col < obtenerTamanio(t); col++) {
		if (!EstaVacia((t.m[fila][col]))) {
			cont++;
		}
	}
	if (cont == obtenerTamanio(t)) {
		llena = true;
	} else {
		llena = false;
	}
	return llena;
}

bool cualquierFilaLlena(Tablero t) {
	bool llena = false;
	int fila;

	for (fila = 0; fila < t.tamano; fila++) {
		if (estaFilaLlena(t, fila)) {
			llena = true;
		}
	}
	return llena;
}

void VaciarFila(Tablero &t, int fila) {
	for (int col = 0; col < t.tamano; col++) {
		VaciarCasilla(t.m[fila][col]);
	}
}

void VaciarTodasFilasLlenas(Tablero &t) {
	for (int i = 0; i < t.tamano; i++) {
		if (estaFilaLlena(t, i)) {
			VaciarFila(t, i);
		}
	}
}

int obtenerTamanio(Tablero t) {
	return t.tamano;
}

int cuantasFilasLLenas(Tablero t) {
	int cont = 0;
	for (int i = 0; i < obtenerTamanio(t); i++) {
		if (estaFilaLlena(t, i)) {
			cont = cont + 1;
		}

	}
	return cont;
}

void pintarPieza(Tablero &t, pieza p, int fila, int col) {
	for (int i = fila; i < fila + obtenerAltoPieza(p); i++) {
		for (int j = col; j < col + obtenerAnchoPieza(p); j++) {
			entornoColorearCasilla(i, j, obtenerColorPieza(p));
		}
	}
}

bool estaColumnaLlena(Tablero t, int col) {

	bool llena = false;
	int fila = 0;
	int cont = 0;

	for (fila = 0; fila < obtenerTamanio(t); fila++) {
		if (!EstaVacia((t.m[fila][col]))) {
			cont++;
		}
	}
	if (cont == obtenerTamanio(t)) {
		llena = true;
	} else {
		llena = false;
	}
	return llena;
}

void VaciarColumna(Tablero &t, int col) {
	for (int fila = 0; fila < t.tamano; fila++) {
		VaciarCasilla(t.m[fila][col]);
	}
}






