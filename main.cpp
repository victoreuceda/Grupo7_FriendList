#include <ncurses.h>
#include <vector>
#include "contacto.h"
#include <cstring>
#include <iostream>

using std::string;
using std::vector;
using std::strcpy;
using std::cin;
using std::cout;
using std::endl;

int menu();
void cargarContacto(vector<Contacto>);
void ordenar(vector<Contacto>, vector<Contacto>, int);
void imprimir(vector<Contacto>);
void escribir(vector<Contacto>);
void cargarContacto(vector<Contacto>);


int main(int argc,char*argv[]){
	vector<Contacto> lista;
	vector<Contacto> lista2;
    int opcion;
	initscr();
    bool ejecutando=true;  
    do{
        move(0,20); 
	    opcion=menu();	
        refresh();
        clear();
        refresh();
        if(opcion==49){
            cargarContacto(lista);
		ordenar(lista,lista2,0);
            refresh();
        }else if(opcion==50){
            clear();         
            escribir(lista);
            refresh();
        }else{
            ejecutando=false;
        }
    }while(ejecutando==true);
	getch();
	endwin();
    cout<<opcion;
	return 0;
}


void cargarContacto(vector<Contacto> lista){
	init_pair(1,COLOR_GREEN,COLOR_BLACK);
	init_pair(2,COLOR_YELLOW,COLOR_BLACK);
	init_pair(3,COLOR_BLUE,COLOR_BLACK);
	init_pair(4,COLOR_MAGENTA,COLOR_BLACK);
	init_pair(5,COLOR_WHITE,COLOR_BLACK);
	char nombres[10];
	char numero[10];
	bool bandera=false;
	move(10,20);
	attron(COLOR_PAIR(1));
	addstr("Ingresando contacto, solo son aceptadas 9 minúsculas ");
	refresh();
	move(11,20);
	attron(COLOR_PAIR(2));
	addstr("Nombre: ");
	for(int i=0;i<9;i++){
		do{ 
            noecho();
			char ingresada;
            if((ingresada=getch())!='\n'){
                if(ingresada>=97 && ingresada<=122){
				    echo();
                    addch(ingresada);                    
                    nombres[i]=ingresada;
				    bandera=true;
			    }else{
                    noecho();
				    bandera=false;
			    }
            }
			
		}while(bandera==false);
	}
	nombres[9]='\0';
	refresh();
	move(12,20);
	attron(COLOR_PAIR(3));
	addstr("Número: ");
	for(int i=0;i<9;i++){
		do{
            noecho();
			char ingresada;
            if((ingresada=getch())!='\n'){
                if(i==4){
				    if(ingresada==45){
                        addch(ingresada); 
					    numero[i]=ingresada;
					    bandera=true;
				    }else{
					    bandera=false;
				    }
			    }else{
				    if(ingresada>=48 && ingresada<=57){
                        addch(ingresada); 					    
                        numero[i]=ingresada;
					    bandera=true;
				    }else{
					    bandera=false;
				    }
			    }

            }
			
		}while(bandera==false);
		
	}
	numero[9]='\0';
	refresh();
	move(13,20);
	char amistad[2];
	attron(COLOR_PAIR(4));
	addstr("Ingresar Nivel de Amistad: ");
	do{
		char ingresada=getch();
		if(ingresada>=49 && ingresada<=53){
			amistad[0]=ingresada;
			bandera=true;
		}else{
			bandera=false;
		}
	}while(bandera==false);
	amistad[1]='\0';
	refresh();
	move(14,20);	
	addstr(nombres);
	move(15,20);
	addstr(numero);
	move(16,20);
	addstr(amistad);
	Contacto nuevo(nombres,numero,amistad);
	lista.push_back(nuevo);	
	move(17,20);
	attron(COLOR_PAIR(5));
	addstr("Agregado");
    	move(14,20);
   	addstr("Su nuevo contacto es: ");
	move(15,20);
	addstr(nombres);
	move(16,20);
	addstr(numero);
	move(17,20);
	addstr(amistad);
	//Contacto nuevo(nombres,numero);
	lista.push_back(nuevo);
    	getch();
    	clear();
}

int menu(){
	int opcion;
	bool bandera=false;
	init_pair(1,COLOR_GREEN,COLOR_BLACK);
	init_pair(2,COLOR_YELLOW,COLOR_BLACK);
	init_pair(3,COLOR_BLUE,COLOR_BLACK);
	init_pair(4,COLOR_WHITE,COLOR_BLACK);
	attron(COLOR_PAIR(1));
	addstr(".-*.-*.-MENU-.*.-*.");
	attron(COLOR_PAIR(2));
	addstr("1.-) Agregar Contacto\n");
	attron(COLOR_PAIR(3));
	addstr("2.-) Listar Contacto\n");
	attron(COLOR_PAIR(4));	
	addstr("3.)Salir\n");
	for(int i=0;i<9;i++){
		do{
			char ingresada=getch();
			if(ingresada==49 || ingresada==50 || ingresada==51){
				opcion=ingresada;
				bandera=true;
			}else{
				bandera=false;
			}
		}while(bandera==false);
	}
	
	return opcion;
}
void ordenar(vector<Contacto> lista, vector<Contacto> lista2, int a){
	if(a==lista.size()){
		return;
	}else{			
		for(int i=a+1; i<lista.size(); i++){
			if(lista.at(i).getAmistad()<lista.at(a).getAmistad()){
				lista2.at(i)=lista.at(a);
				lista.at(a)=lista.at(i);
				lista.at(i)=lista2.at(i);
			}
		}
		ordenar(lista, lista2, a+1);
	}
}

void imprimir(vector<Contacto> lista){
	init_pair(1,COLOR_WHITE,COLOR_BLACK);//el mas aburrido
	init_pair(2,COLOR_YELLOW,COLOR_BLACK);//2do mas aburrido
	init_pair(3,COLOR_BLUE,COLOR_BLACK);//3ro mas aburrido
	init_pair(4,COLOR_GREEN,COLOR_BLACK);//2do mejor
	init_pair(5,COLOR_RED,COLOR_BLACK);//el mejoooor
	/*for(int i=0; i<lista.size(); i++){	
		if(lista.at(i).getAmistad()==49){
			attron(COLOR_PAIR(1));
			addstr(lista.at(i).getNombre());
			addstr('\t');
			addstr(lista.at(i).getNumero());
		else if(lista.at(i).getAmistad()==50){
			attron(COLOR_PAIR(2));
			addstr(lista.at(i).getNombre());
			addstr('\t');
			addstr(lista.at(i).getNumero());
		}else if(lista.at(i).getAmistad()==51){
			attron(COLOR_PAIR(3);
			addstr(lista.at(i).getNombre());
			addstr('\t');
			addstr(lista.at(i).getNumero());
		}else if(lista.at(i).getAmistad()==52){
			attron(COLOR_PAIR(4));
			addstr(lista.at(i).getNombre());
			addstr('\t');
			addstr(lista.at(i).getNumero());
		}else{
			attron(COLOR_PAIR(5));
			addstr(lista.at(i).getNombre());
			addstr('\t');
			addstr(lista.at(i).getNumero());
		}	
	}*/
	return;
}


void escribir(vector<Contacto> lista){
    refresh();
    clear();
    move(1,20);
    addstr("Nombre\t   Número");
    int x=2,y=20;
	move(x,y);
	for(int i=0;i<lista.size();i++){
		mvprintw(x,y,lista[i].getNombre());
		x++;
		y++;
		mvprintw(x,y,lista[i].getNumero());
	}

    getch();
    clear();
}
