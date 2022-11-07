/**************************************************************************************************************************************************************
PROGRAMA1

	Nome e prontu�rio: 
		- Cl�udio Rodrigues 
	
	Data 28/07/21 20:46
	
	Descri��o: o programa resolve problemas da �rea de mec�nica dos fluidos
		- Convers�o de unidades de medida
		- Calculos de propriedades dos fluidos
		- Calculo de vaz�o
		- Calculo do n�mero de reynolds
		- Calculo da press�o em fuidos parados
		- calculo da for�a em fluidos parados
		- calculo do empuxo 
	
***************************************************************************************************************************************************************/

//bibliotecas
#include<stdio.h> //biblioteca padr�o
#include<string.h> //biblioteca string
#include<stdlib.h> //Para utilizar a fun��o srand
#include <ctype.h> //biblioteca que faz funcionar o toupper()
#include<locale.h> //biblioteca para configurar acentua��a
#include<conio.h>
#include<math.h>
#include <time.h>// para utilizar (unsigned)time(NULL))

//struct
struct livros{
	int codigo;
	char nome[50];
	int numautores;
	char autor[30];
	char descricao[200];
	int quantpag;
	int capitulo;
	float preco;
} MEFA[15];

//Prot�tipo
float caso1(); //Convers�o de unidades de medida
float caso2(); //C�lculos de propriedades dos fluidos
float caso3(); //C�lculo de vaz�o
float caso4(); //C�lculo do n�mero de reynolds
float caso5(); //C�lculo da press�o em fluidos parados utilizando o teorema de Stevin
float caso6(); //c�lculo do empuxo
float cadastro(); //Cadastro de Livros de Mec�nica
void exibir(); //Consultar os registros armazenados
void ind(); //Consulta individual de um item cadastrado
void alterar(); //Alterar itens cadastrados
void excluir(); //Excluir itens cadastrados
void algoritimo(); //Exibir os itens do vetor em ordem crescente ou decrescente
void gravar(); //Armazena os dados gravados no vetor no Arquivo
void ler(); //Leitura dos registros do arquivo e armazenagem no vetor




//variaveis globais
int menu; //op��o escolhida do menu principal pelo usu�rio
int opcao; //op��o escolhida do menu secund�rio pelo usu�rio
int indice;
int contador = 0;
FILE *file;


//fun��o principal
int main(){
	
	
	setlocale(LC_ALL, "Portuguese");//configura a localiza��o
	
	
	do{
	file = fopen("Dados da struct.txt", "a");
	printf("\n******************************************* MENU PRINCIPAL *******************************************\n\n");	
		
		printf("1 - Convers�o de unidades de medida");
		printf("\n2 - C�lculos de propriedades dos fluidos");
		printf("\n3 - C�lculo de vaz�o");
		printf("\n4 - C�lculo do n�mero de reynolds");
		printf("\n5 - C�lculo da press�o em fluidos parados (teorema de Stevin)");
		printf("\n6 - c�lculo do empuxo");
		printf("\n7 - Cadastro de Livros de Mec�nica");
		printf("\n8 - Consultar os registros armazenados");
		printf("\n9 - Consulta individual de um item cadastrado");
		printf("\n10 - Alterar itens cadastrados");
		printf("\n11 - Excluir itens cadastrados");
		printf("\n12 - Exibir os itens do vetor em ordem crescente ou decrescente");
		printf("\n13 - Armazena os dados gravados no vetor no Arquivo");
		printf("\n14 - Leitura dos registros do arquivo e armazenagem no vetor");
		printf("\nF - Finalizar Programa.\n");
		
		printf("\nDigite a op��o desejada: ");
		scanf("%i%*c", &menu);
			
	switch(menu){
		case 1: caso1();
			break;
		case 2: caso2();
			break;
		case 3: caso3();
			break;
		case 4: caso4();
			break;
		case 5: caso5();
			break;
		case 6: caso6();
			break;
		case 7: cadastro();
			break;
		case 8: if(menu == 7){
		contador++;
		} 
		exibir();
			break;
		case 9: ind();
			break;
		case 10: alterar();
			break;
		case 11: excluir();
			break;
		case 12: algoritimo();
			break;
		case 13: gravar();
			break;
		case 14: ler();
			break;
		case 'F': printf("\nPrograma finalizado. Agradecemos a prefer�ncia.");
			break;
		
		default:
			printf("O que voc� insiriu n�o faz parte do menu. Tente novamente.\n\n");
			
	}
	
	
		
		
	}while(menu != 'F');
	
	
return 0;
}

