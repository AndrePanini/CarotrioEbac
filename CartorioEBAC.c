#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espacos na memoria
#include <locale.h> //aloca��o de texto por regi�o (acentos)
#include <string.h> //Biblioteca de strings

int incluir()//Fun��o Inculir
{
    
	char arquivo[40];//Vari�veis/strings
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	

	printf("Digite o CPF que deseja incluir: ");//Usu�rio digita o CPF
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);//Responsavel para copiar os valores do CPF para o arquivo
	
	
    FILE* file;//Cria o arquivo file
    file = fopen(arquivo, "w");//abre o arquivo file e escreve o CPF
    fprintf(file,cpf);//printa o CPF dentro do arquivo file
    fclose(file);//fecha o arquivo file
    
    file = fopen(arquivo, "a");
    fprintf(file, "\n");//Pula a linha dentro do arquivo com as informacoes do cliente
    fclose(file);
    
    printf("Digite o nome a ser incluido: ");//Usuario digita o nome 
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");//Salva o nome no arquivo
    fprintf(file, nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, "\n");
    fclose(file);
    
    printf("Digite o sobrenome a ser incluido: ");//Usuario digita o sobrenome
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");//Salva o sobrenome no arquivo
    fprintf(file, sobrenome);
    fclose(file);
    
    
    file = fopen(arquivo, "a");
    fprintf(file, "\n");
    fclose(file);
    
    printf("Digite o cargo do usu�rio a ser incluido: ");//Usurio adiciona o cargo
    scanf("%s" ,cargo);
    
    file = fopen(arquivo, "a");// Salvao cargo no arquivo
    fprintf(file, cargo);
    fclose(file);
    
    printf("Usu�rio inculido com sucesso!\n");
    system("pause");
}

int consultar()//Func�o consultar
{
	setlocale(LC_ALL, "portuguese");//Localizando a linguagem
		
	char cpf[40]; 
    char conteudo[200];
    
    printf("Digite o CPF que deseja consultar: ");
    scanf("%s", cpf);
    
    FILE* file;
    file = fopen(cpf, "r");//Usar o r para ler o arquivo
    
    if(file == NULL)//se o arquivo for igual a nulo == CPF nao encontrado
    {
    	printf("CPF n�o encontrado!\n");
    	system("pause");
    	return;//Para voltar ao menu
    
	}
	
	printf("\nEssas s�o as informa��es do usu�rio:\n \n");//Print exibindo as informacoes do usuario
	
	while(fgets(conteudo, 200, file) != NULL)//Se pegar no arquivo um CPF diferente de nulo mostra as informacoes
	{
		printf("%s", conteudo);//Printa o conteudo do arquivo onde esta as informacoes do cpf escolhido
		printf("\n\n");
	}
    
    system("pause");

}

int excluir()//Fun��o excluir
{
	char cpf[40];
	
	printf("Digite o CPF que deseja excluir: ");// Usuario digita o CPF que deseja excluir
	scanf("%s", cpf);
	
    if (remove(cpf) == 0) //Usa o remove junto a variavel cpf para excluir o cpf desejado e faz a verificao ao igualar a 0
    {
        printf("CPF exclu�do com sucesso\n");
        system("pause");
    }
    else//caso nao iguale a zero, nao ocorreu a exclusao do usuario
    {
        printf("CPF inv�lido! Usu�rio n�o encontrado\n");
        system("pause");
    }
	
}

int sair()
{
	int escolha;

	printf("Deseja mesmo sair do programa? (1 = Sim, 0 = N�o): ");//Confirma��o de saida
	scanf("%d", &escolha);//Usu�rio realiza a escolha se deseja ou n�o sair do programa

	if (escolha == 1)//Escolha 1
	{
		printf("Obrigado por usar o nosso programa!\n");
		return 0;
	}
	else if (escolha == 0)//Escolha 0
	{
		return 1;
	}
	else
	{
		printf("Op��o inv�lida!\n");
		return 1;
	}
	
     
}

int padrao()//Fun��o padr�o
{
	printf("Op��o inv�lida! Digite uma das op��es existentes\n");
    system("pause");
}


int main()
{
	int opcao = 0;//Definindo a vari�vel opcao
	int laco = 1;//Definindo vari�vel laco
	
	for(laco = 1; laco = 1;)//La�o de repeti��o
	{
	
	system("cls");//Limpar a tela
	
	setlocale(LC_ALL, "portuguese");//Localizando a linguagem
	printf("-=-= Cart�rio da EBAC =-=- \n\n");//In�cio do menu
	printf("Selecione uma das tr�s op��es abaixo \n\n");
	printf("\t1 **Incluir nome** \n");
	printf("\t2 **Consultar nome** \n ");
	printf("\t3 **Excluir nome** \n");
	printf("\t4 **Sair do programa** \n\n");
	printf("Digite o n�mero da op��o desejada: ");

    scanf("%d", &opcao);//Escolha do usu�rio

    system("cls");//Limpar a tela
    
    switch(opcao)//Switch case para diferentes possibilidades de escolha
    
    {
    	case 1://Escolha 1
    	incluir();
    	break;
    	
    	case 2://Escolha 2
    	consultar();
    	break;
    	
    	case 3://Escolha 3
    	excluir();
    	break;
    	
    	case 4://Escolha 4
    	if (sair() == 0)
    	{
    		return 0;
		}
    	
    	break;
    	
    	default://Escolha padr�o
    	padrao();
    	break;
	}
    }  
}  
