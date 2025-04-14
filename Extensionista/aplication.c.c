#include <stdio.h>
#include <stdlib.h>

#define MAX_M 500
#define MAX_N 500

int numero_pedidos_feitos(int matriz[MAX_M][MAX_N],FILE *file, int pedidos_feitos);

int main() {
    int M, N;
    FILE *file = fopen("estoque.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Read M and N
    fscanf(file, "%d %d", &M, &N);
	int matriz[M][N];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(file, "%d", &matriz[i][j]);
        }
    }


    int pedidos_feitos;
    fscanf(file, "%d", &pedidos_feitos);
	
	printf("Matriz original:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
	int n =  numero_pedidos_feitos(matriz,file,pedidos_feitos);

	printf("Matriz Modificada");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    fclose(file);
    
    return 0;
}

int numero_pedidos_feitos(int matriz[MAX_M][MAX_N], FILE *file, int pedidos_feitos) {
    int pecas_vendidas = 0;

    for (int i = 0; i < pedidos_feitos; i++) {
        int col, lin;
        fscanf(file, "%d %d", &col, &lin);

        col--;  // converting from 1-based to 0-based index
        lin--;

        if (matriz[lin][col] > 0) {
            matriz[lin][col]--;
            pecas_vendidas++;
        }
    }

    return pecas_vendidas;
}