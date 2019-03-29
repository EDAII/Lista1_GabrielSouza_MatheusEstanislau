#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#define DIM 10

using namespace std;

int buscaBin(int vetor[], int esquerda, int direita, int valor);
//int buscaSeq(int vetor[], int valor);
void buscaSequencial(int vetor[], int valor);
void pause (float delay1);
void popularVetor(int vetor[]);
void imprimeVetor(int vetor[]);
int menuEntrada();
int menuPratica();
void apresentacao();
void mostra1();
void mostra2();
void mostra3();
void tempo();

int main()
{
    int numBusca,
        menuEn,
        menuPra,
        indice,
        vetor[DIM];
    clock_t inicio,
            fim;
    char a;
    string bee = "\U0001F41D";

    popularVetor(vetor);
    
    apresentacao();

    //WORKING
    do{
        menuEn = menuEntrada();
        switch (menuEn)
        {
            case 1:
                system("clear");
                printf("EM DESENVOLVIMENTO!!\n");
                printf("TUTORIAL\n");
                break;
            case 2:
                do
                {
                    menuPra = menuPratica();
                    switch (menuPra)
                    {
                        case 1:
                            system("clear");
                            printf("EM DESENVOLVIMENTO!!\n");
                            printf("Busca Sequencial\n");
                            break;
                        case 2:
                            system("clear");
                            printf("Busca Binaria\n");
                            break;
                        case 5:
                            imprimeVetor(vetor);
                            break;
                        case 0:
                            system("clear");
                            printf("Então falows\n");
                            setbuf(stdin, NULL);
                            break;
                
                        default:
                            system("clear");
                            printf("Uai, não entendi\n");
                            break;
                    }
                    
                } while (menuPra);
                break;
            case 0:
                printf("Tchau, Obrigado ");
                cout << bee << endl;
                break;     

            default:
                printf("Ai não né\n :(\n");
                break;
        }
    }while(menuEn);
    

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

// int buscaSeq(int vetor[], int valor){
//     for(int i=0;i<DIM;i++){
//         if(valor==vetor[i]){
//             return i;
//         }
//     }
// }

void buscaSequencial(int vetor[], int valor){
    for(int i=0;i<DIM;i++){
        if(vetor[i]==valor){
            printf("Indice: %d\n", i);
        }else{
            printf("Valor não encontrado\n");
        }
    }
}

void popularVetor(int vetor[]){
    for(int i = 0;i<DIM;i++){
        vetor[i] = i*2+1;
    }
}

void imprimeVetor(int vetor[]){
    for(int i=0;i<DIM;i++){
        printf("Vetor[%d]: %d\n", i, vetor[i]);
    }
}

int menuEntrada(){
    int opcao;

    printf("============Menu============\n");
    printf("1 - Tutorial\n");
    printf("2 - Prática\n");
    printf("0 - Sair\n");
    printf("============================\n");
    
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    return opcao;
}

int menuPratica(){
    int opcao;

    printf("============Menu============\n");
    printf("1 - Busca Sequencial\n");
    printf("2 - Busca Binária\n");
    printf("3 - Busca em Árvore binária\n");
    printf("4 - Comparativo\n");
    printf("5 - Imprimir Vetor\n");
    printf("0 - Sair\n");
    printf("============================\n");

    printf("Digite sua opção: ");
    scanf("%d", &opcao);
    system("clear");

    return opcao;
}

void pause (float delay1) {

   if (delay1<0.001) return; // pode ser ajustado e/ou evita-se valores negativos.

   float inst1=0, inst2=0;

   inst1 = (float)clock()/(float)CLOCKS_PER_SEC;

   while (inst2-inst1<delay1){
       inst2 = (float)clock()/(float)CLOCKS_PER_SEC;
   }

   return;

}

void tempo(){
    float inicio;
    inicio = clock();
    while((clock() - inicio) < 3000000){
        
    }
}

void apresentacao(){
    system("clear");
    printf("Bem vindo ao seu tutorial de Buscas!!!\n");
    pause(2.0);
    system("clear");
    printf("Aqui você irá aprender como funciona 3 métodos de busca:\n");
    pause(2.5);
    mostra1();
    mostra2();
    mostra3();
}

void mostra1(){
    system("clear");
    printf("**************************************************************************\n");
    printf("* [Busca Sequencial]\t\t\t\t\t\t\t *\n");
    printf("**************************************************************************\n");
    pause(1.0);
    system("clear");
}

void mostra2(){
    system("clear");
    printf("**************************************************************************\n");
    printf("* [Busca Sequencial]\t[Busca Binária]\t\t\t\t\t *\n");
    printf("**************************************************************************\n");
    pause(1.0);
}

void mostra3(){
    system("clear");
    printf("**************************************************************************\n");
    printf("* [Busca Sequencial]\t[Busca Binária]\t\t[Busca por Interpolacao] *\n");
    printf("**************************************************************************\n");
    pause(1.0);
    system("clear");
}
