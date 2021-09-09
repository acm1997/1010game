/*
 * TadCasilla.h
 *
 *  Created on: 28 de nov. de 2016
 *      Author: Angel Cañada y Carlos Guillen.
 */

#ifndef TADCASILLA_H_
#define TADCASILLA_H_

struct casilla{
	int numColor;
	bool vacia;
};

/*PRE:{}
 *POST:{Inicia la casilla con el color 0(ningun color) y vacia=true}
 * Complejidad:O(1)
 */
void Iniciar(casilla &c);


/*PRE:{n>=1 && n<7}
 *POST:{Asigna un numero introducido por parametros a la variable numColor y vacia se pone a false}
 * Complejidad: O(1)
 */
void PonerColorCasilla(casilla &c, int n);


/*PRE:{numColor>0 && numColor<7}
 *POST:{numColor=0 y c.vacia=true}
 * Complejidad: O(1)
 */
void VaciarCasilla(casilla &c);

/*PRE:{Casilla inicializada}
 *POST:{Nos devuelve el numero que corresponde al color de la casilla}
 * Complejidad:O(1)
 */
int ValorColorCasilla(casilla c);

/*PRE:{Casilla inicializada}
 *POST:{Nos devuelve verdadero si tiene un color asignado}
 * Complejidad:O(1)
 */
bool EstaVacia(casilla c);



#endif /* TADCASILLA_H_ */
