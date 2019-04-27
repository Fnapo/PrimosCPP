/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Acciones.hpp
 * Author: fran_
 *
 * Created on 28 de marzo de 2019, 19:21
 */

#ifndef ACCIONES_HPP
#define ACCIONES_HPP

#include "PrimosCPP.hpp"

#define MIN_FACTOR 0.3
#define MAX_FACTOR 1.0

/**
 * 
 * Presenta la ventana de Ayuda.
 * 
 */
void accionAyuda();

/**
 * 
 * Calcula el factor de un numero.
 * 
 * @param {primosCPP} primo
 * 
 */
void accionCalcularFactor(primosCPP &primo);

/**
 * 
 * Acción de buscar el primorial a partir del cual el
 * factor es mayor que un double (Entre 0.3 y 1).
 * 
 * @param {primosCPP} primo
 * 
 */
void accionPrimerPrimorial(primosCPP &primo);

/**
 * 
 * Calcula el factor de 2 primos.
 * 
 * @param {primosCPP} primo
 * 
 */
void accionFactorDoble(primosCPP &primo);

#endif /* ACCIONES_HPP */

