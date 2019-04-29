/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
  * File:   primosCPP.hpp
  * Author: fran_
  *
  * Created on 24 de marzo de 2019, 12:00
  */

#ifndef PRIMOSCPP_HPP
#define PRIMOSCPP_HPP

  /*
	  Clase static de los números primos.
  */

#define MAX_PRIMOS 600000
#define COLUMNAS_PRIMOS 4
#define PRIMOS_FICHERO "primos.txt"
#define PRIMES_FILE "primes1.txt"

class PrimosCPP {
public:
	/**
	 *
	 * Lee los números primos de un fichero preparado.
	 *
	 */
	static void leerFicheroFormateado();

	/**
	 *
	 *	Lee de un fichero externo los números primos.
	 *
	 */
	static void leerFicheroNoFormateado();

	/**
	 *
	 * Busca el primo a partir del cual el
	 * factor es mayor que pedido (Entre MIN_FACTOR y MAX_FACTOR).
	 * Devuelve 1 si lo encuentra.
	 *
	 * @param double pedido
	 * @param int &primo
	 * @return int
	 *
	 */
	static int buscarPrimerPrimo(double pedido, int& primo);

	/**
	 *
	 * Calcula el ln(primorial).
	 *
	 * @param int &primo
	 * @return double
	 *
	 */
	static double logPrimorial(int& primo);

	/**
	 *
	 * Devuelve el mayor primo almacenado.
	 *
	 * @return int
	 *
	 */
	static inline int maximoPrimo() {
		return primos[cuantosPrimos - 1];
	}

	/*

		Muestra el primo en la posición indice

		@return int

	*/
	static int verPrimo(int indice);

private:
	PrimosCPP();
	virtual ~PrimosCPP();

	static int primos[MAX_PRIMOS];
	static int cuantosPrimos;

	/**
	 *
	 * Inicializa a cero los elementos de primos.
	 *
	 */
	static void inicializar();

	/**
	 *
	 * Encuentra los primeros números primos. Hasta el 11.
	 *
	 */
	static void primerosPrimos();

	/**
	 *
	 * Guarda los números primos en un fichero.
	 *
	 */
	static void guardarEnFichero();
};

#endif /* PRIMOSCPP_HPP */
