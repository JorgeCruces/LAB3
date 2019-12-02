#include "libreria.h"
#include <math.h>

char dificultad();
int cantidadMinas(char dif);


char optionTablero();
int jugar(char optionJugar,int goalsMinas);

char tablerox[tam][tam];
int minas = 0;
int cantidad_originalMinas =0 ;

int main(){
	
	//Tablero
	int size = tam;
	
	//  0  1 2 3 4 5 6 7
	// 0
	// 1
	// 2
	
	
	//Dificultad
	char x;
	char dif = dificultad();
	minas = cantidadMinas(dif);
	cantidad_originalMinas = minas;
	construir_tablero(tablerox,minas);
	
	
	
	
	int jugando = 1;

	//Comienza el juego
	
	
	
		while(jugando == 1){
			
			LimpiaPantalla();	
			mostrar_tablero(tablerox,2);	
			char optionJugada = optionTablero();
			jugando = jugar(optionJugada,minas);
			
		}
		
		
		// 0 -> perder 2 -> ganar 1-> jugando
		
		if(jugando == 0){
			LimpiaPantalla();
			mostrar_tablero(tablerox,1);
			printf("Perdiste !!\n");
			printf("Acertaste con %i minas",cantidad_originalMinas - minas);
				
		}else if(jugando == 2){
			LimpiaPantalla();
			mostrar_tablero(tablerox,1);
			printf("Ganaste !!");
			printf("Acertaste con %i minas",cantidad_originalMinas - minas);
			
		}
		
		//Cuando acaba


	
	return 0;	
	
}

char optionTablero(){
		char option;
		printf("CANTIDAD DE MINAS %i \n",minas);
		printf("Ingrese M para marcar , A para abrir una casilla : ");
		scanf(" %c",&option);
		
		return option;
}

int jugar(char optionJugar,int goalMinas){
		
		char casilla[10];
		
		int columna;
		int fila = 0;
		int numMinass = 0;
		
		int i;
		char columna_char;
		
		
		printf("Ingrese coordenada de casilla ( ej : 1 , a ): ");
		scanf("%i%*c%c",&fila,&columna_char);
		fila = fila - 1;
	
		
	
	
		
		
		// a b c
	
		
	
		
		for(i = 0; i < 27; i++) { 
			if(columna_char== columnas[i]) {
				columna = i;
			}
		}
		

		
		//Ya tenemos la casilla
		if(optionJugar == 'A'){
			// PERDI
			if(tablerox[fila][columna] == '*'){
				return 0;
			} 
			else{
				numMinass = minasAlrededor(fila,columna);
				tablerox[fila][columna] = numMinass + '0';
				
			}
			
	
			//SINO
			
			
		}else if(optionJugar == 'M'){
			if(tablerox[fila][columna] == '*'){
				minas = minas-1;
				tablerox[fila][columna] = 'M';
			}
			
			if(minas <= 0){
				return 2;
			}
		
			
			
		}	
			return 1;
	

}