//fun��es
//Convers�o de unidades de medida
float caso1(){
	int num;
	float q, m, g, s, h, c, mc, ml, l;
	float result;
	
	do{
		printf("\n********************* Menu das Convers�es de unidades de medida *********************\n"); //MENU DAS CONVERSOES
		printf("\n1 - Tempo");//calculos de convers�o do tempo
		printf("\n2 - Massa");
		printf("\n3 - Comprimento");
		printf("\n4 - Volume");
		printf("\n5 - Voltar ao menu principal.");
		
		printf("\n\nDigite uma op��o do menu: ");
		scanf("%i%*c", &opcao);
		
		
		switch(opcao){
		case 1:
		printf("\nVoc� deseja converter:\n");
		printf("\n1 - Segundos para Horas");
		printf("\n2 - Hora para Segundos");
		printf("\n3 - Minutos para Segundos");
		printf("\n4 - Segundos para Minutos");
		printf("\n5 - Horas para Minutos");
		printf("\n6 - Minutos para Horas");
		
		printf("\n\nDigite a op��o escolhida: ");
		scanf("%i%*c", &num);
		
		if(num == 1){
			printf("\nDigite o valor em segundos: ");
			scanf("%f%*c", &s);
			
		result = s/3600;
		
		printf("\nO num�ro inserido em horas � igual a: %f\n\n", result);
		}
		
		else if(num == 2){
			printf("\nDigite o valor em Horas: ");
			scanf("%f%*c", &h);
			
		result = h * 3600.00;
		
		printf("\nO num�ro inserido em segudos � igual a: %.2f\n\n", result);
		}
		
		else if(num == 3){
			printf("\nDigite o valor em minutos: ");
			scanf("%f%*c", &m);
			
		result = m * 60.00;
		
		printf("\nO num�ro inserido em segudos � igual a: %.2f\n\n", result);
		}
		
		else if(num == 4){
			printf("\nDigite o valor em Segundos: ");
			scanf("%f%*c", &h);
			
		result = s / 60.00;
		
		printf("\nO num�ro inserido em Minutos � igual a: %.2f\n\n", result);
		}
		
		else if(num == 5){
			printf("\nDigite o valor em Horas: ");
			scanf("%f%*c", &h);
				
			result = h * 60.00;
			
			printf("\nO num�ro inserido em Minutos � igual a: %.2f\n\n", result);
			}
			
		else if(num == 6){
			printf("\nDigite o valor em minutos: ");
			scanf("%f%*c", &m);
			
			result = m / 60.00;
		
			printf("\nO num�ro inserido em horas � igual a: %.2f\n\n", result);
		}
		
		break;
			
		case 2:  //massa
		printf("\nVoc� deseja converter:\n");
		printf("\n1 - Quilogramas para gramas");
		printf("\n2 - Gramas para Quilogramas");
		printf("\n3 - Miligramas para Gramas");
		printf("\n4 - Gramas para Miligramas");
		printf("\n5 - Miligramas para Quilogramas");
		printf("\n6 - Quilogramas para Miligramas");
		
		printf("\n\nDigite a op��o escolhida: ");
		scanf("%i%*c", &num);
		
		
			switch(num){
				case 1: //Quilogramas para gramas
					printf("\nDigite o valor em Quilogramas: ");
					scanf("%f%*c", &q);
					
						result = q * 1000.00;
					
					printf ("\nO valor em gramas � igual a: %.2f\n\n", result);
				
					break;
				case 2: //Gramas para Quilogramas
					printf("\nDigite o valor em gramas: ");
					scanf("%f%*c", &g);
					
						result = g / 1000.00;
					
					printf ("\nO valor em Quilogramas � igual a: %f\n\n", result);
				
					break;
				case 3: //Miligramas para Gramas
					printf("\nDigite o valor em Miligramas: ");
					scanf("%f%*c", &m);
					
						result = m / 1000.00;
					
					printf ("\nO valor em gramas � igual a: %f\n\n", result);
				
					break;
				case 4: //Gramas para Miligramas
					printf("\nDigite o valor em gramas: ");
					scanf("%f%*c", &g);
					
						result = g * 1000.00;
					
					printf ("\nO valor em Miligramas � igual a: %.2f\n\n", result);
					
					break;
				case 5: //Miligramas para Quilogramas
					printf("\nDigite o valor em Miligramas: ");
					scanf("%f%*c", &m);
					
						result = m / 1000000.00;
					
					printf ("\nO valor em Quilogramas � igual a: %f\n\n", result);
					
					break;
				case 6: //Quilogramas para Miligramas
					printf("\nDigite o valor em Quilogramas: ");
					scanf("%f%*c", &q);
					
						result = q * 1000000.00;
					
					printf ("\nO valor em Miligramas � igual a: %.2f\n\n", result);
					
					break;
			}
		
			break;
		case 3: //comprimento
		printf("\nVoc� deseja converter:\n");
		printf("\n1 - Metros para cent�metros");
		printf("\n2 - Cent�metros para Metros");
		printf("\n3 - Metros para Quil�metros");
		printf("\n4 - Quil�metros para Metros");
		printf("\n5 - Cent�metros para Quil�metros");
		printf("\n6 - Quil�metros para Cent�metros");
		
		printf("\n\nDigite a op��o escolhida: ");
		scanf("%i%*c", &num);
		
		
			switch(num){
				case 1: //Metros para cent�metros
					printf("\nDigite o valor em Metros: ");
					scanf("%f%*c", &m);
					
						result = m * 100.00;
					
					printf ("\nO valor em cent�metros � igual a: %.2f\n\n", result);
				
					break;
				case 2: //Cent�metros para Metros
					printf("\nDigite o valor em Cent�metros: ");
					scanf("%f%*c", &c);
					
						result = c / 100.00;
					
					printf ("\nO valor em Metros � igual a: %f\n\n", result);
				
					break;
				case 3: //Metros para Quil�metros
					printf("\nDigite o valor em Metros: ");
					scanf("%f%*c", &m);
					
						result = m / 1000.00;
					
					printf ("\nO valor em Quil�metros � igual a: %f\n\n", result);
				
					break;
				case 4: //Quil�metros para Metros
					printf("\nDigite o valor em Quil�metros: ");
					scanf("%f%*c", &q);
					
						result = q * 1000.00;
					
					printf ("\nO valor em Metros � igual a: %.2f\n\n", result);
					
					break;
				case 5: //Cent�metros para Quil�metros
					printf("\nDigite o valor em Cent�metros: ");
					scanf("%f%*c", &c);
					
						result = c / 100000.00;
					
					printf ("\nO valor em Quil�metros � igual a: %f\n\n", result);
					
					break;
				case 6: //Quil�metros para Cent�metros
					printf("\nDigite o valor em Quil�metros: ");
					scanf("%f%*c", &q);
					
						result = q * 100000.00;
					
					printf ("\nO valor em Cent�metros � igual a: %.2f\n\n", result);
					
					break;
			}
			
			break;
			
		case 4: //Volume
		printf("\nVoc� deseja converter:\n");
		printf("\n1 - Metros C�bicos para Litros");
		printf("\n2 - Litros para Metros C�bicos");
		printf("\n3 - Metros C�bicos para mililitros");
		printf("\n4 - Mililitros para Metros C�bicos");
		printf("\n5 - Mililitros para Litros");
		printf("\n6 - Litros para Mililitros");
		
		printf("\n\nDigite a op��o escolhida: ");
		scanf("%i%*c", &num);
		
		
			switch(num){
				case 1: //Metros C�bicos para Litros
					printf("\nDigite o valor em Metros C�bicos: ");
					scanf("%f%*c", &mc);
					
						result = mc * 1000.00;
					
					printf ("\nO valor em Litros � igual a: %.2f\n\n", result);
				
					break;
				case 2: //Litros para Metros C�bicos
					printf("\nDigite o valor em Litros: ");
					scanf("%f%*c", &l);
					
						result = l / 1000.00;
					
					printf ("\nO valor em Metros C�bicos � igual a: %f\n\n", result);
				
					break;
				case 3: //Metros C�bicos para mililitros
					printf("\nDigite o valor em Metros C�bicos: ");
					scanf("%f%*c", &mc);
					
						result = mc * 1000000.00;
					
					printf ("\nO valor em Mililitros � igual a: %.2f\n\n", result);
				
					break;
				case 4: //Mililitros para Metros C�bicos
					printf("\nDigite o valor em Mililitros: ");
					scanf("%f%*c", &ml);
					
						result = ml / 1000000.00;
					
					printf ("\nO valor em Metros C�bicos � igual a: %f\n\n", result);
					
					break;
				case 5: //Mililitros para Litros
					printf("\nDigite o valor em Mililitros: ");
					scanf("%f%*c", &ml);
					
						result = ml / 1000.00;
					
					printf ("\nO valor em Litros � igual a: %f\n\n", result);
					
					break;
				case 6: //Litros para Mililitros
					printf("\nDigite o valor em Litros: ");
					scanf("%f%*c", &l);
					
						result = l * 1000.00;
					
					printf ("\nO valor em Mililitros � igual a: %.2f\n\n", result);
					
					break;
			}
			
			
			break;
			
		case 5: //Voltar ao menu principal
			break;
		}
		
		
		if ((opcao != 1)&&(opcao != 2)&&(opcao != 3)&&(opcao != 4)&&(opcao != 5)){
		printf("\nO que voc� insiriu n�o faz parte do menu. Tente novamente.\n");
		}
		
		}while(opcao != 5);
	
	}
	
