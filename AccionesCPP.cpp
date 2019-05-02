
#include <iostream>

#include "AccionesCPP.hpp"
#include "Lector.h"
#include "Macros.hpp"
#include "Prompt.hpp"
#include "WConsola.hpp"
#include "PrimosCPP.hpp"

using namespace std;

AccionesCPP::AccionesCPP() {
}

AccionesCPP::~AccionesCPP() {
}

void AccionesCPP::inicio() {
	int exterior = 0;
	Prompt comando, primero;

	WConsola::enlazarConsola();
	cout << "Espera unos minutos ..." << endl;
	if (exterior) {
		PrimosCPP::leerFicheroNoFormateado();
	} else {
		PrimosCPP::leerFicheroFormateado();
	}
	cout << PrimosCPP::verPrimo(122) << endl;
	while (1) {
		cout << "Prompt> ";
		cin >> comando;
		comando.extraer(primero);
		primero.aMin();

		if (primero == "ayuda" || primero == "help") {
			accionAyuda();
		} else if (primero == "factor") {
			accionCalcularFactor();
		} else if ("doble" == primero) {
			accionFactorDoble();
		} else if ("auto" == primero) {
			accionAutomaticaDoble();
		} else if ("aumentado" == primero) {
			accionAutomaticaDoble(1.25);
		} else if (primero == "gap") {
			accionGap();
		} else if ("total" == primero) {
			accionGap(true);
		} else if (primero == "primer") {
			accionPrimerPrimorial();
		} else if (primero == "quit" || primero == "salir") {
			cout << "Hasta luego ... Lucas ...\n\n";
			system("pause");
			break;
		} else {
			cout << "Comando desconocido ... \nEntra ayuda para ver los comandos.\n\n";
			WConsola::alarma();
		}
	}
}

void AccionesCPP::verAviso() {
	string noValida = "Entrada no válida ...\n\n";
	WConsola::alarma();

	cout << noValida;
}

void AccionesCPP::accionAyuda() {
	cout << "help | ayuda : Muestra la presente pantalla." << endl;
	cout << "factor : Calcula el factor de un primo.\n";
	cout << "doble : Encuentra el factor de dos primos.\n";
	cout << "auto : Forma automática de doble.\n";
	cout << "aumentado : Forma aumentada de auto.\n";
	cout << "gap : Calcula la diferencia media de una serie de primos.\n";
	cout << "total : Semejante a gap, pero con todos los primos anteriores.\n";
	cout << "primer : Halla un primo con factor mayor que un decimal.\n";
	cout << "quit | salir : Sale del programa.\n\n";
}

bool AccionesCPP::lecturaPrimo(int& numero, int min, int max) {
	int error;
	char cadena[101];

	snprintf(cadena, 101, "Escribe un número (Entre %i y %i): ", min, max);
	cout << cadena;
	error = !leerInt(&numero);
	if (error || !estaEntre(numero, min, PrimosCPP::maximoPrimo())) {
		verAviso();

		return false;
	}

	return true;
}

void AccionesCPP::accionFactorDoble() {
	int numero, numero2, min = 2;
	double valor;

	cout << "Escribe dos números. El primer número será ..." << endl;
	if (!lecturaPrimo(numero, min, PrimosCPP::maximoPrimo())) {
		return;
	}
	cout << "El segundo número será ..." << endl;
	if (!lecturaPrimo(numero2, min, PrimosCPP::maximoPrimo())) {
		return;
	}
	valor = PrimosCPP::logPrimorial(numero);
	valor += PrimosCPP::logPrimorial(numero2);
	verResultadoDoble(numero, numero2, valor);
}

void AccionesCPP::accionAutomaticaDoble(double aumento) {
	int numero, numero2, min = 5;
	char cadena[101];
	double valor;

	cout << "Se usan dos números. El primer número será ..." << endl;
	if (!lecturaPrimo(numero, min, PrimosCPP::maximoPrimo())) {
		return;
	}
	valor = PrimosCPP::logPrimorial(numero);	// Modifica numero.
	numero2 = (int)(aumento * sqrt(numero));
	valor += PrimosCPP::logPrimorial(numero2);
	snprintf(cadena, 101, "El segundo será: %i.\n", numero2);
	cout << cadena;
	verResultadoDoble(numero, numero2, valor);
}

void AccionesCPP::verResultadoDoble(int numero, int numero2, double valor) {
	char cadena[101];

	snprintf(cadena, 101, "El factor para %i y %i es %g (%.2lf)\n\n", numero, numero2,
		valor / maxT(numero, numero2), valor);
	cout << cadena;
}

void AccionesCPP::accionCalcularFactor() {
	int numero, min = 2;
	char cadena[101];
	double logPrimo;

	if (!lecturaPrimo(numero, min, PrimosCPP::maximoPrimo())) {
		return;
	}
	logPrimo = PrimosCPP::logPrimorial(numero);	// Modifica numero.
	snprintf(cadena, 101, "El factor para el primo %i es %g (%.2f)\n\n", numero, logPrimo / numero, logPrimo);
	cout << cadena;
}

void AccionesCPP::accionGap(bool total) {
	double media;
	int numero, cuantos, min = 101, donde;
	char cadena[101];

	if (!lecturaPrimo(numero, min, PrimosCPP::maximoPrimo())) {
		return;
	}
	donde = PrimosCPP::indice(numero);
	cuantos = (total ? donde : (int)(log(PrimosCPP::verPrimo(donde))));	// Número de diferencias de números.
	media = (PrimosCPP::verPrimo(donde) - (double)PrimosCPP::verPrimo(donde - cuantos)) / cuantos;
	snprintf(cadena, 101, "La diferencia media %s con el primo %i es: %.3f (%.3f).\n\n", total ? "total" : "",
		PrimosCPP::verPrimo(donde), media, log(PrimosCPP::verPrimo(donde)));
	cout << cadena;
}

void AccionesCPP::accionPrimerPrimorial() {
	double por100, logPrimo;
	int numero, error;
	char cadena[101];

	snprintf(cadena, 101, "Escribe un factor (Entre %g y %g): ", MIN_FACTOR, MAX_FACTOR);
	cout << cadena;
	error = !leerDouble(&por100);
	if (error || !estaEntre(por100, MIN_FACTOR, MAX_FACTOR)) {
		verAviso();

		return;
	}
	if (PrimosCPP::buscarPrimerPrimo(por100, numero)) {
		logPrimo = PrimosCPP::logPrimorial(numero);
		snprintf(cadena, 101, "El primo con el factor %g (%g) es: %i (%.2f).\n\n", por100, logPrimo / numero,
			numero, logPrimo);
		cout << cadena;
	} else {
		snprintf(cadena, 101, "Primo no hallado con el factor %g.\n\n", por100);
		cout << cadena;
	}
}
