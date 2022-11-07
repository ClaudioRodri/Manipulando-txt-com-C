/**************************************************************************************************************************************************************
PROGRAMA1

	Nome e prontuário: 
		- Cláudio Rodrigues 
	
	Data 28/07/21 20:46
	
	Descrição: o programa resolve problemas da área de mecânica dos fluidos
		- Conversão de unidades de medida
		- Calculos de propriedades dos fluidos
		- Calculo de vazão
		- Calculo do número de reynolds
		- Calculo da pressão em fuidos parados
		- calculo da força em fluidos parados
		- calculo do empuxo 
	
***************************************************************************************************************************************************************/

//bibliotecas
#include<stdio.h> //biblioteca padrão
#include<string.h> //biblioteca string
#include<stdlib.h> //Para utilizar a função srand
#include <ctype.h> //biblioteca que faz funcionar o toupper()
#include<locale.h> //biblioteca para configurar acentuaçõa
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

//Protótipo
float caso1(); //Conversão de unidades de medida
float caso2(); //Cálculos de propriedades dos fluidos
float caso3(); //Cálculo de vazão
float caso4(); //Cálculo do número de reynolds
float caso5(); //Cálculo da pressão em fluidos parados utilizando o teorema de Stevin
float caso6(); //cálculo do empuxo
float cadastro(); //Cadastro de Livros de Mecânica
void exibir(); //Consultar os registros armazenados
void ind(); //Consulta individual de um item cadastrado
void alterar(); //Alterar itens cadastrados
void excluir(); //Excluir itens cadastrados
void algoritimo(); //Exibir os itens do vetor em ordem crescente ou decrescente
void gravar(); //Armazena os dados gravados no vetor no Arquivo
void ler(); //Leitura dos registros do arquivo e armazenagem no vetor




//variaveis globais
int menu; //opção escolhida do menu principal pelo usuário
int opcao; //opção escolhida do menu secundário pelo usuário
int indice;
int contador = 0;
FILE *file;


//função principal
int main(){
	
	
	setlocale(LC_ALL, "Portuguese");//configura a localização
	
	
	do{
	file = fopen("Dados da struct.txt", "a");
	printf("\n******************************************* MENU PRINCIPAL *******************************************\n\n");	
		
		printf("1 - Conversão de unidades de medida");
		printf("\n2 - Cálculos de propriedades dos fluidos");
		printf("\n3 - Cálculo de vazão");
		printf("\n4 - Cálculo do número de reynolds");
		printf("\n5 - Cálculo da pressão em fluidos parados (teorema de Stevin)");
		printf("\n6 - cálculo do empuxo");
		printf("\n7 - Cadastro de Livros de Mecânica");
		printf("\n8 - Consultar os registros armazenados");
		printf("\n9 - Consulta individual de um item cadastrado");
		printf("\n10 - Alterar itens cadastrados");
		printf("\n11 - Excluir itens cadastrados");
		printf("\n12 - Exibir os itens do vetor em ordem crescente ou decrescente");
		printf("\n13 - Armazena os dados gravados no vetor no Arquivo");
		printf("\n14 - Leitura dos registros do arquivo e armazenagem no vetor");
		printf("\nF - Finalizar Programa.\n");
		
		printf("\nDigite a opção desejada: ");
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
		case 'F': printf("\nPrograma finalizado. Agradecemos a preferência.");
			break;
		
		default:
			printf("O que você insiriu não faz parte do menu. Tente novamente.\n\n");
			
	}
	
	
		
		
	}while(menu != 'F');
	
	
return 0;
}

