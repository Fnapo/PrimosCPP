/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iomanip>
#include <iostream>

#include "../headers/Acciones.hpp"
#include "../headers/Macros.h"
#include "../headers/Macros.hpp"

using namespace std;

string noValida = "Entrada no válida ...";

void accionAyuda() {
	cout << "help | ayuda : Muestra la presente pantalla." << endl;
	cout << "factor : Calcula el factor de un número.\n";
	cout << "doble : Encuentra el factor de dos números.\n";
	cout << "primer : Halla un primo con factor mayor que un decimal.\n";
	cout << "quit | salir : Sale del programa.\n\n";
}

void accionFactorDoble(primosCPP& primo) {
	int numero, numero2, maximo, error;
	double valor;
	char cadena[101];

	cout << "Escribe dos números ... " << endl;
	snprintf(cadena, 101, "Primer número (Entre 1 y %i): ", primo.maximoPrimo());
	cout << cadena;
	error = !leerInt(&numero);
	if (error || numero < 1 || numero > primo.maximoPrimo()) {
		cout << noValida << "\n\n";

		return;
	}
	snprintf(cadena, 101, "Segundo número (Entre 1 y %i): ", primo.maximoPrimo());
	cout << cadena;
	error = !leerInt(&numero2);
	if (error || numero2 < 1 || numero2 > primo.maximoPrimo()) {
		cout << noValida << "\n\n";

		return;
	}
	maximo = maxT(numero, numero2);
	valor = numero * primo.hallarFactor(numero) + numero2 * primo.hallarFactor(numero2);
	snprintf(cadena, 101, "El factor para %i y %i es %g (%.2lf)\n\n", numero, numero2, valor / maximo, valor);
	cout << cadena;
}

void accionCalcularFactor(primosCPP& primo) {
	int numero, error;
	double factor;
	char cadena[101];

	snprintf(cadena, 101, "Escribe un número (Entre 1 y %i): ", primo.maximoPrimo());
	cout << cadena;
	error = !leerInt(&numero);
	if (error || numero < 1 || numero > primo.maximoPrimo()) {
		cout << noValida << "\n\n";

		return;
	}
	factor = primo.hallarFactor(numero);
	snprintf(cadena, 101, "El factor para %i es %g (% .2f)\n\n", numero, factor, factor * numero);
	cout << cadena;
}

void accionPrimerPrimorial(primosCPP& primo) {
	double por100, factor;
	int numero, error;
	char cadena[101];

	snprintf(cadena, 101, "Escribe un factor (Entre %g y %g): ", MIN_FACTOR, MAX_FACTOR);
	cout << cadena;
	error = !leerDouble(&por100);
	if (error || por100 < MIN_FACTOR || por100 > MAX_FACTOR) {
		cout << noValida << "\n\n";

		return;
	}
	if (primo.buscarPrimerPrimorial(por100, numero)) {
		factor = primo.hallarFactor(numero);
		snprintf(cadena, 101, "El primo con el factor %g (%g) es: %i (%.2f).\n\n", por100, factor,
			numero, factor * numero);
		cout << cadena;
	} else {
		snprintf(cadena, 101, "Primo no hallado con el factor %g.\n\n", por100);
		cout << cadena;
	}
}
