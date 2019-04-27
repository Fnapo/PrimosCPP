/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
  * File:   main.cpp
  * Author: fran_
  *
  * Created on 24 de marzo de 2019, 11:55
  */

#include "headers/Acciones.hpp"
#include "headers/Prompt.hpp"
#include "headers/WConsola.hpp"

using namespace std;

/*
 *
 */
int main() {
	primosCPP primo;
	Prompt comando, primero;
	int exterior = 0;

	WConsola::enlazarConsola();
	cout << "Espera unos minutos ..." << endl;
	if (exterior) {
		primo.leerFicheroNoFormateado();
	}
	else {
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
		}
		else if (primero == "factor") {
			accionCalcularFactor(primo);
		}
		else if ("doble" == primero) {
			accionFactorDoble(primo);
		}
		else if (primero == "primer") {
			accionPrimerPrimorial(primo);
		}
		else if (primero == "quit" || primero == "salir") {
			cout << "Hasta luego ... Lucas ...\n\n";
			system("pause");
			break;
		}
		else {
			cout << "Comando desconocido ... \nEntra ayuda para ver los comandos.\n\n";
			WConsola::alarma();
		}
	}

	return 0;
}
