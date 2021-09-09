/*
 * PruebasEntorno.cpp
 *
 *  Created on: 12 dic. 2016
 *      Author: carlos
 */
#include <iostream>
#include "PruebasEntorno.h"
#include "entorno.h"
#include <cstdlib>
using namespace std;

void pr_entornoIniciar(){
	int tamano;
	cout << "Introduzca el tamaño del tablero: " << endl;
	cin >> tamano;
	if(tamano<=9 && tamano>2){
		entornoIniciar(tamano);
		cout << "Tablero iniciado." << endl;
	}else{
		cout << "Error al iniciar." << endl;
	}
	entornoLeerTecla();
}

//modulo que comprueba que el entorno es capaz de leer, y que lo hace correctamente, el fichero 1010!.cnf para
//cargar la configuracion que, ya en el juego, se usará para iniciar el entorno aunque aquí no se haga así.
void pr_entornoCargarConfiguracion(){
	int dimension, puntuacion, numPiezas;
	bool valido;
	cout << "Inicio de pruebas de 'entornoCargarConfiguracion'" << endl;
	valido=entornoCargarConfiguracion(dimension, puntuacion, numPiezas);
	cout << "Configuracion:" << endl; //muestra por pantalla los valores de las variables escritas en uex2048.cnf para que se pueda comprobar si son correctas o no.
	cout << "Dimension: " << dimension << endl; //dimension del tablero
	cout << "Valor: " << puntuacion << endl; //valor a alcanzar
	cout << "Inicio: " << numPiezas << endl; //numero de valores aleatorios iniciales

	if (valido == true) //prueba que el modulo sea capaz de cargar correctamente el fichero
		cout << "Prueba 'entornoCargarConfiguracion' CORRECTA" << endl;
	else
		cout << "PROBLEMA LEYENDO EL FICHERO 1010!.cnf" << endl;




}

void pr_entornoColorearCasilla(){
	int fila, columna, color;
	int tamano=10;
	cout<<"Inicio pruebas colorearCasilla:"<<endl;
		cout<<"		Deben pintarse las siguientes casillas:"<<endl;		//
		cout<<"			Fila: 1		Columna: 1		Color: 4"<<endl;	//
		cout<<"			Fila: 7		Columna: 8		Color: 5"<<endl;	//
		cout<<"			Fila: 1		Columna: 7		Color: 3"<<endl;	//
		cout<<"			Fila: 7		Columna: 7		Color: 1"<<endl;	//
		cout<<"			Fila: 4		Columna: 4		Color: 2"<<endl;	//
	entornoIniciar(tamano);
	entornoColorearCasilla(1,1,4);
	entornoColorearCasilla(7,8,5);
	entornoColorearCasilla(1,7,3);
	entornoColorearCasilla(7,7,1);
	entornoColorearCasilla(4,4,2);


		cout << "Introduce una fila:" << endl;
		cin >> fila;
		cout << "Introduce una columna:" << endl;
		cin >> columna;
		cout << "Introduce un valor para el color:" << endl;
		cin >> color;
		entornoColorearCasilla(fila- 1, columna-1, color);
		entornoLeerTecla();

		cout<<"Fin pruebas colorear casilla."<<endl;
}

void pr_entornoBorrarCasilla(){

	int tamano, fila, columna;
	tamano=10;

	//COLOREAMOS TODO EL TABLERO//
	int i=0;
	int j=0;
	entornoIniciar(tamano);
	for(i=0;i<tamano;i++){
		for(j=0;j<tamano;j++){
			entornoColorearCasilla(i,j,1);
		}
	}
	entornoMostrarMensaje(Zona1, "Prueba eliminar casilla");
		entornoBorrarCasilla(4, 1);
		entornoBorrarCasilla(6, 1);
		entornoBorrarCasilla(1, 6);
		entornoBorrarCasilla(6, 6);
		entornoBorrarCasilla(3, 3);

		cout << "Introduce una fila:" << endl;
		cin >> fila;
		cout << "Introduce una columna:" << endl;
		cin >> columna;

		entornoBorrarCasilla(fila- 1, columna-1);

		cout<<"Fin pruebas borrar casilla."<<endl;

		entornoLeerTecla();
		entornoPausa(2.0);

}