//C�lculos de propriedades dos fluidos
float caso2(){
	
	float ME, PE, VE, CP, EL;
	float ms, vl, ps;
	
	do{
	printf("\n********************* Menu do C�lculos de propriedades dos fluidos *********************\n");
		printf("\n1 - C�lculo da massa espec�fica");
		printf("\n2 - C�lculo do peso espec�fico");
		printf("\n3 - C�lculo do volume espec�fico");
		printf("\n4 - Voltar ao menu principal.\n");
		
			printf("\nDigite a op��o desejada: ");
			scanf("%i%*c", &opcao);
			
			switch(opcao){
				case 1: //C�lculo da massa espec�fica
				printf("\nDigite a massa: ");
				scanf("%f%*c", &ms);
				printf("Digite o Volume: ");
				scanf("%f%*c", &vl);
				
					ME = ms / vl;
				
					printf("\nA massa espec�fica � de: %f\n\n", ME);
					break;
					
				case 2: //C�lculo do peso espec�fico
				printf("\nDigite o Peso: ");
				scanf("%f%*c", &ps);
				printf("Digite o Volume: ");
				scanf("%f%*c", &vl);
				
					PE = ps / vl;
				
					printf("\nO peso espec�fico � de: %f\n\n", PE);
					break;
					
				case 3: //C�lculo do volume espec�fico
				printf("\nDigite o Volume total: ");
				scanf("%f%*c", &vl);
				printf("Digite a Massa total: ");
				scanf("%f%*c", &ms);
				
					VE = vl / ms;
				
					printf("\nO Volume espec�fico � de: %f\n\n", VE);
					break;
					
				case 4: //Voltar ao menu principal
					break;
			}
			
		if ((opcao != 1)&&(opcao != 2)&&(opcao != 3)&&(opcao != 4)){
		printf("\nO que voc� insiriu n�o faz parte do menu. Tente novamente.\n");
		}
			
	}while(opcao != 4);
	
}
	

