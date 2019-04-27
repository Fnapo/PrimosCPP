
#pragma once

#include "PrimosCPP.hpp"

#define MIN_FACTOR 0.3
#define MAX_FACTOR 1.0

/*
	Clase static para trabajar con los números primos.
*/

class AccionesCPP {
public:
	static void inicio();

private:
	static primosCPP primo;

	AccionesCPP();
	virtual ~AccionesCPP();

	/**
	 *
	 * Presenta la ventana de Ayuda.
	 *
	 */
	static void accionAyuda();

	/**
	 *
	 * Calcula el factor de un numero.
	 *
	 * @param primosCPP primo
	 *
	 */
	static void accionCalcularFactor();

	/**
	 *
	 * Acción de buscar el primorial a partir del cual el
	 * factor es mayor que un double (Entre 0.3 y 1).
	 *
	 * @param primosCPP primo
	 *
	 */
	static void accionPrimerPrimorial();

	/**
	 *
	 * Calcula el factor de 2 primos.
	 *
	 * @param primosCPP primo
	 *
	 */
	static void accionFactorDoble();

	/**
		Presenta un aviso.
	*/
	static void verAviso();
};
