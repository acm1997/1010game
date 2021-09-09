/*
 * PruebasCasilla.cpp
 *
 *  Created on: 14 ene. 2017
 *      Author: carlos
 */

#include "PruebasCasilla.h"

void pruebaIniciarCasilla(){
	cout << "***PRUEBA INICIAR CASILLA: ***" <<endl;
	casilla c;
	Iniciar(c);
	cout<<"El color de la casilla es: "<<c.numColor<<endl;
	cout<<"¿Está la casilla vacía? "<<endl;
	if(c.vacia==true){
		cout<<"Sí, está vacía."<<endl;
	}
	else
		cout<<"La casilla no está vacía."<<endl;


	cout<<endl;
}

void PruebaPonerColorCasilla(){
	cout << "***PRUEBA PONER COLOR CASILLA: ***" <<endl;
	int color;
	casilla c;
	cout<<"Introduce el numero del color que quieres poner en la casilla: "<<endl;
	cin>>color;
	PonerColorCasilla(c,color);

	cout<<"El numero del color de la casilla es : "<< color <<endl;


	cout<<endl;

}

void PruebaVaciarCasilla(){
	cout << "***PRUEBA VACIAR CASILLA: ***" <<endl;
	casilla c;
	cout<<"Llenamos la casilla con el color 3."<<endl;
	PonerColorCasilla(c,3);
	cout<<"Vaciando casilla......."<<endl;
	VaciarCasilla(c);
	if(ValorColorCasilla(c)==0){
		cout<<"Se ha vaciado correctamente la casilla."<<endl;
	}
	else
		cout<<"La casilla no se ha vaciado."<<endl;

}
void PruebaValorColorCasilla(){
	cout << "***PRUEBA VALOR CASILLA: ***" <<endl;
	casilla c;
	int color;
	Iniciar(c);
	cout<<"Introduce el numero del color que quieres poner en la casilla: "<<endl;
	cin>>color;
	PonerColorCasilla(c,color);
	cout<<"El el color de la casilla es : "<< ValorColorCasilla(c)<<endl;
	cout<<endl;

}

void PruebaEstaVacia(){
	int color;
	cout << "***PRUEBA ESTA VACIA: ***" <<endl;
	casilla c;
	Iniciar(c);
	cout<<"Primer caso"<<endl;
	if(EstaVacia(c)){
		cout<<"La casilla está vacía."<< endl;
	}
	else
		cout<<"La casilla no está vacía."<<endl;

	cout<<"Segundo caso"<<endl;
	cout<<"Introduce un color: "<<endl;
	cin>>color;
	PonerColorCasilla(c,color);
	if(EstaVacia(c)){
		cout<<"La casilla está vacía."<< endl;
	}
	else
		cout<<"La casilla no está vacía."<<endl;

}
void pruebasCasilla(){
	pruebaIniciarCasilla();
	PruebaPonerColorCasilla();
	PruebaVaciarCasilla();
	PruebaValorColorCasilla();
	PruebaEstaVacia();
}