//funções
//Conversão de unidades de medida
float caso1(){
	int num;
	float q, m, g, s, h, c, mc, ml, l;
	float result;
	
	do{
		printf("\n********************* Menu das Conversões de unidades de medida *********************\n"); //MENU DAS CONVERSOES
		printf("\n1 - Tempo");//calculos de conversão do tempo
		printf("\n2 - Massa");
		printf("\n3 - Comprimento");
		printf("\n4 - Volume");
		printf("\n5 - Voltar ao menu principal.");
		
		printf("\n\nDigite uma opção do menu: ");
		scanf("%i%*c", &opcao);
		
		
		switch(opcao){
		case 1:
		printf("\nVocê deseja converter:\n");
		printf("\n1 - Segundos para Horas");
		printf("\n2 - Hora para Segundos");
		printf("\n3 - Minutos para Segundos");
		printf("\n4 - Segundos para Minutos");
		printf("\n5 - Horas para Minutos");
		printf("\n6 - Minutos para Horas");
		
		printf("\n\nDigite a opção escolhida: ");
		scanf("%i%*c", &num);
		
		if(num == 1){
			printf("\nDigite o valor em segundos: ");
			scanf("%f%*c", &s);
			
		result = s/3600;
		
		printf("\nO numéro inserido em horas é igual a: %f\n\n", result);
		}
		
		else if(num == 2){
			printf("\nDigite o valor em Horas: ");
			scanf("%f%*c", &h);
			
		result = h * 3600.00;
		
		printf("\nO numéro inserido em segudos é igual a: %.2f\n\n", result);
		}
		
		else if(num == 3){
			printf("\nDigite o valor em minutos: ");
			scanf("%f%*c", &m);
			
		result = m * 60.00;
		
		printf("\nO numéro inserido em segudos é igual a: %.2f\n\n", result);
		}
		
		else if(num == 4){
			printf("\nDigite o valor em Segundos: ");
			scanf("%f%*c", &h);
			
		result = s / 60.00;
		
		printf("\nO numéro inserido em Minutos é igual a: %.2f\n\n", result);
		}
		
		else if(num == 5){
			printf("\nDigite o valor em Horas: ");
			scanf("%f%*c", &h);
				
			result = h * 60.00;
			
			printf("\nO numéro inserido em Minutos é igual a: %.2f\n\n", result);
			}
			
		else if(num == 6){
			printf("\nDigite o valor em minutos: ");
			scanf("%f%*c", &m);
			
			result = m / 60.00;
		
			printf("\nO numéro inserido em horas é igual a: %.2f\n\n", result);
		}
		
		break;
			
		case 2:  //massa
		printf("\nVocê deseja converter:\n");
		printf("\n1 - Quilogramas para gramas");
		printf("\n2 - Gramas para Quilogramas");
		printf("\n3 - Miligramas para Gramas");
		printf("\n4 - Gramas para Miligramas");
		printf("\n5 - Miligramas para Quilogramas");
		printf("\n6 - Quilogramas para Miligramas");
		
		printf("\n\nDigite a opção escolhida: ");
		scanf("%i%*c", &num);
		
		
			switch(num){
				case 1: //Quilogramas para gramas
					printf("\nDigite o valor em Quilogramas: ");
					scanf("%f%*c", &q);
					
						result = q * 1000.00;
					
					printf ("\nO valor em gramas é igual a: %.2f\n\n", result);
				
					break;
				case 2: //Gramas para Quilogramas
					printf("\nDigite o valor em gramas: ");
					scanf("%f%*c", &g);
					
						result = g / 1000.00;
					
					printf ("\nO valor em Quilogramas é igual a: %f\n\n", result);
				
					break;
				case 3: //Miligramas para Gramas
					printf("\nDigite o valor em Miligramas: ");
					scanf("%f%*c", &m);
					
						result = m / 1000.00;
					
					printf ("\nO valor em gramas é igual a: %f\n\n", result);
				
					break;
				case 4: //Gramas para Miligramas
					printf("\nDigite o valor em gramas: ");
					scanf("%f%*c", &g);
					
						result = g * 1000.00;
					
					printf ("\nO valor em Miligramas é igual a: %.2f\n\n", result);
					
					break;
				case 5: //Miligramas para Quilogramas
					printf("\nDigite o valor em Miligramas: ");
					scanf("%f%*c", &m);
					
						result = m / 1000000.00;
					
					printf ("\nO valor em Quilogramas é igual a: %f\n\n", result);
					
					break;
				case 6: //Quilogramas para Miligramas
					printf("\nDigite o valor em Quilogramas: ");
					scanf("%f%*c", &q);
					
						result = q * 1000000.00;
					
					printf ("\nO valor em Miligramas é igual a: %.2f\n\n", result);
					
					break;
			}
		
			break;
		case 3: //comprimento
		printf("\nVocê deseja converter:\n");
		printf("\n1 - Metros para centímetros");
		printf("\n2 - Centímetros para Metros");
		printf("\n3 - Metros para Quilômetros");
		printf("\n4 - Quilômetros para Metros");
		printf("\n5 - Centímetros para Quilômetros");
		printf("\n6 - Quilômetros para Centímetros");
		
		printf("\n\nDigite a opção escolhida: ");
		scanf("%i%*c", &num);
		
		
			switch(num){
				case 1: //Metros para centímetros
					printf("\nDigite o valor em Metros: ");
					scanf("%f%*c", &m);
					
						result = m * 100.00;
					
					printf ("\nO valor em centímetros é igual a: %.2f\n\n", result);
				
					break;
				case 2: //Centímetros para Metros
					printf("\nDigite o valor em Centímetros: ");
					scanf("%f%*c", &c);
					
						result = c / 100.00;
					
					printf ("\nO valor em Metros é igual a: %f\n\n", result);
				
					break;
				case 3: //Metros para Quilômetros
					printf("\nDigite o valor em Metros: ");
					scanf("%f%*c", &m);
					
						result = m / 1000.00;
					
					printf ("\nO valor em Quilômetros é igual a: %f\n\n", result);
				
					break;
				case 4: //Quilômetros para Metros
					printf("\nDigite o valor em Quilômetros: ");
					scanf("%f%*c", &q);
					
						result = q * 1000.00;
					
					printf ("\nO valor em Metros é igual a: %.2f\n\n", result);
					
					break;
				case 5: //Centímetros para Quilômetros
					printf("\nDigite o valor em Centímetros: ");
					scanf("%f%*c", &c);
					
						result = c / 100000.00;
					
					printf ("\nO valor em Quilômetros é igual a: %f\n\n", result);
					
					break;
				case 6: //Quilômetros para Centímetros
					printf("\nDigite o valor em Quilômetros: ");
					scanf("%f%*c", &q);
					
						result = q * 100000.00;
					
					printf ("\nO valor em Centímetros é igual a: %.2f\n\n", result);
					
					break;
			}
			
			break;
			
		case 4: //Volume
		printf("\nVocê deseja converter:\n");
		printf("\n1 - Metros Cúbicos para Litros");
		printf("\n2 - Litros para Metros Cúbicos");
		printf("\n3 - Metros Cúbicos para mililitros");
		printf("\n4 - Mililitros para Metros Cúbicos");
		printf("\n5 - Mililitros para Litros");
		printf("\n6 - Litros para Mililitros");
		
		printf("\n\nDigite a opção escolhida: ");
		scanf("%i%*c", &num);
		
		
			switch(num){
				case 1: //Metros Cúbicos para Litros
					printf("\nDigite o valor em Metros Cúbicos: ");
					scanf("%f%*c", &mc);
					
						result = mc * 1000.00;
					
					printf ("\nO valor em Litros é igual a: %.2f\n\n", result);
				
					break;
				case 2: //Litros para Metros Cúbicos
					printf("\nDigite o valor em Litros: ");
					scanf("%f%*c", &l);
					
						result = l / 1000.00;
					
					printf ("\nO valor em Metros Cúbicos é igual a: %f\n\n", result);
				
					break;
				case 3: //Metros Cúbicos para mililitros
					printf("\nDigite o valor em Metros Cúbicos: ");
					scanf("%f%*c", &mc);
					
						result = mc * 1000000.00;
					
					printf ("\nO valor em Mililitros é igual a: %.2f\n\n", result);
				
					break;
				case 4: //Mililitros para Metros Cúbicos
					printf("\nDigite o valor em Mililitros: ");
					scanf("%f%*c", &ml);
					
						result = ml / 1000000.00;
					
					printf ("\nO valor em Metros Cúbicos é igual a: %f\n\n", result);
					
					break;
				case 5: //Mililitros para Litros
					printf("\nDigite o valor em Mililitros: ");
					scanf("%f%*c", &ml);
					
						result = ml / 1000.00;
					
					printf ("\nO valor em Litros é igual a: %f\n\n", result);
					
					break;
				case 6: //Litros para Mililitros
					printf("\nDigite o valor em Litros: ");
					scanf("%f%*c", &l);
					
						result = l * 1000.00;
					
					printf ("\nO valor em Mililitros é igual a: %.2f\n\n", result);
					
					break;
			}
			
			
			break;
			
		case 5: //Voltar ao menu principal
			break;
		}
		
		
		if ((opcao != 1)&&(opcao != 2)&&(opcao != 3)&&(opcao != 4)&&(opcao != 5)){
		printf("\nO que você insiriu não faz parte do menu. Tente novamente.\n");
		}
		
		}while(opcao != 5);
	
	}
	