void pr_entornoPintarPieza(){
	int ancho, alto, color;
	int tamano=10;
	cout<<"Inicio prueba entornoPintarPieza: "<<endl;
	cout<<"Introduce el ancho de la pieza: "<<endl;
	cin>>ancho;
	cout<<"Introduce el alto de la pieza: "<<endl;
	cin>>alto;
	cout<<"Introduce el color de la pieza: "<<endl;
	cin>>color;
	entornoIniciar(tamano);
	entornoMostrarMensaje(Zona1, "Prueba entornoPintarPieza");

	entornoPintarPieza(Zona2, ancho, alto, color);

	cout<<"Fin prueba entornoPintarPieza."<<endl;

	entornoLeerTecla();
	entornoPausa(1.0);

}

void pr_entornoPintarPiezaCuadrada(){
	int ancho, alto, color;
	int tamano=10;
	cout<<"Inicio prueba entornoPintarPieza: "<<endl;
	cout<<"Introduce el ancho de la pieza: "<<endl;
	cin>>ancho;
	cout<<"Introduce el alto de la pieza: "<<endl;
	cin>>alto;
	cout<<"Introduce el color de la pieza: "<<endl;
	cin>>color;


	if(alto==ancho){
	entornoIniciar(tamano);
	entornoMostrarMensaje(Zona1, "Prueba entornoPintarPieza");

	entornoPintarPieza(Zona2, ancho, alto, color);

	cout<<"Fin prueba entornoPintarPieza. La pieza pintada si es cuadrada."<<endl;

	entornoLeerTecla();
	entornoPausa(1.0);
	}
	else{
		cout<<"Error, la pieza no es cuadrada."<<endl;
	}
}

void pr_entornoEliminarPieza(){


}

void pr_entornoActivarCasilla(){
	int tamano=10;

	cout<<"Inicio pruebas ActivarCasilla:"<<endl;
	cout<<"		Deben activarse las siguientes casillas:"<<endl;
	cout<<"			Fila: 1		Columna: 1		"<<endl;
	cout<<"			Fila: 7		Columna: 8		"<<endl;
	cout<<"			Fila: 1		Columna: 7		"<<endl;
	cout<<"			Fila: 7		Columna: 7		"<<endl;
	cout<<"			Fila: 4		Columna: 4		"<<endl;

	entornoIniciar(tamano);
	entornoMostrarMensaje(Zona1, "Prueba entornoActivarCasilla");
	entornoActivarCasilla(1,1);
	entornoActivarCasilla(7,8);
	entornoActivarCasilla(1,7);
	entornoActivarCasilla(7,7);
	entornoActivarCasilla(4,4);

	cout<<"Fin prueba entornoActivarCasilla"<<endl;

	entornoLeerTecla();
	entornoPausa(1.0);


}

void pr_entornoDesactivarCasilla(){
	int tamano;
	tamano=10;

	//COLOREAMOS TODO EL TABLERO//
	int i=0;
	int j=0;
	cout<<"Inicio pruebas ActivarCasilla:"<<endl;
	entornoIniciar(tamano);
	for(i=0;i<tamano;i++){
		for(j=0;j<tamano;j++){
			entornoActivarCasilla(i,j);
		}
	}
	entornoMostrarMensaje(Zona1, "Prueba eliminar casilla");
		entornoDesactivarCasilla(4, 1);
		entornoDesactivarCasilla(6, 1);
		entornoDesactivarCasilla(1, 6);
		entornoDesactivarCasilla(6, 6);
		entornoDesactivarCasilla(3, 3);

		cout<<"Fin prueba entornoDesactivarCasilla."<<endl;

		entornoLeerTecla();
		entornoPausa(1.0);

}

