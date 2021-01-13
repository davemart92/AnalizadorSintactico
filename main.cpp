# include <stdio.h>
# include <stdlib.h>
# include <iostream>
# include "TablaSin.h"
# include "Presentacion.h"
# include "Pila.h"

using namespace std;

int main(){
	Presentacion p1 = Presentacion();
	TablaSin t1 = TablaSin();
	Pila pi1 = Pila();
void * p[2];
p[0]=p[1]=NULL;
p[0]=crea(p[0],0);
int tsin[12][9]; 
//int x = 0;
int y = 0;
t1.tablasin(tsin); //observar� que el par�metro es un arreglo, por lo que se env�a por referencia. char caracter;

// clase de fichero
int edo;
	FILE* fichero;
            fichero = fopen("prueba1.txt", "r");
if (fichero==NULL) {
fputs ("File error",stderr); 
exit (1); 
}
// clase de fichero

p1.iniciar();
//observar� que el par�metro es un arreglo, por lo que se env�a por referencia. T_lexico() s�lo llena el arreglo t_l

// este seria otro bloque
do {
    char caracter = fgetc(fichero);
    int y=t1.transforma(caracter); 
    if (y==6)
        break;
    edo=pi1.tope(p[0]);
    printf("caracter=> %c, y=>%d, edo=>%d\n",caracter,y,edo);
    edo=tsin[edo][y];
    printf("Edo=%d\n",edo);
    if (edo<0) {
        printf("ERROR SINT�CTICO");
        break; 
    }
    else
        sintactico(p,edo,y,tsin);
} while (y<5);
if (y==6)
    printf("Error lexicogr�fico, no se reconoce la palabra"); 
getchar();
}
// fin de otro bloque