//Cálculos de propriedades dos fluidos
float caso2(){
	
	float ME, PE, VE, CP, EL;
	float ms, vl, ps;
	
	do{
	printf("\n********************* Menu do Cálculos de propriedades dos fluidos *********************\n");
		printf("\n1 - Cálculo da massa específica");
		printf("\n2 - Cálculo do peso específico");
		printf("\n3 - Cálculo do volume específico");
		printf("\n4 - Voltar ao menu principal.\n");
		
			printf("\nDigite a opção desejada: ");
			scanf("%i%*c", &opcao);
			
			switch(opcao){
				case 1: //Cálculo da massa específica
				printf("\nDigite a massa: ");
				scanf("%f%*c", &ms);
				printf("Digite o Volume: ");
				scanf("%f%*c", &vl);
				
					ME = ms / vl;
				
					printf("\nA massa específica é de: %f\n\n", ME);
					break;
					
				case 2: //Cálculo do peso específico
				printf("\nDigite o Peso: ");
				scanf("%f%*c", &ps);
				printf("Digite o Volume: ");
				scanf("%f%*c", &vl);
				
					PE = ps / vl;
				
					printf("\nO peso específico é de: %f\n\n", PE);
					break;
					
				case 3: //Cálculo do volume específico
				printf("\nDigite o Volume total: ");
				scanf("%f%*c", &vl);
				printf("Digite a Massa total: ");
				scanf("%f%*c", &ms);
				
					VE = vl / ms;
				
					printf("\nO Volume específico é de: %f\n\n", VE);
					break;
					
				case 4: //Voltar ao menu principal
					break;
			}
			
		if ((opcao != 1)&&(opcao != 2)&&(opcao != 3)&&(opcao != 4)){
		printf("\nO que você insiriu não faz parte do menu. Tente novamente.\n");
		}
			
	}while(opcao != 4);
	
}
	

