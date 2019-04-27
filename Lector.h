/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Macros.h
 * Author: fran_
 *
 * Created on 17 de febrero de 2019, 20:48
 */

#ifndef MACROS_H
#define MACROS_H

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * 
     * Lee numero del teclado.
     * Devuelve 0 si hay error.
     * 
     * @param int numero
     * @return int
     * 
     */
    int leerInt(int *numero);

    /**
     * 
     * Lee numero del teclado.
     * Devuelve 0 si hay error.
     * 
     * @param double numero
     * @return int
     * 
     */
    int leerDouble(double *numero);

#ifdef __cplusplus
}
#endif

#endif /* MACROS_H */
