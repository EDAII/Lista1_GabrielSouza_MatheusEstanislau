#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 100

int buscaBin(int vetor[], int esquerda, int direita, int valor);
int buscaSeq(int vetor[], int valor);

int main()
{
    int numBusca,
        menu,
        indice,
        vetor[DIM];
    clock_t inicio,
            fim;

    //Populando array
    for(int i = 0;i<DIM;i++){
        vetor[i] = i*2+1;
    }
    do
    {
        printf("============Menu============\n");
        printf("1 - Busca Sequencial\n");
        printf("2 - Busca Binária\n");
        printf("3 - Busca em Árvore binária\n");
        printf("4 - Comparativo\n");
        printf("5 - Imprimir Vetor\n");
        printf("0 - Sair\n");
        printf("============================\n");
        scanf("%d", &menu);
        system("clear");
        switch (menu){
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &numBusca);
                inicio = clock();
                indice = buscaSeq(vetor, numBusca);
                fim = clock();
                printf("Indice: %d\n", indice);
                printf("Tempo de Execução: %lf\n", (double)(fim-inicio)/CLOCKS_PER_SEC);
                break;
            case 2:
                printf("Digite o valor: ");
                scanf("%d", &numBusca);
                inicio=clock();
                indice = buscaBin(vetor, 0, DIM-1, numBusca);
                fim = clock();
                printf("Indice: %d\n", indice);
                printf("Tempo de Execução: %lf\n", (double)(fim-inicio)/CLOCKS_PER_SEC);
                break;
            case 5:
                for(int i=0;i<DIM;i++){
                    printf("Vetor[%d]: %d\n", i, vetor[i]);
                }
                break;
        }
    } while (menu);
    

    return 0;
}

int buscaBin(int vetor[], int esquerda, int direita, int valor){
    if(direita>=esquerda){
        int i = esquerda+(direita-esquerda)/2;
        int atual = vetor[i];
        if(atual == valor){
            return i;
        }
        if(atual > valor){
            printf("%d - %d\n", esquerda, direita);
            return buscaBin(vetor, esquerda, i-1, valor);
        }
        printf("%d - %d\n", esquerda, direita);
        return buscaBin(vetor, i+1, direita, valor);
    }
    return -1;
}

int buscaSeq(int vetor[], int valor){
    for(int i=0;i<DIM;i++){
        if(valor==vetor[i]){
            return i;
        }else{
            return -1;
        }
    }
}
