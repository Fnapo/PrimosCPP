/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   primosCPP.hpp
 * Author: fran_
 *
 * Created on 24 de marzo de 2019, 12:00
 */

#ifndef PRIMOSCPP_HPP
#define PRIMOSCPP_HPP

#define MAX_PRIMOS 600000
#define COLUMNAS_PRIMOS 4
#define PRIMOS_FICHERO "primos.txt"
#define PRIMES_FILE "primes1.txt"

typedef struct {
    int primo;
    double logPrimorial;
} PRIMOLOG;

class primosCPP { // Sólo existirá una instancia de esta clase.
public:
    primosCPP();
    virtual ~primosCPP();

    /**
     * 
     * Lee los números primos de un fichero preparado.
     * 
     */
    void leerFicheroFormateado();
    /**
     * 
     * Lee de un fichero externo los números primos.
     * 
     */
    void leerFicheroNoFormateado();

    /**
     * Busca el primorial a partir del cual el
     * factor es mayor que pedido (Entre MIN_FACTOR y MAX_FACTOR).
     * Devuelve 1 si lo encuentra.
     * 
     * @param double pedido
     * @param int primo
     * @param double delPrimo
     * @return int
     */
    int buscarPrimerPrimorial(double pedido, int &primo);

    /**
     * 
     * Calcula el ln(primorial).
     * 
     * @param int primo
     * @return double
     * 
     */
    double logPrimorial(int primo);

    /**
     * 
     * Calcula el cociente ln(primorial)/primo.
     * 
     * @param int primo
     * @return double
     * 
     */
    double hallarFactor(int primo);

    /**
     * 
     * Devuelve el mayor primo almacenado.
     * 
     * @return int
     * 
     */
    inline int maximoPrimo() {
        return primos[cuantosPrimos - 1];
    }

    const int operator[](int indice) const;

private:
    static int primos[MAX_PRIMOS];
    static int cuantosPrimos;
    static double maxFactor;
    static int cuantosPCPP;

    /**
     *
     * Inicializa a cero los elementos de primos.
     * 
     */
    void inicializar();

    /**
     * 
     * Encuentra los primeros números primos. Hasta el 11.
     * 
     */
    void primerosPrimos();

    /**
     * 
     * Guarda los números primos en un fichero.
     * 
     */
    void guardarEnFichero();

    /**
     * 
     * Halla el indice, por defecto,
     * dentro de los primos del número primo.
     * Devuelve -1 si primo \<= 1.
     * 
     * @param int primo
     * @return int
     * 
     */
    int indicePrimo(int primo);
};

#endif /* PRIMOSCPP_HPP */
