/*
 * PruebaTablero.cpp
 *
 *  Created on: 12 ene. 2017
 *      Author: carlos
 */

#include "PruebaTablero.h"
#include "TadPieza.h"
#include "TadTablero.h"

#include <iostream>

using namespace std;


void pruebaIniciarTablero(){
	cout << "***PRUEBA INICIAR TABLERO***" <<endl;
	Tablero t;
	IniciarTablero(t,10);
	mostrarTablero(t);

	cout<<"El tablero se ha iniciado correctamente."<<endl;
	cout<<endl;
}

void pruebaMostrarTablero(){
	cout << "***PRUEBA MOSTRAR TABLERO ***" <<endl;
	Tablero t;
	IniciarTablero(t, 10);
	mostrarTablero(t);
	cout<<"El tablero se ha mostrado correctamente."<<endl;
}

void pruebaSePuedeSituarPiezaZonaConcreta(){//EN ESTE MODULO PROBAMOS LOS MODULOS SePuedeSituarPiezaZonaConcreta
						//y el modulo RellenarPiezaTablero
	cout << "***PRUEBA SE PUEDE SITUAR PIEZA ZONA CONCRETA***" <<endl;
	int a,b,c,d;
	Tablero t;
	pieza p;
	IniciarTablero(t,10);		//iniciamos el tablero con una dimension de 10x10

	PonerColorCasilla(t.m[3][4],1);
	PonerColorCasilla(t.m[2][2],5);
	PonerColorCasilla(t.m[8][1],3);
	PonerColorCasilla(t.m[9][9],1);

	cout<<"Introduce un ancho de la pieza:"<<endl;
	cin>>a;
	cout<<"Introduce un alto de la pieza:"<<endl;
	cin>>b;
	generarPiezaConcreta(p,b,a,2);  //Generamos una pieza con los valores que metemos por parametros

	cout<<"Alto: " <<obtenerAltoPieza(p)<<endl;	//Nos muestra por consola el valor del ancho y el alto de la pieza que hemos creado
	cout<<"Ancho: "<<obtenerAnchoPieza(p)<<endl;

	cout<<"Introduces en que fila del tablero quieres situar la pieza: "<<endl;
	cin>>c;
	cout<<"Introduce en que ancho del tablero quieres situar la pieza: "<<endl;
	cin>>d;


	if(	SePuedeSituarPiezaZonaConcreta2(t,p,c,d)){	//comprobamos si se puede situar la pieza en la zona concreta que ponemos por parametros
		cout<<"Si se puede situar la pieza."<<endl;
		rellenarPiezaEnTablero(t,p,c,d);
	}

	else{
		cout<<"No se puede situar"<<endl;
	}

	mostrarTablero(t);		//Nos muestra el tablero con la pieza pintada si esta en una posicion correcta.

}

void pruebaSePuedeSituarPieza(){
	cout << "***PRUEBA SE PUEDE SITUAR PIEZA***" <<endl;
	int a, b;
	Tablero t;
	pieza p;
	IniciarTablero(t, 5);	//iniciamos el tablero con una dimension de 10x10

	cout<<"Vamos a meter una pieza de 4x4 en un tablero de 5x5 que tiene ocupado la primera fila y la primera columna (deja entrar la pieza."<<endl;
	PonerColorCasilla(t.m[0][0], 1);//Iniciamos unas cuantas casillas.
	PonerColorCasilla(t.m[0][1], 5);
	PonerColorCasilla(t.m[0][2], 3);
	PonerColorCasilla(t.m[0][3], 1);
	PonerColorCasilla(t.m[0][4], 2);
	PonerColorCasilla(t.m[1][0], 2);
	PonerColorCasilla(t.m[2][0], 5);
	PonerColorCasilla(t.m[3][0], 2);
	PonerColorCasilla(t.m[4][0], 3);

	cout << "Introduce un ancho de la pieza:" << endl;
	cin >> a;
	cout << "Introduce un alto de la pieza:" << endl;
	cin >> b;
	generarPiezaConcreta(p, a, b, 2);

	if(SePuedeSituarPieza(t,p)){
		cout<<"La pieza si se puede situar :)"<<endl;
	}
	else{
		cout<<"La pieza NO se puede situar en el tablero. :("<<endl;
	}


}