//Cálculo de vazão
float caso3(){
/*Cálculo de Vazão em Volume: Q = v•A
Cálculo de Vazão em Massa: Qm = ?m/?y
Cálculo da Vazão por meio do volume e tempo: Q = V / t 

Q = Vazão
v = velocidade média global do fluido no conduto
A = área da seção transversal do conduto
Qm = Vazão em Massa
?m = quantidade (massa) de fluido deslocado no intervalo de tempo considerado
?t = intervalo de tempo considerado
V = Volume
t = tempo
*/

	
	do{
		printf("\n********************* Menu do Calculo da Vazão *********************\n");
		printf("\n1 - Cálculo da Vazão por meio da velocidade e área da seção transversal do conduto");
		printf("\n2 - Cálculo da Vazão por meio do volume e tempo");
		printf("\n3 - Cálculo de Vazão em Massa");
		printf("\n4 - Voltar ao menu principal.");
		
		printf("\n\nDigite uma opção do menu: ");
		scanf("%i%*c", &opcao);
		
		float vazao, massa, velocidade, area, tempo, volume;
		switch(opcao){
		case 1: //Cálculo da Vazão por meio da velocidade e área da seção transversal do conduto
			printf("\nDigite a velocidade média global do fluido no conduto: ");
			scanf("%f%*c", &velocidade);
			printf("Digite a área da seção transversal do conduto: ");
			scanf("%f%*c", &area);
			
			vazao = velocidade * area;
			
			printf("\nA vazão é igua a: %.2f\n\n", vazao);
			
			break;
		case 2: //Cálculo da Vazão por meio do volume e tempo
			printf("\nDigite o volume: ");
			scanf("%f%*c", &volume);
			printf("Digite o tempo: ");
			scanf("%f%*c", &tempo);
			
			vazao = volume/tempo;
			
			printf("\nA vazão é igua a: %.2f\n\n", vazao);
			
			break;
		case 3: //Cálculo de Vazão em Massa
			printf("\nDigite a quantidade (massa) de fluido deslocado no intervalo de tempo considerado: ");
			scanf("%f%*c", &massa);
			printf("Digite o intervalo de tempo considerado: ");
			scanf("%f%*c", &tempo);
			
			vazao = massa / tempo;
			
			printf("\nA vazão é igua a: %.2f\n\n", vazao);
			
			break;
		case 4: //Voltar ao menu principal
			break;
		}
		
		
		if ((opcao != 1)&&(opcao != 2)&&(opcao != 3)&&(opcao != 4)){
		printf("\nO que você insiriu não faz parte do menu. Tente novamente.\n");
		}
		
		}while(opcao != 4);	
}

