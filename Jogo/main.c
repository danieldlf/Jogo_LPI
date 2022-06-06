#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <windows.h>
#include "jogar.h"

int i, j;


void exibirMenu(){
    printf("    PEGUE O PORCO!!\n");
    printf("\nMENU INICIAL DO JOGO");
    printf("\n1 - JOGAR");
    printf("\n2 - INSTRUCOES");
    printf("\n3 - SAIR");
    printf("\nEscolha uma opcao: ");
}

// execucao do jogo
int main()
{
    int opcao;
    while (true){
        opcao = 0;
        while(opcao != 1 && opcao != 2 && opcao != 3){
            system("cls");
            exibirMenu();
            scanf("%d", &opcao);
            }
        if(opcao == 1){
            system("cls");
            getchar(); // pause()
            jogar();
        }
        else if(opcao == 2){
            system("cls");
            printf("Instrucoes:");
            printf("Aperte Q para aumentar o angulo de lançamento.\n");
            printf("Aperte A para diminuir o angulo de lançamento.\n");
            printf("Aperte W para subir a posicao do canhao.\n");
            printf("Aperte S para descer a posicao do canhao.\n");
            printf("Aperte ESPACO para atirar\n");
            getch(); // pause()
        }
        else{
            printf("Bye bye!");
            exit(0);
        }
    }
}
