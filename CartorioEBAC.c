#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espacos na memoria
#include <locale.h> //alocação de texto por região (acentos)
#include <string.h> //Biblioteca de strings

int incluir()//Função Inculir
{
    
	char arquivo[40];//Variáveis/strings
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	

	printf("Digite o CPF que deseja incluir: ");//Usuário digita o CPF
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
    
    printf("Digite o cargo do usuário a ser incluido: ");//Usurio adiciona o cargo
    scanf("%s" ,cargo);
    
    file = fopen(arquivo, "a");// Salvao cargo no arquivo
    fprintf(file, cargo);
    fclose(file);
    
    printf("Usuário inculido com sucesso!\n");
    system("pause");
}

int consultar()//Funcão consultar
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
    	printf("CPF não encontrado!\n");
    	system("pause");
    	return;//Para voltar ao menu
    
	}
	
	printf("\nEssas são as informações do usuário:\n \n");//Print exibindo as informacoes do usuario
	
	while(fgets(conteudo, 200, file) != NULL)//Se pegar no arquivo um CPF diferente de nulo mostra as informacoes
	{
		printf("%s", conteudo);//Printa o conteudo do arquivo onde esta as informacoes do cpf escolhido
		printf("\n\n");
	}
    
    system("pause");

}

int excluir()//Função excluir
{
	char cpf[40];
	
	printf("Digite o CPF que deseja excluir: ");// Usuario digita o CPF que deseja excluir
	scanf("%s", cpf);
	
    if (remove(cpf) == 0) //Usa o remove junto a variavel cpf para excluir o cpf desejado e faz a verificao ao igualar a 0
    {
        printf("CPF excluído com sucesso\n");
        system("pause");
    }
    else//caso nao iguale a zero, nao ocorreu a exclusao do usuario
    {
        printf("CPF inválido! Usuário não encontrado\n");
        system("pause");
    }
	
}

int sair()
{
	int escolha;

	printf("Deseja mesmo sair do programa? (1 = Sim, 0 = Não): ");//Confirmação de saida
	scanf("%d", &escolha);//Usuário realiza a escolha se deseja ou não sair do programa

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
		printf("Opção inválida!\n");
		return 1;
	}
	
     
}

int padrao()//Função padrão
{
	printf("Opção inválida! Digite uma das opções existentes\n");
    system("pause");
}


int main()
{
	int opcao = 0;//Definindo a variável opcao
	int laco = 1;//Definindo variável laco
	
	for(laco = 1; laco = 1;)//Laço de repetição
	{
	
	system("cls");//Limpar a tela
	
	setlocale(LC_ALL, "portuguese");//Localizando a linguagem
	printf("-=-= Cartório da EBAC =-=- \n\n");//Início do menu
	printf("Selecione uma das três opções abaixo \n\n");
	printf("\t1 **Incluir nome** \n");
	printf("\t2 **Consultar nome** \n ");
	printf("\t3 **Excluir nome** \n");
	printf("\t4 **Sair do programa** \n\n");
	printf("Digite o número da opção desejada: ");

    scanf("%d", &opcao);//Escolha do usuário

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
    	
    	default://Escolha padrão
    	padrao();
    	break;
	}
    }  
}  
