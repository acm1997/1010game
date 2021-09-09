/*
 * TadPieza.cpp
 *
 *  Created on: 28 de nov. de 2016
 *      Author: usuario
 */

#include "TadPieza.h"
#include <cstdlib>
#include "entorno.h"
void Iniciar(pieza &p){
	p.ancho=0;
	p.color=0;
	p.alto=0;
}

void generarPieza(pieza &p){
	p.ancho=rand()%4+1;
	p.alto=rand()%4+1;
	p.color=rand()%6+1;
}

void generarPiezaConcreta(pieza &p, int alto,int ancho,int color){
	p.ancho=ancho;
	p.alto=alto;
	p.color=color;
}

int obtenerAltoPieza (pieza p){
	return p.alto;
}

int obtenerAnchoPieza (pieza p){
	return p.ancho;
}
int obtenerColorPieza (pieza p){
	return p.color;
}

pieza rotarPieza(pieza &p){
	pieza r;
	r.ancho=p.alto;
	r.alto=p.ancho;
	r.color=p.color;
	return r;
}
