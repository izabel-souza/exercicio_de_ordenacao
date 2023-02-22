#include <stdio.h> 
#include <stdlib.h> 

int *inicializacao_vetor (int n);
void atribuicao_vetor(int n, int *vetor);
void impressao(int n, int *vetor);
void bolha(int n, int *vetor);

int main (void) {

    int n;
    do {
        printf("Informe o numero de elementos no vetor: ");
        scanf("%d", &n);
    }while(n < 0);

    int *vet = inicializacao_vetor(n);
    atribuicao_vetor(n, vet);
    printf("Vetor Original: \n");
    impressao(n, vet);
    bolha(n, vet);
    printf("Vetor Ordenado com Bubble Sort: \n");
    impressao(n, vet);
    
    return 0;
}

int *inicializacao_vetor(int n) {

    int *vet = (int *) malloc(n * sizeof(int));
    if(vet == NULL) { printf("Falta de memoria"); exit(1); }

    return vet;
}

void atribuicao_vetor(int n, int *vetor) {
    for(int i = 0; i < n; i++) {
        printf("Informe o elemento %d do vetor: ", i+1);
        scanf("%d", &vetor[i]);
    }
}

void impressao(int n, int *vetor) {
    for(int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void bolha(int n, int *vetor) {

    for(int fim = n-1; fim > 0; fim--) {
        for(int i = 0; i < fim; i++) {
            if(vetor[i] > vetor[i+1]) {
                int temp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = temp;
            }
        }
    }
}