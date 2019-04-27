
/*
	Clase sin posibles instaciaciones.
*/

#pragma once

#ifndef ESPECIAL
#define ESPECIAL -61 // Para char especiales
#endif // !ESPECIAL

using namespace std;

ostream& operator<<(ostream& out, const wchar_t car);

class WConsola {
public:

	/**
	 *
	 * Efecto sonoro.
	 *
	 */
	static void alarma();

	/*
		Para la correcta visualizaci�n de los
		car�cteres especiales.
	*/
	static void enlazarConsola();

private:
	WConsola();
	virtual ~WConsola();
};