//C�lculo de vaz�o
float caso3(){
/*C�lculo de Vaz�o em Volume: Q = v�A
C�lculo de Vaz�o em Massa: Qm = ?m/?y
C�lculo da Vaz�o por meio do volume e tempo: Q = V / t 

Q = Vaz�o
v = velocidade m�dia global do fluido no conduto
A = �rea da se��o transversal do conduto
Qm = Vaz�o em Massa
?m = quantidade (massa) de fluido deslocado no intervalo de tempo considerado
?t = intervalo de tempo considerado
V = Volume
t = tempo
*/

	
	do{
		printf("\n********************* Menu do Calculo da Vaz�o *********************\n");
		printf("\n1 - C�lculo da Vaz�o por meio da velocidade e �rea da se��o transversal do conduto");
		printf("\n2 - C�lculo da Vaz�o por meio do volume e tempo");
		printf("\n3 - C�lculo de Vaz�o em Massa");
		printf("\n4 - Voltar ao menu principal.");
		
		printf("\n\nDigite uma op��o do menu: ");
		scanf("%i%*c", &opcao);
		
		float vazao, massa, velocidade, area, tempo, volume;
		switch(opcao){
		case 1: //C�lculo da Vaz�o por meio da velocidade e �rea da se��o transversal do conduto
			printf("\nDigite a velocidade m�dia global do fluido no conduto: ");
			scanf("%f%*c", &velocidade);
			printf("Digite a �rea da se��o transversal do conduto: ");
			scanf("%f%*c", &area);
			
			vazao = velocidade * area;
			
			printf("\nA vaz�o � igua a: %.2f\n\n", vazao);
			
			break;
		case 2: //C�lculo da Vaz�o por meio do volume e tempo
			printf("\nDigite o volume: ");
			scanf("%f%*c", &volume);
			printf("Digite o tempo: ");
			scanf("%f%*c", &tempo);
			
			vazao = volume/tempo;
			
			printf("\nA vaz�o � igua a: %.2f\n\n", vazao);
			
			break;
		case 3: //C�lculo de Vaz�o em Massa
			printf("\nDigite a quantidade (massa) de fluido deslocado no intervalo de tempo considerado: ");
			scanf("%f%*c", &massa);
			printf("Digite o intervalo de tempo considerado: ");
			scanf("%f%*c", &tempo);
			
			vazao = massa / tempo;
			
			printf("\nA vaz�o � igua a: %.2f\n\n", vazao);
			
			break;
		case 4: //Voltar ao menu principal
			break;
		}
		
		
		if ((opcao != 1)&&(opcao != 2)&&(opcao != 3)&&(opcao != 4)){
		printf("\nO que voc� insiriu n�o faz parte do menu. Tente novamente.\n");
		}
		
		}while(opcao != 4);	
}

