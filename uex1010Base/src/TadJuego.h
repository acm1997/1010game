/*
 * TadJuego.h
 *
 *  Created on: 28 de nov. de 2016
 *      Author: Angel Cañada y Carlos Guillen.
 */

#ifndef TADJUEGO_H_
#define TADJUEGO_H_
#include "TadTablero.h"

struct Juego {
	Tablero t;
	int puntuacion;
	int maxPuntuacion;
	int numPieza;
};

int obtenerPuntuacionPartida(Juego ju);

int obtenerPuntuacionMaxima(Juego ju);

int obtenerNumPiezas(Juego ju);

bool iniciarJuego(Juego &ju);

void jugar(Juego &ju);

void terminar(Juego &ju);



#endif /* TADJUEGO_H_ */
