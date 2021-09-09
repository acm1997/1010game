/*
 * TadPieza.h
 *
 *  Created on: 28 de nov. de 2016
 *      Author: Angel Cañada y Carlos Guillen.
 */

#ifndef TADPIEZA_H_
#define TADPIEZA_H_

struct pieza{
	int ancho;
	int alto;
	int color;
};


/*PRE:{}
 *POST:{Inicio la pieza con valores nulos}
 * Complejidad: O(1)
 */
void Iniciar(pieza &p);

/*PRE:{Pieza inicializada}
 *POST:{0<altoPieza<=4, 0<anchoPieza<=4 y 0<colorPieza<7}
 * Complejidad: O(1)
 */
void generarPieza(pieza &p);


/*PRE:{Pieza inicializada}
 *POST:{Devuelve una pieza modificada con los valores de alto, ancho y color introducidos por parametros}
 * Complejidad: O(1)
 */
void generarPiezaConcreta(pieza &p, int alto,int ancho,int color);

/*PRE:{Pieza inicializada}
 *POST:{Devuelve el alto de la pieza}
 * Complejidad:O(1)
 */
int obtenerAltoPieza (pieza p);

/*PRE:{Pieza inicializada}
 *POST:{Devuelve el ancho de la pieza}
 * Complejidad:O(1)
 */
int obtenerAnchoPieza (pieza p);

/*PRE:{Pieza inicializada}
 *POST:{Devuelve el color de la pieza}
 * Complejidad: =O(1)
 */
int obtenerColorPieza (pieza p);

/*PRE:{Pieza inicializada}
 *POST:{Rota la dimensión de la pieza}
 * Complejidad: =O(1)
 */
pieza rotarPieza(pieza &p);

#endif /* TADPIEZA_H_ */
