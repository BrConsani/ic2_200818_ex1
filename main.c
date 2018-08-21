#include<stdio.h>
#include<stdlib.h>

struct RegFunc{
	int numeroMatricula;
	int idade;
	struct RegFuc *prox;	
};

void registrarFunc(struct RegFunc **listaRFunc){
	struct RegFunc *aux;
	aux = malloc(sizeof(struct RegFunc));
	printf("\nRegistrando funcionario...\n");
	printf("Digite o numero da matricula (1-10): ");
	scanf("%d", &aux->numeroMatricula);
	printf("Digite a idade: ");
	scanf("%d", &aux->idade);
	printf("\n");
	if(*listaRFunc == NULL){
		aux->prox = *listaRFunc;
		*listaRFunc = aux;
	}else{
		struct RegFunc *a, *ant=NULL;
		a = *listaRFunc;
		while(aux->numeroMatricula > a->numeroMatricula){
			ant=a;
			if(a->prox == NULL){
				a=NULL;
				break;
			}else{
				a=a->prox;
			}
		}
		aux->prox=a;
		if(ant == NULL){
			*listaRFunc = aux;
		}else{
			ant->prox=aux;	
		}
	}		
}

void visualizarRegistro(struct RegFunc *listaRFunc){
	struct RegFunc *aux;
	aux=listaRFunc;
	while(1){		
		printf("\nMatricula: %i\n", aux->numeroMatricula);
		printf("Idade: %i\n\n", aux->idade);
		if(aux->prox == NULL){
			break;
		}
		aux=aux->prox;
	}
}

main(){
	
	struct RegFunc *listaRFunc = NULL;
	int acao;
	
	do{
		printf("Escolha uma opcao:\n");
		printf("0. Sair\n");
		printf("1. Registrar\n");
		printf("2. Visualizar Funcionario\n");		
		printf("command: ");
		scanf("%i", &acao);
		
		if(acao == 1){
			registrarFunc(&listaRFunc);					
		}else if(acao == 2){
			visualizarRegistro(listaRFunc);
		}		
	}while(acao != 0);
			
}
