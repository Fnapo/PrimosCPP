/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Comandos.cpp
 * Author: fran_
 * 
 * Created on 1 de abril de 2019, 11:12
 */

#include <stddef.h>
#include <cstring>
#include <termios.h>
#include <unistd.h> //_getc
#include <minwindef.h>

#include "../headers/Prompt.hpp"
#include "../headers/Macros.hpp"

string Prompt::separadores = "\n\t\r\v ";

Prompt::Prompt() {
    cadena[0] = '\0';
}

Prompt::Prompt(const Prompt &origen) : cadena(origen.cadena) {
}

Prompt::Prompt(const char *origen) {
    copiar(origen);
}

Prompt::Prompt(const string &origen) {
    copiar(origen);
}

Prompt::~Prompt() {
    cadena.clear();
}

ostream &operator <<(ostream &out, const wchar_t car) {
    char salida;

    if (car < 256) {
        out << (char) car;
    } else {
        salida = car % 256;
        out << (char) ESPECIAL << salida;
    }

    return out;
}

bool Prompt::esEscape(char car) {
    return car == ESCAPAR;
}

bool Prompt::esEspecial(char car) {
    return car == ESPECIAL;
}

Prompt &Prompt::copiar(const string &origen, int cuantos) {
    int hechos = 0; // Número de carácteres reales.
    int donde = 0, desde = 0; // Por si hay teclas de escape.
    char aux[2 * P_LONGITUD + 1];

    while (hechos < cuantos && desde < origen.length() != '\0') {
        if (estaEntre<int>(origen[desde], 1, 26) && origen[desde] != '\t') { // Teclas de control básicas.
            ++desde;
        } else if (estaEntre<int>(origen[desde], 28, 31)) { // Teclas de control básicas.
            ++desde;
        } else if (esEscape(origen[desde])) { // 1ª tecla de escape.
            ++desde;
            if (origen[desde] == '\0') { // 2ª tecla.
                break;
            } else if (origen[desde] == '[') { // 2ª tecla.
                ++desde;
                if (origen[desde] == '[' || estaEntre(origen[desde], '1', '6')) { // Hay 4 chars. 3ª tecla.
                    ++desde;
                } else if (estaEntre(origen[desde], '1', '2')) { // Hay 5 chars. 3ª tecla.
                    ++desde;
                    if (origen[desde] == '\0') { // 4ª tecla.
                        break;
                    }
                    ++desde;
                }
            }
            if (origen[desde] == '\0') { // 3ª tecla.
                break;
            }
            ++desde;
        } else {
            if (esEspecial(origen[desde])) {
                if (origen[desde + 1] == '\0') { // Por las tecla de escape.
                    break;
                }
                aux[donde] = origen[desde];
                ++donde;
                ++desde;
            }
            aux[donde] = origen[desde];
            ++donde;
            ++desde;
            ++hechos;
        }
    }
    aux[donde] = '\0';
    cadena = aux;

    return *this;
}

int Prompt::longitud() const {

    int salida = 0;

    for (int indice = 0; indice < cadena.length(); ++indice) {
        salida += !esEspecial(cadena[indice]);
    }

    return salida;
}

inline void Prompt::alarma() {
    printf("\a");
}

//int Prompt::kbhit() {
//    int buf = 0;
//    struct termios old = {0};
//
//    fflush(stdout);
//    if (tcgetattr(0, &old) < 0)
//        perror("tcsetattr()");
//    old.c_lflag &= ~ICANON;
//    old.c_lflag &= ~ECHO;
//    old.c_cc[VMIN] = 1;
//    old.c_cc[VTIME] = 0;
//    if (tcsetattr(0, TCSANOW, &old) < 0)
//        perror("tcsetattr ICANON");
//    if (read(0, &buf, 2) < 0)
//        perror("read()");
//    old.c_lflag |= ICANON;
//    old.c_lflag |= ECHO;
//    if (tcsetattr(0, TCSADRAIN, &old) < 0)
//        perror("tcsetattr ~ICANON");
//
//    return buf;
//}

int getch() {
    int buf = 0;
    struct termios old = {0};

    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");

    return buf;
}

