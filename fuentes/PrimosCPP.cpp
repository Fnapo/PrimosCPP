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
 */

#include <iostream>
#include <math.h>
#include <fstream>
#include "../headers/Macros.h"
#include "../headers/Macros.hpp"

#include "../headers/PrimosCPP.hpp"

using namespace std;

int primosCPP::cuantosPCPP = 0;
int primosCPP::cuantosPrimos = 0;
int primosCPP::primos[MAX_PRIMOS];

primosCPP::primosCPP() {
    try {
        if (cuantosPCPP > 0) {
            throw 1;
        }
        ++cuantosPCPP;
        inicializar();
        primerosPrimos();
    }    catch (int) {
        cout << "Solamente puede existir una instancia de primosCPP." << endl;

        exit(1);
    }
}

primosCPP::~primosCPP() {
}

void primosCPP::inicializar() {
    for (int indice = 0; indice < MAX_PRIMOS; ++indice) {
        primos[indice] = 0;
    }
}

void primosCPP::primerosPrimos() {
    primos[cuantosPrimos++] = 2;
    primos[cuantosPrimos++] = 3;
    primos[cuantosPrimos++] = 5;
    primos[cuantosPrimos++] = 7;
    primos[cuantosPrimos++] = 11;
}

int primosCPP::indicePrimo(int primo) {
    int salida = -1;

    if (primo >= 2) {
        for (salida = 0; salida < cuantosPrimos - 1; ++salida) {
            if (primos[salida] == primo) {
                break;
            } else if (primos[salida] > primo) {
                --salida;
                break;
            }
        }
    }

    return salida;
}

double primosCPP::logPrimorial(int primo) {
    int anteriores, donde = indicePrimo(primo);
    double salida = 0;

    for (anteriores = 0; anteriores <= donde; ++anteriores) {
        salida += log(primos[anteriores]);
    }

    return salida;
}

double primosCPP::hallarFactor(int primo) {
    return logPrimorial(primo) / (primo < 2 ? 1 : primo);
}

int primosCPP::buscarPrimerPrimorial(double pedido, int &primo) {
    int indice;
    int salida = 0;
    double valor = 0;

    primo = 0;
    for (indice = 0; indice < cuantosPrimos - 1; ++indice) {
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

void primosCPP::leerFicheroNoFormateado() {
    ifstream ficheroEntrada;
    int valor, leidos = 0;

    ficheroEntrada.open(PRIMES_FILE);
    if (ficheroEntrada.is_open()) { //Hay datos guardados.
        do {
            ficheroEntrada >> valor;
            if (valor == 0) {
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
    } else {
        primerosPrimos();
    }
    guardarEnFichero();
}

void primosCPP::leerFicheroFormateado() {
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

void primosCPP::guardarEnFichero() {
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

const int primosCPP::operator[](int indice) const {
    ajustaEntre(indice, 0, cuantosPrimos - 1);

    return primos[indice];
}