//Cálculo do número de reynolds
float caso4(){
/*Cálculo do Número de Reynolds: Re = pVD/µ

Re = Número de Reynolds
p = Massa Específica do Fluído 
V = Velocidade Média 
D = Diâmetro Hidráulico
µ = Viscosidade Dinâmica do Fluído*/

	float Re;
	float p, V, D, u;
	
	printf("\n********************* Cálculo do número de reynolds *********************\n");
	
	printf("\nDigite a Massa Específica do Fluído: ");
	scanf("%f%*c", &p);
	printf("Digite a Velocidade Média: ");
	scanf("%f%*c", &V);
	printf("Digite a Diâmetro Hidráulico: ");
	scanf("%f%*c", &D);
	printf("Digite a Viscosidade Dinâmica do Fluído: ");
	scanf("%f%*c", &u);
	
		Re = ((p * V * D)/ u);
	
	printf("\nNúmero de reynolds dos valores insiridos: %f\n\n", Re);
	
}

//Cálculo da pressão em fluidos parados
float caso5(){
/*Cálculo da Pressão de Fluidos Parados: ph = d•g•h

ph = Pressão Hidrostática 
d = Densidade 
g = Aceleração da Gravidade
h = Altura*/

	float ph;
	float d, g, h;
	
	printf("\n********************* Cálculo da pressão em fluidos parados (teorema de Stevin) *********************\n");
	
	printf("\nDigite a Densidade: ");
	scanf("%f%*c", &d);
	printf("Digite a Aceleração da Gravidade: ");
	scanf("%f%*c", &g);
	printf("Digite a Altura: ");
	scanf("%f%*c", &h);
	
		ph = d * g * h;
	
	printf("\nA pressão no fluido parado é de: %.2f\n\n", ph);
}


//cálculo do empuxo
float caso6(){
/*Cálculo Empuxo: E = µ(FLUIDO).V(OBJETO).g
Cálculo Empuxo pela massa: E = massa(FLUIDO).g

E = Empuxo
µ = Densidade do fluido
V = Volume do objeto
g = gravidade*/

	float E; 
	float u, V, g, m;
	
	do{
	printf("\n********************* Menu do cálculo do empuxo *********************\n");
	printf("\n1 - Calculo do empuxo por meio da densidade e volume");
	printf("\n2 - Calculo do empuxo por meio da massa");
	printf("\n3 - Voltar ao menu principal.");
		
		printf("\n\nDigite uma opção do menu: ");
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
					
				printf("\nO valor do Empuxo é de: %.2f\n\n", E);
			
				break;
			case 2: //Calculo do empuxo por meio da massa
				printf("\nDigite a Massa do fluido: ");
				scanf("%f%*c", &m);
				printf("Digite a gravidade do objeto do fluido: ");
				scanf("%f%*c", &g);
				
				E = m * g;
					
				printf("\nO valor do Empuxo é de: %.2f\n\n", E);
				
				break;
			case 3: //Voltar ao menu principal.
				break;
		}
	
	if ((opcao != 1)&&(opcao != 2)&&(opcao != 3)){
		printf("\nO que você insiriu não faz parte do menu. Tente novamente.\n");
		}
		
	}while(opcao != 3);
	
	
}