bool Prompt::comparar(const string &segunda) const {
    for (int indice = 0; indice <= cadena.length(); ++indice) {
        if (cadena[indice] != segunda[indice]) {
            return FALSE;
        }
    }

    return TRUE;
}

void Prompt::aMay() {
    for (int indice = 0; indice < cadena.length(); ++indice) {
        cadena[indice] = (char) toupper(cadena[indice]);
    }
}

void Prompt::aMin() {
    for (int indice = 0; indice < cadena.length(); ++indice) {
        cadena[indice] = (char) tolower(cadena[indice]);
    }
}

wchar_t Prompt::operator [](int indice) const {
    wchar_t salida = 0;
    int hechos = -1, max = longitud();

    if (indice < 0 || indice >= max) {
        return '\0';
    }
    for (int donde = 0; donde < cadena.length(); ++donde) {
        hechos += !esEspecial(cadena[donde]);
        if (hechos == indice) {
            if (donde) {
                if (esEspecial(cadena[donde - 1])) {
                    salida = I_ESPACIAL * 256;
                }
                salida += (unsigned char) cadena[donde];
            }
            break;
        }
    }

    return salida;
}

void Prompt::extraer(Prompt &destino) {
    int cuantos;

    trim();
    for (cuantos = 0; cuantos < cadena.length(); ++cuantos) {
        if (esSeparador(cadena[cuantos])) {
            break;
        }
    }
    destino = cadena.substr(0, cuantos);
    cadena.erase(0, cuantos);
}

void Prompt::rTrim() {
    int cuantos = cadena.length();

    while (cuantos > 0 && esSeparador(cadena[cuantos - 1])) {
        --cuantos;
    }
    cadena.resize(cuantos);
}

void Prompt::lTrim() {
    int cuantos = 0;

    while (esSeparador(cadena[cuantos])) {
        ++cuantos;
    }
    cadena.erase(0, cuantos);
}

void Prompt::trim() {
    rTrim();
    lTrim();
}

void Prompt::copiarN(Prompt& destino, int cuantos) const {
    int reales, hechos = 0;

    destino.cadena.clear();
    if (cuantos < 1) {
        return;
    }
    for (reales = 0; reales < cadena.length(); ++reales) {
        hechos += !esEspecial(cadena[reales]);
        if (hechos == cuantos) {
            ++reales;
            break;
        }
    }
    destino.cadena = cadena.substr(0, reales);
}

void Prompt::eliminarN(int cuantos) {
    int reales, hechos = 0;

    if (cuantos < 1) {
        return;
    }
    for (reales = 0; reales < cadena.length(); ++reales) {
        hechos += !esEspecial(cadena[reales]);
        if (hechos == cuantos) {
            ++reales;
            break;
        }
    }
    cadena.erase(0, reales);
}

bool Prompt::esSeparador(char caracter) {
    for (int indice = 0; indice < separadores.length(); ++indice) {
        if ((caracter == separadores[indice])) {
            return TRUE;
        }
    }

    return FALSE;
}

int Prompt::leer(istream & in) {
    string aux;

    getline(in, aux);

    *this = aux;

    //    int itecla;
    //    char tecla;
    //    bool salida = 0;
    //
    //    longitud = 0;
    //    cadena[0] = '\0';
    //    while (!salida) {
    //        itecla = kbhit();
    //        if (itecla > 255) {
    //            itecla = kbhit();
    //        } else {
    //            tecla = (char) itecla;
    //            if (!estaEntre<char>(tecla, '\0', 31) && (tecla != DELETER)) {
    //                if (longitud < P_LONGITUD) {
    //                    cout << tecla;
    //                    cadena[longitud++] = tecla;
    //                    cadena[longitud] = '\0';
    //                }
    //            } else {
    //                switch (tecla) {
    //                case '\n':
    //                    salida = 1;
    //                    break;
    //                case '\b':
    //                case DELETER:
    //                    if (longitud) {
    //                        cadena[--longitud] = '\0';
    //                        cout << '\b';
    //                        cout << ' ';
    //                        cout << '\b';
    //                    }
    //                    break;
    //                }
    //            }
    //        }
    //    }
    //    cout << endl;

    return cadena.length();
}
