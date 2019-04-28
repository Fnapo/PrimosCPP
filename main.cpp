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

#include <iostream>

#include "AccionesCPP.hpp"

using namespace std;

/*
 *
 */
int main(int argc, const char** argv) {
	if (argc <= 1) {
		AccionesCPP::inicio();
	} else {
		std::cout << "Existen " << argc << " argumentos:" << std::endl;
		for (int i = 0; i < argc; ++i) {
			std::cout << argv[i] << std::endl;
		}
	}

	return 0;
}