//C�lculo do n�mero de reynolds
float caso4(){
/*C�lculo do N�mero de Reynolds: Re = pVD/�

Re = N�mero de Reynolds
p = Massa Espec�fica do Flu�do 
V = Velocidade M�dia 
D = Di�metro Hidr�ulico
� = Viscosidade Din�mica do Flu�do*/

	float Re;
	float p, V, D, u;
	
	printf("\n********************* C�lculo do n�mero de reynolds *********************\n");
	
	printf("\nDigite a Massa Espec�fica do Flu�do: ");
	scanf("%f%*c", &p);
	printf("Digite a Velocidade M�dia: ");
	scanf("%f%*c", &V);
	printf("Digite a Di�metro Hidr�ulico: ");
	scanf("%f%*c", &D);
	printf("Digite a Viscosidade Din�mica do Flu�do: ");
	scanf("%f%*c", &u);
	
		Re = ((p * V * D)/ u);
	
	printf("\nN�mero de reynolds dos valores insiridos: %f\n\n", Re);
	
}

//C�lculo da press�o em fluidos parados
float caso5(){
/*C�lculo da Press�o de Fluidos Parados: ph = d�g�h

ph = Press�o Hidrost�tica 
d = Densidade 
g = Acelera��o da Gravidade
h = Altura*/

	float ph;
	float d, g, h;
	
	printf("\n********************* C�lculo da press�o em fluidos parados (teorema de Stevin) *********************\n");
	
	printf("\nDigite a Densidade: ");
	scanf("%f%*c", &d);
	printf("Digite a Acelera��o da Gravidade: ");
	scanf("%f%*c", &g);
	printf("Digite a Altura: ");
	scanf("%f%*c", &h);
	
		ph = d * g * h;
	
	printf("\nA press�o no fluido parado � de: %.2f\n\n", ph);
}


