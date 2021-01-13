# include <stdio.h>
# include <stdlib.h>
# include <iostream>

using namespace std;


//pila sintáctica
struct nodo{
    int dato;
    struct nodo * siguiente;
    
};

// el árbol
struct nodo1{
    char dato;
    struct nodo1 * izq;
    struct nodo1 * der;
};

//pila para crear el árbol
struct nodo2{
    void * p;
    struct nodo2 * siguiente;
};


void * elimina(void *);

void *crea(void *, int);

void  sintactico(void **, int, int, int[][9]); //requiere shift
void *shift(void*, int, int);


//Funciones para crear el árbol
void *creaA(void *, char );
void * enlaza(void *, char );


// ************************************* Clase Pila

class Pila{
	//atr
	//metodos
	public:
		pila();
		int tope(void* p);
		void mostrar(void *p);
		void reduce(void **p, int edo, int tsin[][9]);
		void muestraA(struct nodo1 * r);
		
};

void Pila::muestraA(struct nodo1 * r){
	if(r!=NULL){ 
		muestraA(r->izq);
		muestraA(r->der);
		if(r->dato=='i' || r->dato=='+' ||r->dato=='*')
			printf("%c ",r->dato);
	}
}

void Pila::reduce(void **p, int edo, int tsin[][9]){
	int w=edo-100,z; 
	if (w%2==1){
		for (int k=0;k<6;k++) //ELIMINO SEIS ELEMENTOS 
			p[0]=elimina(p[0]);
		printf("Reducción de seis elementos\n");
		mostrar(p[0]);
		putchar('\n');
		z=tope(p[0]); //TOMO LO QUE HAY EN TOPE DE PILA
		if(w==1){ //reduce E->E+T
			p[0]=crea(p[0],6); 
			//INTRODUCIR LA REDUCCIÓN (EN ESTE CASO, 6 REPRESENTA A "E")
			z=tsin[z][6]; //Reviso el elemento a introducir a tope de pila
			p[0]=crea(p[0],z); //introduzco el elemento a tope de pila
			printf("llamo a enlaza con +\n");
			p[1]=enlaza(p[1], '+');
		}
		else if(w==3){ //reduce T->T*F 
		p[0]=crea(p[0],7);
			z=tsin[z][7];
			p[0]=crea(p[0],z);
			printf("Llamo a enlaza con *\n"); 
			p[1]=enlaza(p[1], '*');
		}
		else { //REDUCE F->(E)
			p[0]=crea(p[0],8); 
			z=tsin[z][8]; 
			p[0]=crea(p[0],z); 
			p[1]=creaA(p[1],'F');
		}
	}
	else{
		for (int i=0;i<2;i++) //ELIMINO DOS ELEMENTOS
			p[0]=elimina(p[0]);
		z=tope(p[0]);
		printf("Reducción de dos elementos\n"); 
		mostrar(p[0]);
		putchar('\n');
		if (w==2){ //E->T 
			p[0]=crea(p[0],6);
			z=tsin[z][6]; 
			p[0]=crea(p[0],z);
			p[1]=creaA(p[1],'E'); 
		}
		else if (w==4){ //T->F 
			p[0]=crea(p[0],7);
			z=tsin[z][7]; 
			p[0]=crea(p[0],z); 
			p[1]=creaA(p[1],'T');
		}
		else if (w==6){ //F->ID
			p[0]=crea(p[0],8); 
			z=tsin[z][8]; 
			p[0]=crea(p[0],z); 
			p[1]=creaA(p[1],'i');
		}
	 }
}

void Pila::mostrar(void *p){
	struct nodo *s;
	s=(struct nodo *)p;
	if (p==NULL)
		printf("PILA VACIA"); 
	else{
		if(s->siguiente!=NULL) 
			mostrar(s->siguiente);
		printf("%d..",s->dato); 
	}
}

int Pila::tope(void* p){
	struct nodo *q=(struct nodo*)p;
	printf("\nEn tope %d\n",q->dato);
	return q->dato;
}

