/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
  * File:   Prompt.hpp
  * Author: fran_
  *
  * Created on 1 de abril de 2019, 11:12
  */

#ifndef PROMPT_HPP
#define PROMPT_HPP

#include <iostream>
#include <string>

#define P_LONGITUD 50
#define MAX_CIFRAS 12
#define MAX_DECIMALES 8
#define DELETER 127  // Tecla del.
#define ESPECIAL -61 // Para char especiales
#define I_ESPACIAL 195
#define ESCAPAR 27  // Tecla escape.

typedef struct {
	unsigned char Signo : 1;
	unsigned char Punto : 1;
} NO_NUM;

/*
 * Clase para trabajar con cadenas cortas (P_LONGITUD carácteres como máximo).
 */

using namespace std;

class Prompt {
public:
	Prompt();
	Prompt(const Prompt& origen);
	Prompt(const char* origen);
	Prompt(const string& origen);

	virtual ~Prompt();

	/**
	 *
	 * @param (char) car
	 * @return (bool) Indica si car es un separador o no.
	 *
	 */
	static bool esSeparador(char car);

	/**
	 *
	 * @param (char) car
	 * @return (bool) Indice si car es del tipo especial.
	 */
	static bool esEspecial(char car);

	/**
	 *
	 * @param (char) car
	 * @return (bool) Indice si car es del tipo escape.
	 */
	static bool esEscape(char car);

	/**
	 *
	 * Devuelve los separadores habituales.
	 * @return (Prompt)
	 *
	 */
	static const string& Separadores() {
		return separadores;
	}

	/**
	 *
	 * Pasa a mayúsculas o a minúsculas.
	 *
	 */
	void aMay();
	void aMin();

	/**
	 *
	 * Tras hacer un trim() actúa como una función strtok con los
	 * separadores habituales, sólo extrae una parte.
	 * @param (Prompt) destino
	 *
	 */
	void extraer(Prompt& destino);

	/**
	 *
	 * @param (int) indice
	 * @return (char) wide char
	 *
	 */
	wchar_t operator[](int indice) const;

	/**
	 *
	 * Comparación estricta de 2 Prompts.
	 * @param (const Prompt&) segunda
	 * @return (bool)
	 *
	 */
	inline bool operator==(const Prompt& segunda) const {
		return !cadena.compare(segunda.cadena);
	}

	inline bool operator!=(const Prompt& segunda) const {
		return cadena.compare(segunda.cadena);
	}

	inline bool operator==(const char* segunda) const {
		return comparar(string(segunda));
	}

	inline bool operator!=(const char* segunda) const {
		return !((*this) == string(segunda));
	}

	inline bool operator==(const string & segunda) const {
		return comparar(segunda);
	}

	inline bool operator!=(const string & segunda) const {
		return !((*this) == segunda);
	}

	//    operator const string &() {
	//        return cadena;
	//    }

	friend ostream& operator<<(ostream & out, const Prompt & origen) {
		out << origen.cadena;

		return out;
	}

	friend bool operator==(const string & uno, const Prompt & dos) {
		return dos.comparar(uno);
	}

	friend bool operator!=(const string & uno, const Prompt & dos) {
		return !(dos == uno);
	}

	inline Prompt& operator=(const Prompt & origen) {
		cadena = origen.cadena;

		return *this;
	}

	inline Prompt& operator=(const char* origen) {
		return copiar(string(origen));
	}

	inline Prompt& operator=(const string & origen) {
		return copiar(origen);
	}

	/**
	 *
	 * Copia en destino los primeros cuantos chars.
	 * @param (Prompt &) destino
	 * @param (int) cuantos
	 *
	 */
	void copiarN(Prompt & destino, int cuantos) const;

	/**
	 *
	 * Elimina los primeros cuantos chars.
	 * @param (int) cuantos
	 *
	 */
	void eliminarN(int cuantos);

	/**
	 *
	 * Esta función y el operador >> están pensados para stdin(cin) o para
	 * ficheros con longitud de lí­nea menor que P_LONGITUD.
	 * leer devuelve el número de bytes leí­dos.
	 * @param (istream &) in
	 * @return (int)
	 *
	 */
	int leer(istream & in);

	friend istream& operator>>(istream & in, Prompt & salida) {
		salida.leer(in);

		return in;
	}

	/**
	 *
	 * Las funciones tí­picas de cadenas:
	 * trim, lTrim, rTrim.
	 *
	 */
	void trim();
	void lTrim();
	void rTrim();

	int longitud() const; // Número de chars almacenados.

private:
	string cadena;

	/**
	 *
	 * Copia como máximo cuantos chars.
	 * @param (const string &) origen
	 * @param (int) cuantos
	 * @return (Prompt &) el propio objeto
	 *
	 */
	Prompt& copiar(const string & origen, int cuantos = P_LONGITUD);

	bool comparar(const string & segunda) const;
	static string separadores;
};

#endif /* PROMPT_HPP */
