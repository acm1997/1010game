/*
 * TadCasilla.cpp
 *
 *  Created on: 28 de nov. de 2016
 *      Author: usuario
 */

#include "TadCasilla.h"
#include <cstdlib>

void Iniciar(casilla &c){
	c.numColor=0;
	c.vacia=true;
}

void PonerColorCasilla(casilla &c, int n){
	c.numColor=n;
	c.vacia=false;
}

void VaciarCasilla(casilla &c){
	c.numColor=0;
	c.vacia=true;
}

int ValorColorCasilla(casilla c){
	return c.numColor;
}

bool EstaVacia(casilla c){
	return c.vacia;
}





