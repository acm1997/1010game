/*
 * PruebasTadJuego.cpp
 *
 *  Created on: 17 de ene. de 2017
 *      Author: usuario
 */

#include "PruebasTadJuego.h"
#include <iostream>
using namespace std;

void pruebaIniciarJuego(){
	Juego ju;
	ju.maxPuntuacion=100;
	ju.numPieza=1;
	int n;
	cout<<"INICIO PRUEBA INICIAR JUEGO: "<<endl;
	cout<<"Introduce el tamaño del tablero: "<<endl;
	cin>>n;

	entornoGuardarConfiguracion(n,ju.maxPuntuacion,ju.numPieza);

	if(entornoCargarConfiguracion(n,ju.maxPuntuacion,ju.numPieza)){
		IniciarTablero(ju.t, n);
		entornoIniciar(n);
	}
	else{
		cout<<"Error en el inicio del juego."<<endl;
	}

	cout<<"Fin prueba iniciar juego."<<endl;
	cout<<endl;
}
void pruebaJugar(){
	Juego ju;
	cout<<"INICIO PRUEBA JUGAR: "<<endl;

	cout<<"Iniciando juego..: "<<endl;

	if(iniciarJuego(ju)){
			jugar(ju);
			terminar(ju);
		}
	else{
			cout<<"Error en el modulo jugar."<<endl;
		}
	cout<<"La prueba se ha realizado correctamente."<<endl;

	cout<<"Fin prueba jugar."<<endl;
	cout<<endl;

}

void pruebaTerminar(){
	Juego ju;
	cout<<"Coloca piezas hasta que pierdas la partida."<<endl;

	if(iniciarJuego(ju)){
			jugar(ju);
			terminar(ju);
			}
	else{
		cout<<"El juego no se ha terminado como se debe."<<endl;
	}
	cout<<"El juego se ha terminado correctamente."<<endl;
}

void pruebasTadJuego(){

	int a;
	cout<<"Numero 1-> Prueba iniciar juego."<<endl;
	cout<<"Numero 2-> Prueba jugar."<<endl;
	cout<<"Numero 3-> Prueba terminar."<<endl;
	cout<<"Introduce un numero del 1 al 3: "<<endl;
	cin>>a;


	if(a==1){
		pruebaIniciarJuego();
	}
	else{
		if(a==2){
			pruebaJugar();
		}
		else{
			pruebaTerminar();
		}
	}
}



