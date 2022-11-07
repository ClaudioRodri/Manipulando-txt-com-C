/**************************************************************************************************************************************************************
PROGRAMA2

	Nome e prontu�rio: 
		- Cl�udio Rodrigues 
	
	Data 28/07/21 20:46
	
	Descri��o: Fa�a um programa que simule um sensor anal�gico do Arduino, utilizando n�mero aleat�rio (valores de 0 a 1023) 
	para simular as leituras de um sensor de temperatura
	
***************************************************************************************************************************************************************/

#include <stdio.h> //biblioteca padr�o
#include <stdlib.h>
#include <time.h>   //biblioteca para configurar a data
#include <conio.h> //faz funcionar o kbhit()
#include<locale.h> //biblioteca para configurar acentua��o

//vari�vel global
int resultado;
int tecla;

FILE *file; //ponteiro do arquivo

//Prot�tipos das fun��es
void ps(int s); //faz um delay na execucao do loop 
int Temperatura (); //Calcula a temperatura e o armazena em um arquivo

//Fun��o principal
int main(){
	
	setlocale(LC_ALL, "Portuguese");//configura a localiza��o
	
	srand(time(NULL)); //Valores do rand() oscilam
	
		printf("\n******* TEMPERATURAS *******\n\n");
	
	// Loop
	for( ; ; ){
		
		ps(1); //chama a fun��o ps com Delay de 1 segundo
		Temperatura(); //Chama a fun��o Temperatura
	
	
		if(kbhit()){ 
			//tecla F == 102
			if((tecla = getch()) == 102) break;
		}

    }


	fclose(file); //fecha o arquivo
	
return 0;
}


void ps(int s){

   int i;
   i = 1000 * s;

   clock_t start_time = clock();

   while (clock() < start_time + i);

}


int Temperatura () { 
	
	time_t current_time;
	
	   char* string; //string para a data
	   
	   current_time = time(NULL);
	   string = ctime(&current_time);
	

	int S = rand() % 1023;  //Gera os n�meros de 0 a 1023
	int resultado = (S * 500) / 1023;  //n�mero aleat�rio
	
	printf("Temperatura: %d\n", resultado);


	file = fopen("TeDay.txt", "a"); //Abre o arquivo ou cria se n�o houver para adcionar coisas nele
	
	 if(resultado >= 60){ //verifica se a temperatura � maior que 60
	
	     fprintf(file, "Temperatura: %d\nData: %s\n\n", resultado, string); //imprime a temperatura e a data dentro arquivo

 }
}

