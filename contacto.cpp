#include "contacto.h"
#include <iostream>
#include <cstring>
#include <ncurses.h>

using namespace std;
Contacto::Contacto(){
	nombre=new char[10];
	numero=new char[10];
}

Contacto::Contacto(char* nombres, char* numeros){
	setNombre(nombre);
}

void Contacto::setNombre(char* nombre){
	this->nombre= new char[10];
	strcpy(this->nombre,nombre);
}

void Contacto::setNumero(char* numero){
	this->numero= new char[10];
	strcpy(this->numero,numero);
}

char* Contacto::getNombre(){
	return nombre;
}

char* Contacto::getNumero(){
	return numero;
}
void Contacto::imprimirNumero(){
	for(int i=0;i<9;i++){
		addch(numero[i]);
	}
}
void Contacto::imprimirNombre(){
	for(int i=0;i<9;i++){
		addch(nombre[i]);
	}
}

