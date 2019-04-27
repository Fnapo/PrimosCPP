
#include <iostream>

#include "AccionesCPP.hpp"
#include "Lector.h"
#include "Macros.hpp"
#include "Prompt.hpp"
#include "WConsola.hpp"

using namespace std;

primosCPP AccionesCPP::primo;

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
		primo.leerFicheroNoFormateado();
	} else {
		primo.leerFicheroFormateado();
	}
	cout << primo[122] << endl;
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

	cout << noValida;
}

void AccionesCPP::accionAyuda() {
	cout << "help | ayuda : Muestra la presente pantalla." << endl;
	cout << "factor : Calcula el factor de un número.\n";
	cout << "doble : Encuentra el factor de dos números.\n";
	cout << "primer : Halla un primo con factor mayor que un decimal.\n";
	cout << "quit | salir : Sale del programa.\n\n";
}

void AccionesCPP::accionFactorDoble() {
	int numero, numero2, maximo, error;
	double valor;
	char cadena[101];

	cout << "Escribe dos números ... " << endl;
	snprintf(cadena, 101, "Primer número (Entre 1 y %i): ", primo.maximoPrimo());
	cout << cadena;
	error = !leerInt(&numero);
	if (error || numero < 1 || numero > primo.maximoPrimo()) {
		verAviso();

		return;
	}
	snprintf(cadena, 101, "Segundo número (Entre 1 y %i): ", primo.maximoPrimo());
	cout << cadena;
	error = !leerInt(&numero2);
	if (error || numero2 < 1 || numero2 > primo.maximoPrimo()) {
		verAviso();

		return;
	}
	maximo = maxT(numero, numero2);
	valor = numero * primo.hallarFactor(numero) + numero2 * primo.hallarFactor(numero2);
	snprintf(cadena, 101, "El factor para %i y %i es %g (%.2lf)\n\n", numero, numero2, valor / maximo, valor);
	cout << cadena;
}

void AccionesCPP::accionCalcularFactor() {
	int numero, error;
	double factor;
	char cadena[101];

	snprintf(cadena, 101, "Escribe un número (Entre 1 y %i): ", primo.maximoPrimo());
	cout << cadena;
	error = !leerInt(&numero);
	if (error || numero < 1 || numero > primo.maximoPrimo()) {
		verAviso();

		return;
	}
	factor = primo.hallarFactor(numero);
	snprintf(cadena, 101, "El factor para %i es %g (% .2f)\n\n", numero, factor, factor * numero);
	cout << cadena;
}

void AccionesCPP::accionPrimerPrimorial() {
	double por100, factor;
	int numero, error;
	char cadena[101];

	snprintf(cadena, 101, "Escribe un factor (Entre %g y %g): ", MIN_FACTOR, MAX_FACTOR);
	cout << cadena;
	error = !leerDouble(&por100);
	if (error || por100 < MIN_FACTOR || por100 > MAX_FACTOR) {
		verAviso();

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
