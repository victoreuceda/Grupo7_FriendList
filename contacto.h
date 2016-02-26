#ifndef CONTACTO_H
#define CONTACTO_H
#include <cstring>

using std::string;

class Contacto{

	string nombre;
	char* numero;
	
	public:
		Contacto(string, char*);
		void setNombre(string nombre);
		void setNumero(char* numero);
		string getNombre();
		char* getNumero();
								
};

#endif


