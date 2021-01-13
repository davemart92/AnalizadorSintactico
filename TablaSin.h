# include <stdio.h>
# include <stdlib.h>
# include <iostream>

using namespace std;
// ****************************************** Clase tabla sintactica
class TablaSin{
	// atrr
	//metodos
	public:
		tablaSin();
		void tablasin(int x[][9]);
		int transforma (char c);
};

int TablaSin::transforma(char c){
	int x;
	if (c>='a' && c<='z')
		x=0; 
	else
	switch(c){
		case '+':x=1;break; 
		case '*':x=2;break; 
		case '(':x=3;break; 
		case ')':x=4;break; 
		case '$':x=5;break; 
		default:x=6;
	}
	return x;
}

void TablaSin::tablasin(int x[][9]){
	 for(int i=0;i<12;i++)
        for (int j=0;j<9;j++) 
            x[i][j]=-1;
        
        x[0][0]=15; //S5
        x[0][3]=14; //S4
        x[0][6]=1; // IR AL ESTADO 1 
        x[0][7]=2; // IR AL ESTADO 2 
        x[0][8]=3; // IR AL ESTADO 3 
        x[1][1]=16; //S6 
        x[1][5]=1000; //ACC 
        x[2][1]=102; // REDUCE E->T 
        x[2][2]=17; //S7
        x[2][4]=102; // REDICE E->T 
        x[2][5]=102; // REDICE E->T 
        x[3][1]=104; // REDUCE T->F 
        x[3][2]=104; // REDUCE T->F 
        x[3][4]=104; // REDUCE T->F 
        x[3][5]=104; // REDUCE T->F
        x[4][0]=15; //S5
        x[4][3]=14; //S4
        x[4][6]=8; // IR AL ESTADO 8
        x[4][7]=2; // IR AL ESTADO 2
        x[4][8]=3; // IR AL ESTADO 3
        x[5][1]=106; // REDUCE F->ID 
        x[5][2]=106; // REDUCE F->ID 
        x[5][4]=106; // REDUCE F->ID 
        x[5][5]=106; // REDUCE F->ID 
        x[6][0]=15; //S5
        x[6][3]=14; // S4
        x[6][7]=9; // IR AL ESTADO 9 
        x[6][8]=3; // IR AL ESTADO 3 
        x[7][0]=15; // S5
        x[7][3]=14; // S4
        x[7][8]=10; // IR AL ESTADO 10 
        x[8][1]=16; // S6
        x[8][4]=21; // S11
        x[9][1]=101; // REDUCE E->E+T 
        x[9][2]=17; // S7
        x[9][4]=101; // REDUCE E->E+T 
        x[9][5]=101; // REDUCE E->E+T
        x[10][1]=103; // REDUCE T->T*F
        x[10][2]=103; // REDUCE T->T*F
        x[10][4]=103; // REDUCE T->T*F
        x[10][5]=103; // REDUCE T->T*F
        x[11][1]=105; // REDUCE F->(E)
        x[11][2]=105; // REDUCE F->(E)
        x[11][4]=105; // REDUCE F->(E)
        x[11][5]=105; // REDUCE F->(E)
}

// ******************************************************* Final Clase tabla sintactica
