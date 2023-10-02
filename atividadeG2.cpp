#include<stdio.h>//bliblioteca de comunicação com o usuário
#include<stdlib.h>//biblioteca de alocação de espaço de memória
#include<locale.h>//biblioteca de alocação de texto por região
#include<string.h>//biblioteca responsável por cuidar dasstring

int registro()//Função responsavel por cadastrar os usuários no sistema
{
  //Inicio da criação das variáveis/string
  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  //fim da criação das variáveis/string
  
  printf("digite o CPF a ser cadastrado:");//coletando informação do usuário
  scanf("%s",cpf);//Refere-se as string
  
  strcpy(arquivo,cpf);//Responsavel por copiar os valores das string
  
  FILE *file;//Cria o arquivo
  file=fopen(arquivo,"w");//Criar o arquivo e o (w)é de escrever
  fprintf(file,cpf);//Salvar o valor da variavel
  fclose(file);//Fecha o arquivo
  
  file=fopen(arquivo,"a");//Cria o arquivo
  fprintf(file,",");//Salvar o valor da variável e (,)é para a divisão dos caractere da variável
  fclose(file);//Fecha o arquivo
  
  printf("Digite o nome a ser cadastrado:");//Coletando informações do usuário
  scanf("%s",nome);//Refere-se a string
  
  file=fopen(arquivo,"a");//Criar o arquivo
  fprintf(file,nome);//Salvar o valor da variável
  fclose(file);//Fecha o arquivo
  
  file=fopen(arquivo,"a");//Cria o arquivo
  fprintf(file,",");//Salvar o arquivo da variável e (,) é para a divisão dos caractere da variável
  fclose(file);//Fecha o arquivo
  
  printf("Digite o sobrenome a ser cadastrado:");
  scanf("%s",sobrenome);
  
  file=fopen(arquivo,"a");//Cria o arquivo
  fprintf(file,sobrenome);
  fclose(file);//Fecha o arquivo
  
  file=fopen(arquivo,"a");//Cria o arquivo
  fprintf(file,",");
  fclose(file);//Fecha o arquivo
  
  printf("Digite o cargo a ser cadastrado:");
  scanf("%s",cargo);
  
  file=fopen(arquivo,"a");//Cria o arquivo
  fprintf(file,cargo);
  fclose(file);//Fecha o arquivo
  
  system("pause");//sistema de pausa
  	
}
int consulta()
{
	setlocale(LC_ALL,"portuguese");//definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
    printf("Digite o CPF a ser consultado:");
    scanf("%s",cpf);
    
    FILE*file;
    file=fopen(cpf,"r");
    
    if(file==NULL)
    {
    	printf("não foi possivel abrir o arquivo!não localizado!\n");
	}
	
	while(fgets(conteudo,200,file)!=NULL)
	
	{
		printf("\nEssasas são as informações do usuário:");
		printf("%s",conteudo);
		printf("\n\n");
	}
	system("pause");
}
int deletar()
{
   char cpf[40];
   
   printf("Digite o CPF do usuário a ser deletado:");
   scanf("%s",cpf);
   
   remove(cpf);
   
   FILE *file;
   file=fopen(cpf,"r");
   
   if(file==NULL)
   {
   	  printf("O usuário não se encontra no sistema!.\n");
   	  system("pause");
   }
}

int main()
    {
    int opcao=0;//definindo variaveis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
	   system("cls");
	
	   setlocale(LC_ALL,"portuguese");//definindo a linguagem
	
	   printf("###Cartório EBAC###\n\n");//inicio do menu
 	   printf("Escolha a opção desejada do menu\n\n");
	   printf("\t1-Registrar nomes\n");
 	   printf("\t2-Consultar nomes\n");
	   printf("\t3-Deletar nomes\n\n");
	   printf("\t4-Sair do sistema\n\n");
	   printf("opção:");//fim do menu
	
	   scanf("%d",&opcao);
	
	   system("cls");
	   
	   switch(opcao)
	   {
	   	 case 1:
	   	 registro();
		 break;
		 
		 case 2:
		 consulta();
		 break;
		
		 case 3:
		 deletar();
		 break;
		
		 case 4:
		 printf("obrigado por utilizar o sistema!\n");
		 return 0;
		 break;
		 	
		 default:
		 printf("Essa opção não está disponivel\n");
		 system("pause");
		 break; 
	   }
	
	  
    }
}
