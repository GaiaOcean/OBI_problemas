#define MaxPilha 500
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int topo;
	int array[MaxPilha];
}Pilha;

Pilha criarPilha();
Pilha push(Pilha,int);
int peek(Pilha);
int numeros_da_sequencia(int arr[],int);

int main(){
    int tamanho_array,numero, qtd_numeros = 0;
    
	FILE *file  =  fopen("input.txt", "r");
	if(file == NULL){
		printf("Erro ao ler o arquivo");
		return 1;
	}

	fscanf(file,"%d", &tamanho_array );

	int array[tamanho_array];
	
	for(int i = 0; i < tamanho_array; i++){
		fscanf(file,"%d", &numero);
		array[i] = numero;
	}
	
	fclose(file);
	
	qtd_numeros = numeros_da_sequencia(array,tamanho_array);
	printf("%d", qtd_numeros);

	return 0;
}

Pilha criarPilha(){
	Pilha stack;
	stack.topo = 0;
	
	return stack;
}

Pilha push(Pilha stack, int item){
	if(stack.topo != MaxPilha - 1){
		stack.array[stack.topo] = item;
		stack.topo++;
	}
	return stack;
}


int peek(Pilha stack){
	int topo = -1;
	if(stack.topo > 0){
     	topo = stack.array[stack.topo - 1];
	}	
	return topo;	
}

int numeros_da_sequencia(int array[],int tamanho){
	Pilha stack = criarPilha();
	stack = push(stack, array[0]);
	int sequencia = 1;
	
	for(int i = 1; i < tamanho; i++){
		if(peek(stack) != array[i]){
			stack = push(stack,array[i]);
			sequencia++;
		}
	}
	return sequencia;
}
