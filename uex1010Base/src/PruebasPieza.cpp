/*
 * PruebasPieza.cpp
 *
 *  Created on: 14 ene. 2017
 *      Author: carlos
 */

#include "PruebasPieza.h"
#include "TadPieza.h"
#include <iostream>
using namespace std;

void pruebaIniciarPieza(){
	cout << "***PRUEBA INICIAR PIEZA: ***" <<endl;
	pieza p;
	Iniciar(p);
	cout<< "Alto: "<<obtenerAltoPieza(p) << endl;
	cout<< "Ancho: "<<obtenerAnchoPieza(p) << endl;
	cout<< "Color: "<<obtenerColorPieza(p) << endl;
	cout<<endl;
}

void pruebaGenerarPieza(){
	cout << "***PRUEBA GENERAR PIEZA: ***" <<endl;
	pieza p;
	generarPieza(p);
	cout<<"Las dimensiones de la pieza son las siguientes: "<<endl;
	cout<< "Alto: "<<obtenerAltoPieza(p) << endl;
	cout<< "Ancho: "<<obtenerAnchoPieza(p) << endl;
	cout<< "Color: "<<obtenerColorPieza(p) << endl;

	cout<<endl;

}

void pruebaObtenerAltoPieza(){
	cout << "***PRUEBA ALTO PIEZA: ***" <<endl;
	pieza p;
	generarPieza(p);
	cout<<"El alto de la pieza es : "<<obtenerAltoPieza(p)<<endl;
	cout<<endl;

}

void pruebaObtenerAnchoPieza(){
	cout << "***PRUEBA ANCHO PIEZA: ***" << endl;
	pieza p;
	generarPieza(p);
	cout << "El ancho de la pieza es : " << obtenerAnchoPieza(p) << endl;
	cout<<endl;
}

void pruebaObtenerColorPieza(){
	cout << "***PRUEBA COLOR PIEZA: ***" << endl;
	pieza p;
	generarPieza(p);
	cout << "El color de la pieza es : " << obtenerColorPieza(p)<<endl;
	cout<<endl;
}

void pruebasPieza(){
	pruebaIniciarPieza();
	pruebaGenerarPieza();
	pruebaObtenerAltoPieza();
	pruebaObtenerAnchoPieza();
	pruebaObtenerColorPieza();
}