//c�lculo do empuxo
float caso6(){
/*C�lculo Empuxo: E = �(FLUIDO).V(OBJETO).g
C�lculo Empuxo pela massa: E = massa(FLUIDO).g

E = Empuxo
� = Densidade do fluido
V = Volume do objeto
g = gravidade*/

	float E; 
	float u, V, g, m;
	
	do{
	printf("\n********************* Menu do c�lculo do empuxo *********************\n");
	printf("\n1 - Calculo do empuxo por meio da densidade e volume");
	printf("\n2 - Calculo do empuxo por meio da massa");
	printf("\n3 - Voltar ao menu principal.");
		
		printf("\n\nDigite uma op��o do menu: ");
		scanf("%i%*c", &opcao);
		
		switch(opcao){
			case 1: //Calculo do empuxo por meio da densidade e volume
				printf("\nDigite a Densidade do fluido: ");
				scanf("%f%*c", &u);
				printf("Digite o Volume do objeto do fluido: ");
				scanf("%f%*c", &V);
				printf("Digite a gravidade do objeto do fluido: ");
				scanf("%f%*c", &g);
				
					E = u * V * g;
					
				printf("\nO valor do Empuxo � de: %.2f\n\n", E);
			
				break;
			case 2: //Calculo do empuxo por meio da massa
				printf("\nDigite a Massa do fluido: ");
				scanf("%f%*c", &m);
				printf("Digite a gravidade do objeto do fluido: ");
				scanf("%f%*c", &g);
				
				E = m * g;
					
				printf("\nO valor do Empuxo � de: %.2f\n\n", E);
				
				break;
			case 3: //Voltar ao menu principal.
				break;
		}
	
	if ((opcao != 1)&&(opcao != 2)&&(opcao != 3)){
		printf("\nO que voc� insiriu n�o faz parte do menu. Tente novamente.\n");
		}
		
	}while(opcao != 3);
	
	
}


//Cadastro de Livros de Mec�nica
float cadastro(){
	int j;
	
    /* gerando valores aleat�rios entre zero e 100 */
    srand((unsigned)time(NULL));
	MEFA[indice].codigo = rand() % 100;
    printf("\nC�digo: %i",  MEFA[indice].codigo);
	
	printf("\nDigite o nome do Livro: ");
	gets(MEFA[indice].nome);
	
	printf("Digite o numero de autores: ");
	scanf("%i%*c", &MEFA[indice].numautores);
	
	for(j = 0; j < MEFA[indice].numautores; j++){
		printf("Digite o nome do autor: ");
		gets(MEFA[indice].autor);
	}
	
	printf("Descri��o do Livro: ");
	gets(MEFA[indice].descricao);
	
	printf("Digite a quantidade de Paginas: ");
	scanf("%i%*c", &MEFA[indice].quantpag);
	
	printf("Digite a Quantidade de cap�tulos: ");
	scanf("%i", &MEFA[indice].capitulo);
	
	printf("Digite o pre�o do livro: ");
	scanf("%f", &MEFA[indice].preco);
}