// ***************************************** Final clase Pila


void sintactico(void ** p, int edo, int y, int tsin[][9]) { 
Pila pila = Pila();
int z;
struct nodo2 *aux;
struct nodo1 *r;
if (edo <100) //Hay un shift
p[0]=shift(p[0],y,edo); 
else{ // hay una reducción
while(edo>100){ 
pila.reduce(p,edo,tsin);
printf("Después de Reducción\n");
pila.mostrar(p[0]);
z=pila.tope(p[0]);
edo=tsin[z][y]; //Reviso el nuevo estado guardado en tope de pila con el elemento leido para ver si se repita la reducción
if (edo==1000) {
printf("TERMINO CON EXITO\n\n"); 
printf("El arbol es:\n");
aux=(struct nodo2*)p[1];
r=(struct nodo1*)aux->p;
pila.muestraA(r);
break;
}
else if (edo <100 && edo >-1) //Hay un shift 
p[0]=shift(p[0],y,edo);
else if (edo<0)
printf("ERROR SINTÁCTICO");
}

}

}

void*shift(void *p, int y, int edo){
	Pila pila = Pila();
	p=crea(p,y); 
p=crea(p,edo-10); 
printf("\nShift =>%d\n",y); 
pila.mostrar(p);
putchar('\n');
return p;
}

void *crea(void *p, int x){
struct nodo *q,*aux; 
q=(struct nodo*)malloc(sizeof(struct nodo)); 
q->dato=x;
q->siguiente=NULL; 
if(p==NULL) //La pila está vacía
p=q; 
else{
q->siguiente=(struct nodo*)p;
p=q; 
}
return(p);
}

void * elimina(void * s){ 
struct nodo *p,* aux; 
if(s==NULL)
printf("\npila vacia\n"); 
else{
p=(struct nodo*)s;
s=p->siguiente;
free(p); 
}
return(s); 
}

//------------------------------------------------ //FUNCIONES PARA CREAR EL ÁRBOL
void *creaA(void *p, char x){
struct nodo1 *q, *aux; //apuntador a nodo de árbol
struct nodo2 *q1,*aux1; //apuntador a pila para crear el árbol
if (x=='i'){//en este caso, se considera que el identificador es una hoja del árbol.
//crear el nodo para el identificador y preparo el terreno para el Factor
aux=(struct nodo1*)malloc(sizeof(struct nodo1));
aux->dato=x;
x='F';
printf("\n\tSe crea rama => %c\n",aux->dato); 
aux->izq=aux->der=NULL; 
q1=(struct nodo2*)malloc(sizeof(struct nodo2)); 
q1->p=aux;
q1->siguiente=NULL; 
if (p==NULL)
p=q1;
else{
q1->siguiente=(struct nodo2*)p;
p=q1; 
}
}
//se crea el una parte de la rama del árbol 
q=(struct nodo1*)malloc(sizeof(struct nodo1)); 
q->dato=x;
printf("\n\tGuardo un %c\n\n",q->dato);
q->der=NULL; 
aux1=(struct nodo2*)p; 
aux=(struct nodo1*)aux1->p; 
q->izq=aux; aux1->p=q;
p=aux1; 
return(p); 
}

void * enlaza(void * p, char x){ 
struct nodo1 * q,*q1;
struct nodo2 * aux,*aux1,*aux2;
//se crea nodo que enlaza dos ramas 
q=(struct nodo1*)malloc(sizeof(struct nodo1));
aux=(struct nodo2*)p; //rama derecha
aux1=aux->siguiente; //rama izquierda
q->izq=(struct nodo1*)aux1->p; //se conecta lado izquierdo de la rama 
q->der=(struct nodo1*)aux->p; //se conecta lado derecho de la rama 
q->dato=x;
aux2=(struct nodo2*)malloc(sizeof(struct nodo2));
aux2->p=q; 
aux2->siguiente=aux1->siguiente;
free (aux); 
free (aux1);
return(aux2);
}







