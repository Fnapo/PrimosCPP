
#include <Windows.h>
#include <string>
#include <iostream>

#include "../headers/WConsola.hpp"

ostream& operator <<(ostream& out, const wchar_t car) {
	char salida;

	if (car < 256) {
		out << (char)car;
	} else {
		salida = car % 256;
		out << (char)ESPECIAL << salida;
	}

	return out;
}

void WConsola::alarma() {
	cout << "\a";
}

WConsola::WConsola() {
}


WConsola::~WConsola() {
}

void WConsola::enlazarConsola() {
	string local;
	int pagina = 1252, donde;

	setlocale(LC_ALL, "");
	local = setlocale(LC_ALL, NULL);
	donde = local.find('.');
	if (donde > -1) {
		local = local.substr(donde + 1);
		pagina = stoi(local);
	}
	SetConsoleCP(pagina);
	SetConsoleOutputCP(pagina);
}