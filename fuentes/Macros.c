/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../headers/Macros.h"
#include <stdio.h>
#include <errno.h>

int leerInt(int *numero) {
    int salida = scanf_s("%i", numero);
    while (getchar() != 10);

    return salida;
}

int leerDouble(double *numero) {
    int salida = scanf_s("%lf", numero);
    while (getchar() != 10);

    return salida;
}

