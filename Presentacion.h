# include <stdio.h>
# include <stdlib.h>
# include <iostream>

using namespace std;

class Presentacion{
	// atributos
	//metodos
	public:
		Presentacion();
		void iniciar();
};

Presentacion::Presentacion(){
};

void Presentacion::iniciar(){
	cout<<"Analizador Lexico y Sintáctico COMELI.\n "<<endl;
	cout<<"iniciamos\n"<<endl;
}
