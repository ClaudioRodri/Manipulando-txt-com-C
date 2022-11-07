/**************************************************************************************************************************************************************
PROGRAMA3

	Nome e prontuário: 
		- Cláudio Rodrigues
	
	Data 28/07/21 21:40
	
	Descrição: programa que lê o arquivo criado no Sensor de Temperatura.
	
***************************************************************************************************************************************************************/



#include <stdio.h> //biblioteca padrão
#include<locale.h> //biblioteca para configurar acentuaçõa
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	setlocale(LC_ALL, "Portuguese");//configura a localização
	int maiorTemp, menorTemp = 1000;
	char temp[3], newTemp[3];
	int menu;
	
	do{
		
		FILE *file;
		file = fopen("TeDay.txt", "r"); //quando compilado em outro desktop deve ser alterado o diretorio
	
		printf("\n***************************************************** MENU *****************************************************\n\n");
		printf("1 - Exibir todas as temperaturas armazenadas no arquivo\n");
		printf("2 - Exibir a maior temperatura\n");
		printf("3 - Exibir a menor temperatura\n");
		printf("4 - Finalizar o programa\n\n");
		
		printf("Escolha a opção desejada: ");
		scanf("%i%*c", &menu);
		
		printf("\n\n");
		
		switch(menu){
			case 1: 
				char temperaturas[10000];
				printf("\n************************************** Temperaturas armazenadas no arquivo ************************************\n\n");
				while(fgets(temperaturas, 10000, file) != NULL){
					printf("%s", temperaturas);
				}
			break;
			
			case 2:
				char temperaturasFiltro[1000];
				while(fgets(temperaturasFiltro, 10000, file) != NULL){
					//se comecar com Temperatura: a string 
					//separe a string Temperatura: de modo que fique apenas o número inteiro...
					if(strstr(temperaturasFiltro, "Temperatura:")){
						memcpy(temp, &temperaturasFiltro[12], 12);
						int numero = atoi(temp);//convertendo char para int...
						if(numero > maiorTemp) maiorTemp = numero;// calculando a menor temperatura...
					}	
				}//fim do while
				printf("o maior número foi: %i", maiorTemp);
				break;
				
			case 3:
				char temperaturasFiltro2[1000];
				while(fgets(temperaturasFiltro2, 10000, file) != NULL){
				if(strstr(temperaturasFiltro2, "Temperatura:")){
					memcpy(temp, &temperaturasFiltro2[12], 12);
					int numero = atoi(temp);
					if(numero < menorTemp) menorTemp = numero;
				}	
			}
			printf("o menor número foi: %i", menorTemp);
			break;
			
			case 4:
				printf("\nPrograma finalizado. Agradecemos a preferência.");
			break;
			
			default:
				printf("O que você insiriu não faz parte do menu. Tente novamente.\n\n");
		}
		
		fclose(file);
			
	}while(menu != 4);
	
	return 0;
}
