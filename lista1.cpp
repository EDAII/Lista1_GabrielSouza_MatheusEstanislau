#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#define DIM 50

using namespace std;

int buscaBin(int vetor[], int esquerda, int direita, int valor);
//int buscaSeq(int vetor[], int valor);
void buscaSequencial(int vetor[], int valor);
void pause (float delay1);
void popularVetor(int vetor[]);
void imprimeVetor(int vetor[]);
int menuEntrada();
int menuPratica();
int menuTutorial();
void apresentacao();
void tutorialBuscaSequencial();
void tutorialBuscaBinaria();
void tutorialBuscaPorInterpolacao();
void mostra1();
void mostra2();
void mostra3();

int main()
{
    int numBusca,
        menuEn,
        menuPra,
        menuTuto,
        indice,
        vetor[DIM];
    clock_t inicio,
            fim;
    char a;
    string bee = "\U0001F41D";

    popularVetor(vetor);
    
    apresentacao();

    //WORKING
    //Menu Superior
    do{
        menuEn = menuEntrada();
        switch (menuEn)
        {
            case 1:
            //Menu Tutorial
                do
                {
                    menuTuto = menuTutorial();
                    switch (menuTuto)
                    {
                        case 1:
                            system("clear");
                            tutorialBuscaSequencial();
                            break;
                        case 2:
                            system("clear");
                            tutorialBuscaBinaria();
                            break;
                        case 3:
                            system("clear");
                            tutorialBuscaPorInterpolacao();
                            break;
                        case 0:
                            system("clear");
                            printf("Então Flws\n");
                    
                        default:
                            system("clear");
                            printf("Uai, não entendi\n");
                            break;
                    }
                } while (menuTuto);
                
                system("clear");
                break;
            //Menu Prática
            case 2:
                do
                {
                    menuPra = menuPratica();
                    switch (menuPra)
                    {
                        case 1://Sequencial
                            system("clear");
                            printf("EM DESENVOLVIMENTO!!\n");
                            printf("Busca Sequencial\n");
                            break;
                        case 2://Binario
                            system("clear");
                            imprimeVetor(vetor);
                            printf("Digite o valor a ser pesquisado: ");
                            scanf("%d", &numBusca);
                            indice = buscaBin(vetor, 0, DIM-1, numBusca);
                            printf("Indice: %d\n", indice);
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
            return i+1;
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

void tutorialBuscaSequencial(){
    system("clear");
    printf("Busca sequencial, como o proprio nome diz eh uma busca feita em sequencia,\n");
    printf("registro a registro. O que em um DataSet grande, chega a ser inviável sua utilizacao\n");      
    printf("\nVamos a um exemplo?!\n");
    pause(9.0);
    system("clear");

    printf("Imagine um vetor de 10 elementos: Vetor{1,2,3,4,5,6,7,8,9,10}\n");
    printf("Agora imagine que você queira saber qual a posição que se encontra o valor 9\n.");        
    printf("O algorismo irá percorrer todo o vetor para retorna o valor.\nAcompanhe o exemplo:\n");       
    pause(11.0);
    system("clear");

    printf("{x, , , , , , , , , }\n");
    pause(1);
    system("clear");
    printf("{ ,x, , , , , , , , }\n");
    pause(1);
    system("clear");
    printf("{ , ,x, , , , , , , }\n");
    pause(1);
    system("clear");
    printf("{ , , ,x, , , , , , }\n");
    pause(1);
    system("clear");
    printf("{ , , , ,x, , , , , }\n");
    pause(1);
    system("clear");
    printf("{ , , , , ,x, , , , }\n");
    pause(1);
    system("clear");
    printf("{ , , , , , ,x, , , }\n");
    pause(1);
    system("clear");
    printf("{ , , , , , , ,x, , }\n");
    pause(1);
    system("clear");
    printf("{ , , , , , , , ,9, }\n");
    pause(1);
    system("clear");
    printf("{ , , , , , , , , ,x}\n");
    pause(1);
}

void tutorialBuscaBinaria(){
    system("clear");
    printf("Vimos que a busca sequencial pode ser demasiadamente demorada, entao\n");
    printf("surge a busca binaria. Ela consiste em fazer divisoes (por 2) sucessivas\n");
    printf("ate encontrar o valor. Para cada iteracao o vetor e reduzido pela metade\n");
    printf("o que reduz drasticamente o tempo de execucao, porem o vetor precisa estar ordenado!\n\n");

    printf("Vamos achar o 9 de novo!\n");
    pause(20);

    system("clear");
    printf("{1,2,3,4,5,6,7,8,9,10}\n");
    pause(1);
    //system("clear");
    printf("          {6,7,8,9,10}\n");
    pause(1);
    //system("clear");
    printf("              {8,9,10}\n");
    pause(1);
    //system("clear");
    printf("                {9}\n");
    pause(1);


}
void tutorialBuscaPorInterpolacao(){
    system("clear");
    printf("A Pesquisa por interpolação é uma variante mais otimizada da busca binária\n");
    printf("Para melhor utilização, dados ordenados e uniformes são essenciais\n");
    printf("Se encontrar o item pesquisado ele retorna o índice\n");
    printf("Caso contrário ele divide o vetor em duas partes pelo seguinte método:\n");
    printf("meio = inferior + ((superior - inferior)/(A[superior] - A[inferior])) * (x - A[inferior)\n");
    printf("onde: A = lista ou vetor\n");
    printf("      inferior = indice mais baixo da lista/vetor\n");
    printf("      superior = indice mais alto da lista/vetor\n");
    printf("      A[n] = valor armazenado no índice 'n' da lista \n");
    printf("      x = valor procurado\n");
    printf("Exemplo: Em um vetor y = (1,2,3,4,5,6,7,8,9,10)iremos buscar a posição que o elemento 2 ocupa\n");
    pause(20);
    printf("temos que inferior = 0, superior = 9, A[inferior] = 1, A[superior] = 10 e x = 2\n");
     pause(1);
    printf("na equação : meio = 0 + ((9-0)/(10 - 1)) * (2 - 1)\n");
     pause(1);
    printf("             meio = (9/9) * (1)\n");
     pause(1);
    printf("             meio = 1\n");
     pause(1);
}


void popularVetor(int vetor[]){
    for(int i = 0;i<DIM;i++){
        vetor[i] = i*2+1;
    }
}

void imprimeVetor(int vetor[]){
    printf("[");
    for(int i=0;i<DIM;i++){
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

int menuTutorial(){
    int opcao;

    printf("==========Tutorial==========\n");
    printf("1 - Busca Sequencial\n");
    printf("2 - Busca Binaria\n");
    printf("3 - Busca por Interpolação\n");
    printf("0 - Sair\n");
    printf("============================\n");
    
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    return opcao;
}

int menuEntrada(){
    int opcao;

    printf("==========Pratica===========\n");
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
