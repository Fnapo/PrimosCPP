/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
  * File:   primosCPP.cpp
  * Author: fran_
  *
  * Created on 24 de marzo de 2019, 12:00
  *
  */

#include <iostream>
#include <math.h>
#include <fstream>

#include "Lector.h"
#include "Macros.hpp"
#include "PrimosCPP.hpp"

using namespace std;

int PrimosCPP::cuantosPrimos = 0;
int PrimosCPP::primos[MAX_PRIMOS];

PrimosCPP::PrimosCPP() {
}

PrimosCPP::~PrimosCPP() {
}

void PrimosCPP::inicializar() {
	for (int indice = 0; indice < MAX_PRIMOS; ++indice) {
		primos[indice] = 0;
	}
}

void PrimosCPP::primerosPrimos() {
	primos[cuantosPrimos++] = 2;
	primos[cuantosPrimos++] = 3;
	primos[cuantosPrimos++] = 5;
	primos[cuantosPrimos++] = 7;
	primos[cuantosPrimos++] = 11;
}

double PrimosCPP::logPrimorial(int& numero) {
	int anteriores, aux = numero;
	double salida = 0;

	if (!estaEntre(numero, 2, maximoPrimo())) {
		return 0;
	}

	numero = 1;
	for (anteriores = 0; anteriores < cuantosPrimos; ++anteriores) {
		if (primos[anteriores] > aux) {
			break;
		}
		numero = primos[anteriores];
		salida += log(numero);
	}

	return salida;
}

int PrimosCPP::buscarPrimerPrimo(double pedido, int& primo) {
	int indice;
	int salida = 0;
	double valor = 0;

	primo = 0;
	for (indice = 0; indice < cuantosPrimos; ++indice) {
		valor += log(primos[indice]);
		if (valor >= primos[indice] * pedido) {
			if (salida == 0) {
				primo = primos[indice];
			}
			salida = 1;
		} else {
			salida = 0;
		}
	}

	return salida;
}

void PrimosCPP::leerFicheroNoFormateado() {
	ifstream ficheroEntrada;
	int valor, leidos = 0;

	primerosPrimos();
	ficheroEntrada.open(PRIMES_FILE);
	if (ficheroEntrada.is_open()) { //Hay datos guardados.
		do {
			ficheroEntrada >> valor;
			if (valor < 2) {
				break;
			}
			primos[leidos++] = valor;
			if (leidos == MAX_PRIMOS) {
				break;
			}
		} while (1);
	}
	ficheroEntrada.close();
	if (leidos >= cuantosPrimos) {
		cuantosPrimos = leidos;
	}
	guardarEnFichero();
}

void PrimosCPP::leerFicheroFormateado() {
	ifstream ficheroEntrada;

	ficheroEntrada.open(PRIMOS_FICHERO);
	if (ficheroEntrada.is_open()) { //Hay datos guardados.
		ficheroEntrada >> cuantosPrimos;
		if (estaEntre(cuantosPrimos, 1, MAX_PRIMOS)) {
			for (int indice = 0; indice < cuantosPrimos; ++indice) {
				ficheroEntrada >> primos[indice];
			}
		} else {
			cuantosPrimos = 0;
		}
	}
	ficheroEntrada.close();
	if (cuantosPrimos < 1) {
		primerosPrimos();
		guardarEnFichero();
	}
}

void PrimosCPP::guardarEnFichero() {
	ofstream ficheroSalida;
	char cadena[21];

	ficheroSalida.open(PRIMOS_FICHERO);
	snprintf(cadena, 20, "%-16i", cuantosPrimos);
	ficheroSalida << cadena << endl;
	for (int indice = 0; indice < cuantosPrimos; ++indice) {
		snprintf(cadena, 20, "%-16i", primos[indice]);
		ficheroSalida << cadena;
		if ((indice % COLUMNAS_PRIMOS) == COLUMNAS_PRIMOS - 1) {
			ficheroSalida << endl;
		}
	}
	ficheroSalida << endl;
	ficheroSalida.close();
}

int PrimosCPP::verPrimo(int indice) {
	ajustaEntre(indice, 0, cuantosPrimos - 1);

	return primos[indice];
}

int PrimosCPP::indice(int numero) {
	int salida;

	if (!estaEntre(numero, 2, maximoPrimo())) {
		return -1;
	}
	for (salida = 0; salida < cuantosPrimos; ++salida) {
		if (primos[salida] > numero) {
			return salida - 1;
		}
	}

	return cuantosPrimos - 1;
}