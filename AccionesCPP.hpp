
#pragma once

#define MIN_FACTOR 0.3
#define MAX_FACTOR 1.0

/*
	Clase static para trabajar con los n�meros primos.
*/

class AccionesCPP {
public:
	static void inicio();

private:
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
	 */
	static void accionCalcularFactor();

	/**
	 *
	 * Acci�n de buscar el primorial a partir del cual el
	 * factor es mayor que un double (Entre 0.3 y 1).
	 *
	 */
	static void accionPrimerPrimorial();

	/**
	 *
	 * Calcula el factor de 2 primos.
	 *
	 */
	static void accionFactorDoble();

	/*
	*
	* Forma autom�tica de doble.
	*
	* @param double aumento (multiplica a la ra�z).
	*
	*/
	static void accionAutomaticaDoble(double aumento = 1);

	/**
	*
	* Muestra el resultado de dos n�meros.
	*
	* @param int numero
	* @param int numero2
	*
	*/
	static void verResultadoDoble(int numero, int numero2, double valor, char* cadena);

	/*

		Calcula la diferencia media de una serie de primos.

	*/
	static void accionGap();

	/**
		Presenta un aviso.
	*/
	static void verAviso();
};
