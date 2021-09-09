/*
 * TadJuego.cpp
 *
 *  Created on: 28 de nov. de 2016
 *      Author: usuario
 */

#include "TadJuego.h"
#include "TadTablero.h"
#include "entorno.h"
#include <cstdlib>
#include <iostream>
using namespace std;


int obtenerPuntuacionPartida(Juego ju){
	return ju.puntuacion;
}

int obtenerPuntuacionMaxima(Juego ju){
	return ju.maxPuntuacion;
}

int obtenerNumPiezas(Juego ju){
	return ju.numPieza;
}


bool iniciarJuego(Juego &ju) {
	bool exito=false;
	int numPieza;
	ju.puntuacion = 0;	//pone la puntuacion a 0
	int dimension;
	if(entornoCargarConfiguracion(dimension, ju.maxPuntuacion, numPieza)){//carga el fichero de configuracion con las variables correspondientes
	IniciarTablero(ju.t, dimension);
	entornoIniciar(dimension);//inicia el enorno grafico con las dimensión "dimension"
	exito=true;

	srand(time(NULL));
	}
return exito;

}

void jugar(Juego &ju) {
	int fila, col;
	//int y,z,w;
	bool salir = false;
	TipoTecla tecla;
	int filas[obtenerTamanio(ju.t)];
	int columnas[obtenerTamanio(ju.t)];

	//Inicializo los vectores a 0
	for(int q=0; q<obtenerTamanio(ju.t); q++){
		filas[q]=0;
		columnas[q]=0;
	}

	fila = 0;
	col = 0;
	entornoActivarCasilla(fila, col);
	pieza p;
	generarPieza(p);
	entornoPintarPieza(Zona1, obtenerAnchoPieza(p), obtenerAltoPieza(p),obtenerColorPieza(p));
	entornoPuntuacionMaxima(ju.maxPuntuacion);

	while (!salir) {
		tecla = entornoLeerTecla();
		switch (tecla) {

		case TEnter:



				if (SePuedeSituarPiezaZonaConcreta2(ju.t, p, fila, col)  ) {
				rellenarPiezaEnTablero(ju.t, p, fila, col);
				pintarPieza(ju.t, p, fila, col);
				ju.puntuacion = ju.puntuacion + obtenerAltoPieza(p) * obtenerAnchoPieza(p);
				entornoPonerPuntuacion(ju.puntuacion);
				//Indico que filas están llenas.
				for(int i=0;i<obtenerTamanio(ju.t); i++){
					if(estaFilaLlena(ju.t,i)){
						filas[i]=1;
					}
				}
				//Indico qué columnas están llenas
				for(int j=0;j<obtenerTamanio(ju.t); j++){
					if(estaColumnaLlena(ju.t,j)){
						columnas[j]=1;
					}
				}
				//Vacio las filas llenas y actualizo marcador
				for(int h=0;h<obtenerTamanio(ju.t);h++){
					if(filas[h]==1){
						ju.puntuacion=ju.puntuacion+obtenerTamanio(ju.t);
						VaciarFila(ju.t,h);
						filas[h]=0;
						for(int w=0; w<obtenerTamanio(ju.t); w++){
							entornoBorrarCasilla(h,w);
						}
					}
				}
				//Vacio las columnas llenas y actualizo marcador
				for(int k=0;k<obtenerTamanio(ju.t);k++){
					if(columnas[k]==1){
						ju.puntuacion=ju.puntuacion+obtenerTamanio(ju.t);
						VaciarColumna(ju.t,k);
						columnas[k]=0;
						for(int l=0; l<obtenerTamanio(ju.t); l++){
							entornoBorrarCasilla(l,k);
						}
					}
				}

				entornoPonerPuntuacion(ju.puntuacion);
				entornoEliminarPieza(Zona1);
				generarPieza(p);
				entornoPintarPieza(Zona1, obtenerAnchoPieza(p),
						obtenerAltoPieza(p), obtenerColorPieza(p));
				if (SePuedeSituarPieza(ju.t, p)||SePuedeSituarPieza(ju.t,rotarPieza(p))) {
				} else {
					entornoMostrarMensajeFin("Juego finalizado");
					salir = true;
					entornoPausa(3.0);
				}
			}

				break;
				case TDerecha:
				entornoDesactivarCasilla(fila, col);
				if (col < obtenerTamanio(ju.t) - 1)
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
					col = obtenerTamanio(ju.t) - 1;
				entornoActivarCasilla(fila, col);
				break;
				case TArriba:
				entornoDesactivarCasilla(fila, col);
				if (fila > 0)
					fila--;
				else
					fila = obtenerTamanio(ju.t) - 1;
				entornoActivarCasilla(fila, col);
				break;
				case TAbajo:
				entornoDesactivarCasilla(fila, col);
				if (fila < obtenerTamanio(ju.t) - 1)
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
					p=rotarPieza(p);
					entornoEliminarPieza(Zona1);
					entornoPintarPieza(Zona1, obtenerAnchoPieza(p), obtenerAltoPieza(p), obtenerColorPieza(p));

				break;
				case TNada:
				break;

			}

		}



	entornoPausa(1.0);
}


void terminar(Juego &ju){

	if(obtenerPuntuacionPartida(ju)>obtenerPuntuacionMaxima(ju)){
		ju.maxPuntuacion= obtenerPuntuacionPartida(ju);
		entornoGuardarConfiguracion(obtenerTamanio(ju.t),obtenerPuntuacionMaxima(ju),obtenerNumPiezas(ju));
	}

	entornoTerminar ();

}