void exibir(){
	int y;
	for (indice = 0; indice < 15; indice++){
	printf("\n\nC�digo: %i", &MEFA[indice].codigo);
	printf("\nNome do Livro: %s", MEFA[indice].nome);
	
	printf("\nNumero de autores: %i\n", MEFA[indice].numautores);
	
	for(y = 0; y < MEFA[indice].numautores; y++){
		printf("Nome do autor: %s\n", MEFA[indice].autor);
	}
	
	printf("Descri��o do Livro: %s", MEFA[indice].descricao);
	
	printf("\nQuantidade de Paginas: %i", MEFA[indice].quantpag);
	
	printf("\nQuantidade de cap�tulos: %i", &MEFA[indice].capitulo);
	
	printf("\nPre�o do livro: %.2f\n\n", &MEFA[indice].preco);
	}
}

void ind(){
	printf("Digite o numero do indice do livro que quer consultar: ");
	scanf("%i", &indice);
	
	printf("\nC�digo: %i", MEFA[indice].codigo);
	printf("\nNome do livro: %s", MEFA[indice].nome);
	printf("\nN�mero de Autores: %i", MEFA[indice].autor);
	printf("\nDescri��o: %s", MEFA[indice].descricao);
	printf("\nQuantidade de Pagina: %i", MEFA[indice].quantpag);
	printf("\nQuantidade de Cap�tulo: %i", MEFA[indice].capitulo);
	printf("\nPre�o: %.2f\n", MEFA[indice].preco);
}

//Alterar itens cadastrados	
void alterar(){
printf("\nN�o deu Certo");	
}

//Excluir itens cadastrados
void excluir(){
printf("\nN�o deu Certo");
} 

//Exibir os itens do vetor em ordem crescente ou decrescente
void algoritimo(){
	
}

//Armazena os dados gravados no vetor no Arquivo
void gravar(){
	
	for(indice = 0; indice<25; indice++){
	fprintf(file, "\nC�digo: %i", MEFA[indice].codigo);
	fprintf(file, "\nNome do livro: %s", MEFA[indice].nome);
	fprintf(file, "\nN�mero de Autores: %i", MEFA[indice].autor);
	fprintf(file, "\nDescri��o: %s", MEFA[indice].descricao);
	fprintf(file, "\nQuantidade de Pagina: %i", MEFA[indice].quantpag);
	fprintf(file, "\nQuantidade de Cap�tulo: %i", MEFA[indice].capitulo);
	fprintf(file, "\nPre�o: %.2f\n", MEFA[indice].preco);
	}
	
	//finalizar arquivo
	fclose(file);
	
	
fclose(file);	
}

//Leitura dos registros do arquivo e armazenagem no vetor
void ler(){
	file = fopen("Dados da struct.txt", "r");
   char dados[400];
   
   while(fgets(dados, 400, file) != NULL)
   {
   	 printf("\nC�digo: %i",  MEFA[indice].codigo);
	 printf("\nNome: %s", MEFA[indice].nome);
	 printf("\nN�mero de Autores: %i", MEFA[indice].autor);
	 printf("\nEndere�o: %s",  MEFA[indice].descricao);
	 printf("\nAno de cadastro: %i", MEFA[indice].quantpag);
	 printf("\nTipo de automa��o: %s\n", MEFA[indice].capitulo);
	 break;
   } 
   fclose(file);
	
}