int minasAlrededor(int fila, int columna){
	
	int numMinas;
	numMinas = 0;
	char x;

	//ESQUINA SUPERIOR IZQUIERDA
	if(fila == 0 && columna == 0){
	
		if(tablerox[1][1] == '*'){
			numMinas++;
		  }
		  if(tablerox[0][1] == '*') {
		  	numMinas++;
		  }
		  if(tablerox[1][0] == '*') {
		  	numMinas++;
		  } 
		  
	}
	
	//ESQUINA SUPERIOR DERECHA
	if(fila == 0 && columna == tam-1 ){
		if(tablerox[fila][columna-1] == '*') {
			numMinas++;
		}
		if(tablerox[fila+1][columna-1] == '*'){
			numMinas++;
		}
		if(tablerox[fila+1][columna] == '*'){
			numMinas++;
		}
		
		
	}
	
	//ESQUINA INFERIOR IZQUIERDA
	if(fila == tam-1 && columna == 0){
		if(tablerox[fila-1][columna] == '*'){
			numMinas++;
		}
		if(tablerox[fila-1][columna+1] == '*'){
			numMinas++;
		}
		if(tablerox[fila][columna+1] == '*'){
			numMinas++;
		}
		
	}
	
	//ESQUINA INFERIOR DERECHA
	if(fila == tam-1 && columna == tam-1){
		if(tablerox[tam-1][tam-2] == '*'){
			numMinas++;
		}
		if(tablerox[tam-2][tam-2] == '*'){
			numMinas++;
		}
		if(tablerox[tam-2][tam-1] == '*'){
			numMinas++;
		}
		
	}
	
	
	//LADO IZQUIERDO
	
	if(columna == 0 && fila != 0){
		if(tablerox[fila-1][columna] == '*'){
			numMinas++;
		}
		if(tablerox[fila-1][columna+1] == '*'){
			numMinas++;
		}
		if(tablerox[fila][columna+1] == '*'){
			numMinas++;
		}
		if(tablerox[fila+1][columna+1] == '*'){
			numMinas++;
		}
		if(tablerox[fila+1][columna] == '*'){
			numMinas++;
		}
		
	}
	
	//LADO ABAJO
	
	if(fila == tam-1 && columna != 0 && columna != tam -1){
		if(tablerox[fila][columna-1] == '*'){
			numMinas++;
		}
		if(tablerox[fila-1][columna-1] == '*'){
			numMinas++;
		}
		if(tablerox[fila-1][columna] == '*'){
			numMinas++;
		}
		if(tablerox[fila-1][columna+1] == '*'){
			numMinas++;
		}
		if(tablerox[fila][columna+1] == '*'){
			numMinas++;
		}
	}
	
	//LADO DERECHO
	
	if(fila != 0 && fila != tam -1 && columna == tam-1){
		if(tablerox[fila-1][columna] == '*'){
			numMinas++;
		}
		if(tablerox[fila-1][columna-1] == '*'){
			numMinas++;
		}
		if(tablerox[fila][columna-1] == '*'){
			numMinas++;
		}
		if(tablerox[fila+1][columna-1] == '*'){
			numMinas++;
		}
		if(tablerox[fila+1][columna] == '*'){
			numMinas++;
		}
	}
	
	//LADO ARRIBA
	
	if(fila == 0 && columna != 0 && columna != tam-1){
		if(tablerox[fila][columna-1] == '*'){
			numMinas++;
		}
		if(tablerox[fila+1][columna-1] == '*'){
			numMinas++;
		}
		if(tablerox[fila+1][columna] == '*'){
			numMinas++;
		}
		if(tablerox[fila+1][columna+1] == '*'){
			numMinas++;
		}
		if(tablerox[fila][columna+1] == '*'){
			numMinas++;
		}
		
	}
	
	
	
	
	//MAYORIA DE CASOS
	
	if(fila != 0 && columna != 0 && fila != tam-1 && columna != tam-1){
		
		int fila_rial = fila;
		int columna_rial = columna;
	
		
		if(tablerox[fila_rial-1][columna_rial-1] == '*'){
			numMinas++;
		}
		if(tablerox[fila_rial-1][columna_rial]  == '*'){
			numMinas++;
		}
		if(tablerox[fila_rial-1][columna_rial+1]  == '*'){
			numMinas++;
		}
		if(tablerox[fila_rial][columna_rial-1]  == '*'){
			numMinas++;
		}
		if(tablerox[fila_rial][columna_rial+1]  == '*'){
			numMinas++;
		}
		if(tablerox[fila_rial+1][columna_rial-1]  == '*'){
			numMinas++;
		}
		if(tablerox[fila_rial+1][columna_rial]  == '*' ){
			numMinas++;
		}
		if(tablerox[fila+1][columna+1]  == '*'){
			numMinas++;
		}
	
	
	}

	
	


	

	
	
	return numMinas;
}





char dificultad(){
	Titulo();
	
	char dif;

	printf("\nIngrese dificultad de la partida ( F ( facil ) , M ( medio ) , D ( dificil )): D: ");

	scanf("%c",&dif);

	
	return dif;
}

int cantidadMinas(char dif){
	
	int cantidad = tam;
	if(dif == 'F'){
		cantidad = round((cantidad* cantidad) * 0.1);
	}
	else if(dif == 'M'){
		cantidad = round((cantidad* cantidad) * 0.15);	
	}else if(dif == 'D'){
		cantidad = round((cantidad* cantidad) * 0.2);
	}
	
	return cantidad;
}
