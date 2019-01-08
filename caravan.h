/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: <your class name here>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * File:			caravan.h
 * Author:			Peter Bauer
 * Due Date:		#due#
 * ----------------------------------------------------------
 * Description:
 * <Add description>
 * ----------------------------------------------------------
 */
#ifndef CARAVAN_H
#define CARAVAN_H

#include "pack_animal.h"

typedef struct NodeImplementation* Node;

/**
* Initialisiert eine Karawane. D. h., dass es alle in der Karawane befindlichen Tiere aus der
* Karawane entfernt und die Karawane als leer kennzeichnet.
* @param caravan Die Karawane, welche initialisiert werden soll.
*/
Caravan new_caravan();

/**
* @return Die Länge einer Karawane, d.h., die Anzahl der Tiere in der Karawane.
*/
int get_length(Caravan caravan);

/**
* Entfern alle Tiere aus einer Karawane und löscht die Karawane.
*/
void delete_caravan(Caravan caravan);

/**
* Fügt ein Packtier zu einer Karawane hinzu.
*/
void add_pack_animal(Caravan caravan, PackAnimal animal);

/**
* Entfernt ein Packtier aus einer Karawane.
*/
void remove_pack_animal(Caravan caravan, PackAnimal animal);

/**
* @return Die Geschwindigkeit einer Karawane. Diese richtet sich nach der Geschwindigkeit des
* langsamsten Tiers in der Karawane.
*/
int get_caravan_speed(Caravan caravan);

/**
* @return Die Gesamtanzahl der Ballen einer Karawane.
*/
int get_caravan_load(Caravan caravan);

/**
* Entl&auml;dt die gesamte Karawane. D.h. es wird jedes Tier in der Karawane von seinen Ballen
* befreit.
*/
void unload(Caravan caravan);

/**
* Verteilt die Last der Ballen so auf die einzelnen Tiere, dass die Geschwindigkeit der Karawane
* maximal ist.
*/
void optimize_load(Caravan caravan);

#endif