void PruebaEstaFilaLlena(){
	cout << "***PRUEBA ESTA FILA LLENA***" <<endl;
	Tablero t;
	int numFila,a;
	IniciarTablero(t, 10);

	cout<<"Introduce la fila que quieres llenar: "<<endl;
	cin>>a;
	for(int i=0; i< obtenerTamanio(t) ; i++){
		PonerColorCasilla(t.m[a][i],2);//Ponemos el color 2 para usar este ejemplo.
	}

	cout<<"Introduce que fila quieres comprobar si esta llena: "<<endl;
	cin>>numFila;

	if(estaFilaLlena(t,numFila)){
		cout<<"La fila si esta llena :("<<endl;
	}
	else{
		cout<<"La fila no esta llena :)"<<endl;
	}

}

void PruebaVaciarFila(){
	cout << "***PRUEBA VACIAR FILA***" <<endl;
	Tablero t;
	int numFila;
	IniciarTablero(t,10);

	cout<<"Introduce el numero de la fila que quieres llenar: "<<endl;
	cin>>numFila;

	for(int j=0; j < t.tamano ; j++){
		PonerColorCasilla(t.m[numFila][j], 2 );
	}

	mostrarTablero(t);

	cout<<"Borrando fila indicada: "<<endl;
	VaciarFila(t,numFila);
	mostrarTablero(t);
	cout<<"La fila se ha borrado correctamente :)"<<endl;

}

void pruebaCualquierFilaLlena(){
	cout << "***PRUEBA CUALQUIER FILA LLENA***" <<endl;
	Tablero t;
	int a;
	IniciarTablero(t, 10);
	for(int j=0 ; j < 3 ; j++){
		cout << "Introduce la fila que quieres llenar: " << endl;
		cin >> a;
		for (int i = 0; i < obtenerTamanio(t); i++) {
			PonerColorCasilla(t.m[a][i], 2);//Ponemos el color 2 para usar este ejemplo.
		}
	}
	mostrarTablero(t);

	if(cualquierFilaLlena(t)){
		cout<<"Hay al menos una fila llena :)"<<endl;
	}
	else{
		cout<<"No hay filas llenas :("<<endl;
	}
}

void pruebaVaciarTodasFilasLlenas(){
	cout << "***PRUEBA VACIAR TODAS LAS FILAS LLENAS***" <<endl;
	Tablero t;

	int a;
	IniciarTablero(t, 10);

	PonerColorCasilla(t.m[2][3],4);
	PonerColorCasilla(t.m[2][5],1);
	PonerColorCasilla(t.m[7][3],3);
	PonerColorCasilla(t.m[4][2],5);
	PonerColorCasilla(t.m[2][7],6);
	PonerColorCasilla(t.m[1][0],3);
	PonerColorCasilla(t.m[6][3],4);

	for(int j=0 ; j < 3 ; j++){
		cout << "Introduce la fila que quieres llenar: " << endl;
		cin >> a;
		for (int i = 0; i < obtenerTamanio(t); i++) {
			PonerColorCasilla(t.m[a][i], 2);//Ponemos el color 2 para usar este ejemplo.
		}
	}
	mostrarTablero(t);
	cout<<endl;

	VaciarTodasFilasLlenas(t);
	mostrarTablero(t);
	cout<<"Se han eliminado las filas llenas."<<endl;


}

void pruebaObtenerTamanioTablero(){
	cout << "***PRUEBA OBTENER TAMAÑO TABLERO***" <<endl;
	Tablero t;
	int tam;

	cout<<"Introduce un tamanio:"<<endl;
	cin>>tam;

	IniciarTablero(t,tam);

	mostrarTablero(t);

	if(obtenerTamanio(t) == tam){
		cout<<"El tamaño del tablero es: "<< tam <<endl;
	}

}

void pruebasTablero(){
	pruebaIniciarTablero();
	pruebaMostrarTablero();
	pruebaSePuedeSituarPiezaZonaConcreta();
	pruebaSePuedeSituarPieza();
	PruebaEstaFilaLlena();
	PruebaVaciarFila();
	pruebaCualquierFilaLlena();
	pruebaVaciarTodasFilasLlenas();
	pruebaObtenerTamanioTablero();
}













