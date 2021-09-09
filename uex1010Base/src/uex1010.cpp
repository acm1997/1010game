//============================================================================
// Name        : uex1010.cpp
// Author      : Angel Cañada y Carlos Guillen.
// Version     : Curso 16/17
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "entorno.h"
#include "PruebasEntorno.h"
#include "TadTablero.h"
#include "TadCasilla.h"
#include "TadPieza.h"
#include "TadJuego.h"
#include "PruebaTablero.h"
#include "PruebasPieza.h"
#include "PruebasCasilla.h"
#include "PruebasTadJuego.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void MenuPruebas(){
	int a;

		cout<<"Numero 1-> Pruebas del Tad Casilla."<<endl;
		cout<<"Numero 2-> Pruebas del Tad Pieza."<<endl;
		cout<<"Numero 3-> Pruebas del Tad Tablero ."<<endl;
		cout<<"Numero 4-> Pruebas del Tad Juego."<<endl;
		cout<<"Introduce un numero del 1 al 4: "<<endl;
		cin>>a;

		if(a==1){
				pruebasCasilla();
				cout<<"FIN DE LAS PRUEBAS DEL TAD CASILLA."<<endl;
			}
			else{
				if(a==2){
					pruebasPieza();
					cout<<"FIN DE LAS PRUEBAS DEL TAD PIEZA."<<endl;
				}
				else{
					if(a==3){
						pruebasTablero();
						cout<<"FIN DE LAS PRUEBAS DEL TAD TABLERO."<<endl;
					}
					else{
						pruebasTadJuego();
						cout<<"FIN DE LAS PRUEBAS DEL TAD JUEGO."<<endl;
					}
				}
			}


}

void pruebasBasicas(){
	int tamanio, maxPuntos, numPiezas;
	int fila, col;
	bool salir;
	TipoTecla tecla;
	srand(time(NULL));
	pieza p;

	if (entornoCargarConfiguracion(tamanio, maxPuntos, numPiezas)) {
		entornoIniciar(tamanio);
	}
	fila = 0;
	col = 0;
	entornoActivarCasilla(fila, col);
	salir = false;

	generarPieza(p);

	while (!salir) {

		tecla = entornoLeerTecla();
		switch (tecla) {

		case TEnter:
			entornoColorearCasilla(fila, col, COLOR_VERDE);
			break;
		case TDerecha:
			entornoDesactivarCasilla(fila, col);
			if (col < tamanio - 1)
				col++;
			else
				col = 0;
			entornoActivarCasilla(fila, col);
			break;
		case TIzquierda:
			entornoDesactivarCasilla(fila, col);
			if (col > 0)
				col--;
			else
				col = tamanio - 1;
			entornoActivarCasilla(fila, col);
			break;
		case TArriba:
			entornoDesactivarCasilla(fila, col);
			if (fila > 0)
				fila--;
			else
				fila = tamanio - 1;
			entornoActivarCasilla(fila, col);
			break;
		case TAbajo:
			entornoDesactivarCasilla(fila, col);
			if (fila < tamanio - 1)
				fila++;
			else
				fila = 0;
			entornoActivarCasilla(fila, col);
			break;
		case TSalir:
			salir = true;
			break;
		case TUno:
			break;
		case TDos:
			break;
		case TTres:
			break;
		case TX:
			break;
		case TNada:
			break;

		}
	}

	//entornoMostrarMensajeFin("      Adios");
	entornoPausa(1.0);
	entornoTerminar();
}
int main() {

	//MenuPruebas();

	Juego ju;

	if(iniciarJuego(ju)){
		jugar(ju);
		terminar(ju);
	}


	return 0;
}