void pr_entornoPuntuacionMaxima(){
	int MAX,tamano=10;
	cout << "Inicio pruebas entornoPuntuacionMaxima." << endl;
	cout << "Introduce la máxima puntuación: " <<endl;
	cin >>MAX;
	entornoIniciar(tamano);
	entornoMostrarMensaje(Zona1, "Prueba entornoPuntuacionMaxima");
	entornoPuntuacionMaxima(MAX);
	cout<<"Fin prueba entornoPuntuacionMaxima."<<endl;

	entornoLeerTecla();
	entornoPausa(1.0);


}

void pr_entornoPonerPuntuacion(){
	int puntAct,tamano=10;
		cout << "Inicio pruebas entornoPonerPuntuacion." << endl;
		cout << "Introduce la puntuación: " <<endl;
		cin >>puntAct;
		entornoIniciar(tamano);
		entornoMostrarMensaje(Zona1, "Prueba entornoPonerPuntuacion");
		entornoPonerPuntuacion(puntAct);
		cout<<"Fin prueba entornoPonerPuntuacion."<<endl;
		entornoLeerTecla();
		entornoPausa(1.0);
}

void pr_entornoLeerTecla(){
	bool salir;
	TipoTecla c;
	cout<<"Inicio de las pruebas de 'entornoLeerTecla'"<<endl;
	entornoIniciar(10);
	entornoMostrarMensaje(Zona1,"");
	entornoMostrarMensaje(Zona3,"");

	while(!salir){
		c= entornoLeerTecla();
		switch(c){
		case TIzquierda:
			entornoMostrarMensaje(Zona2, "Izq");
			break;
		case TDerecha:
			entornoMostrarMensaje(Zona2, "Der");
			break;
		case TAbajo:
			entornoMostrarMensaje(Zona2, "Abajo");
			break;
		case TArriba:
			entornoMostrarMensaje(Zona2, "Arriba");
			break;
		case TEnter:
			entornoMostrarMensaje(Zona2, "Enter");
			break;
		case TUno:
			entornoMostrarMensaje(Zona2, "1");
			break;
		case TDos:
			entornoMostrarMensaje(Zona2, "2");
			break;
		case TTres:
			entornoMostrarMensaje(Zona2, "3");
			break;
		case TX:
			entornoMostrarMensaje(Zona2, "X");
			break;
		case TSalir:
			entornoMostrarMensaje(Zona2, "SALIR");
			salir=true;
			break;
		case TNada:
			break;
		}

	}
		entornoLeerTecla();
		entornoPausa(1.0);


		cout<<"FIN Prueba de 'entornoLeerTecla'"<<endl;

}

void pr_entornoPausa(){
	float pausa;
	cout<<"Introduzca el valor de la pausa que quieras dar para terminar el programa: "<<endl;
	cin>>pausa;

	entornoIniciar(10);
	entornoLeerTecla();
	entornoPausa(pausa);


		cout<<"La prueba de entornoPausa es correcta."<<endl;


}

void pruebasEntorno(){
	cout<<"Inicio Pruebas Entorno: "<<endl;
	pr_entornoIniciar();
	pr_entornoCargarConfiguracion();
	pr_entornoColorearCasilla();
	pr_entornoBorrarCasilla();
	pr_entornoPintarPieza();
	pr_entornoPintarPiezaCuadrada();
	pr_entornoEliminarPieza();
	pr_entornoActivarCasilla();
	pr_entornoDesactivarCasilla();
	pr_entornoPuntuacionMaxima();
	pr_entornoPonerPuntuacion();
	pr_entornoLeerTecla();
	pr_entornoPausa();

	cout<<"Fin pruebas entorno: "<<endl;
	cout<<endl;
}




