//Cadastro de Livros de Mecânica
float cadastro(){
	int j;
	
    /* gerando valores aleatórios entre zero e 100 */
    srand((unsigned)time(NULL));
	MEFA[indice].codigo = rand() % 100;
    printf("\nCódigo: %i",  MEFA[indice].codigo);
	
	printf("\nDigite o nome do Livro: ");
	gets(MEFA[indice].nome);
	
	printf("Digite o numero de autores: ");
	scanf("%i%*c", &MEFA[indice].numautores);
	
	for(j = 0; j < MEFA[indice].numautores; j++){
		printf("Digite o nome do autor: ");
		gets(MEFA[indice].autor);
	}
	
	printf("Descrição do Livro: ");
	gets(MEFA[indice].descricao);
	
	printf("Digite a quantidade de Paginas: ");
	scanf("%i%*c", &MEFA[indice].quantpag);
	
	printf("Digite a Quantidade de capítulos: ");
	scanf("%i", &MEFA[indice].capitulo);
	
	printf("Digite o preço do livro: ");
	scanf("%f", &MEFA[indice].preco);
}

void exibir(){
	int y;
	for (indice = 0; indice < 15; indice++){
	printf("\n\nCódigo: %i", &MEFA[indice].codigo);
	printf("\nNome do Livro: %s", MEFA[indice].nome);
	
	printf("\nNumero de autores: %i\n", MEFA[indice].numautores);
	
	for(y = 0; y < MEFA[indice].numautores; y++){
		printf("Nome do autor: %s\n", MEFA[indice].autor);
	}
	
	printf("Descrição do Livro: %s", MEFA[indice].descricao);
	
	printf("\nQuantidade de Paginas: %i", MEFA[indice].quantpag);
	
	printf("\nQuantidade de capítulos: %i", &MEFA[indice].capitulo);
	
	printf("\nPreço do livro: %.2f\n\n", &MEFA[indice].preco);
	}
}

void ind(){
	printf("Digite o numero do indice do livro que quer consultar: ");
	scanf("%i", &indice);
	
	printf("\nCódigo: %i", MEFA[indice].codigo);
	printf("\nNome do livro: %s", MEFA[indice].nome);
	printf("\nNúmero de Autores: %i", MEFA[indice].autor);
	printf("\nDescrição: %s", MEFA[indice].descricao);
	printf("\nQuantidade de Pagina: %i", MEFA[indice].quantpag);
	printf("\nQuantidade de Capítulo: %i", MEFA[indice].capitulo);
	printf("\nPreço: %.2f\n", MEFA[indice].preco);
}

//Alterar itens cadastrados	
void alterar(){
printf("\nNão deu Certo");	
}

//Excluir itens cadastrados
void excluir(){
printf("\nNão deu Certo");
} 

//Exibir os itens do vetor em ordem crescente ou decrescente
void algoritimo(){
	
}

//Armazena os dados gravados no vetor no Arquivo
void gravar(){
	
	for(indice = 0; indice<25; indice++){
	fprintf(file, "\nCódigo: %i", MEFA[indice].codigo);
	fprintf(file, "\nNome do livro: %s", MEFA[indice].nome);
	fprintf(file, "\nNúmero de Autores: %i", MEFA[indice].autor);
	fprintf(file, "\nDescrição: %s", MEFA[indice].descricao);
	fprintf(file, "\nQuantidade de Pagina: %i", MEFA[indice].quantpag);
	fprintf(file, "\nQuantidade de Capítulo: %i", MEFA[indice].capitulo);
	fprintf(file, "\nPreço: %.2f\n", MEFA[indice].preco);
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
   	 printf("\nCódigo: %i",  MEFA[indice].codigo);
	 printf("\nNome: %s", MEFA[indice].nome);
	 printf("\nNúmero de Autores: %i", MEFA[indice].autor);
	 printf("\nEndereço: %s",  MEFA[indice].descricao);
	 printf("\nAno de cadastro: %i", MEFA[indice].quantpag);
	 printf("\nTipo de automação: %s\n", MEFA[indice].capitulo);
	 break;
   } 
   fclose(file);
	
}
