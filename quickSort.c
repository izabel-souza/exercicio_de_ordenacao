#include <stdio.h> 
#include <stdlib.h> 

int *inicializacao_vetor (int n);
void atribuicao_vetor(int n, int *vetor);
void impressao(int n, int *vetor);
void rapida(int n, int *vetor);

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
    rapida(n, vet);
    printf("Vetor Ordenado com Quick Sort: \n");
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

void rapida(int n, int *vetor) {

   if(n > 1) {
    int x = vetor[0], a = 1, b = n - 1;
    do {
        while((a < n) && (vetor[a] <= x)) { a++; }
        while(vetor[b] > x) { b--; }
        if(a < b) {
            int temp = vetor[a];
            vetor[a] = vetor[b];
            vetor[b] = temp;
            a++, b--;
        }
    } while(a <= b);

    vetor[0] = vetor[b];
    vetor[b] = x;

    rapida(b, vetor);
    rapida(n-a, &vetor[a]);
   }
}
