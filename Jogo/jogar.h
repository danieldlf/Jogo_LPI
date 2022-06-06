#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <windows.h>
#include "solve2.h"
#include "gotoxy.h"
#include "init.h"
#define LIMITE 120
#define LIMITEVERT 30
#define PONTOS_ACERTO 100
#define PONTOS_ERRO 5

int i, j;
char bloco = '-';

void jogar(){

    int dif = 0;
    while (dif != 1 && dif != 2 && dif != 3){
        system("cls");
        printf("Configuracoes do JOGO:");
        printf("- Dificuldade:\n 1 - Dificil\n 2 - Medio\n 3 - Facil");
        printf("\nQual a dificuldade desejada? ");
        scanf("%d", &dif);
        // try... except
        }


    getchar(); // ou pause()
    init(LIMITEVERT);
    gotoxy(0, LIMITEVERT);
    for(i=0; i<LIMITE; i++){
        printf("%c", bloco);
    }
    fflush(stdout);
    gotoxy (1, LIMITEVERT - 4);
    for(i=0; i<LIMITE; i++){
        printf("%c", bloco);
    }
    fflush(stdout);
    gotoxy ((LIMITE/2) - 5, 0);
    printf("Pontos:");
    fflush(stdout);
    gotoxy ((LIMITE/2) - 5, LIMITEVERT - 3);
    printf("Vidas:");
    fflush(stdout);
    getchar();

    struct traj {
        float A, B, C;
    };

    struct passaros {
        char img; // dps mudar pra tentar o desenho real
        int x, y;
        bool ativo; // = false
        struct traj traj1; // = {0, 0, 0}
    }pssr[2];

    struct porquinhos{
        char img; // ='@'
        int x, y;
        bool ativo; // = false
    }prqn[4];

    float pontuacaoJogador = 0.0;
    float coefAng = 0;
    float intervalo = 5;
    float posicaoCanhao = LIMITEVERT/2;
    int numeroVidasJogador = 0;
    /**/
    int size = (sizeof prqn / sizeof *prqn);
    int size2 = (sizeof pssr / sizeof *pssr);
    /**/

    if (dif == 1){
        numeroVidasJogador = 5;
    }else if(dif == 2){
        numeroVidasJogador = 8;
    }else if(dif == 3){
        numeroVidasJogador = 10;
    }

    gotoxy((int)(LIMITE/2 + 2), 0);
    printf("0");

    gotoxy (LIMITE/2 + 1, LIMITEVERT - 3);
    printf("%d", numeroVidasJogador);

    while(true){
        if(((rand()%15)%sizeof(prqn) == 0) && (intervalo < 0)){ // nao sei se strlen funciona aq
            intervalo = sizeof(prqn) + rand()%10; // strlen, msm coisa aq
            //int j = 0; ja declarei j
            for(i=0; i<4; i++){
                if(!prqn[i].ativo){
                    prqn[i].ativo = true;
                    prqn[i].img = '@';
                    prqn[i].x = 25 + rand()%70;
                    prqn[i].y = 5 + rand()%15;
                    break;
                }
            //j += 1
            }

        }
        //j=0
        for(i=0; i<4; i++){
            //apaga o porco
            gotoxy(prqn[i].x, prqn[i].y);
            printf("       "); //end = ''

            if(prqn[i].ativo){
                gotoxy(prqn[i].x, prqn[i].y);
                printf("%c", prqn[i].img);
            }else{
                for(i=0; i<30; i++){
                    printf(" ");
                }

            }
        }

        //apagar o canhao
        gotoxy(1, posicaoCanhao+1);
        printf("  ", fflush(stdout));
        gotoxy(2, posicaoCanhao+1);
        printf("  ", fflush(stdout));
        gotoxy(3, posicaoCanhao+1);
        printf("  ", fflush(stdout));
        gotoxy(4, posicaoCanhao+1);
        printf("  ", fflush(stdout));
        gotoxy(1, posicaoCanhao);
        printf("  ", fflush(stdout));
        gotoxy(2, posicaoCanhao);
        printf("  ", fflush(stdout));
        gotoxy(3, posicaoCanhao);
        printf("  ", fflush(stdout));
        gotoxy(4, posicaoCanhao);
        printf("  ", fflush(stdout));
        gotoxy(1, posicaoCanhao-1);
        printf("  ", fflush(stdout));
        gotoxy(2, posicaoCanhao-1);
        printf("  ", fflush(stdout));
        gotoxy(3, posicaoCanhao-1);
        printf("  ", fflush(stdout));
        gotoxy(4, posicaoCanhao-1);
        printf("  ", fflush(stdout));

        if(kbhit()){
            char c = getch(); // aqui ele usou hitKey

            // Atirar bala
            if(c == ' '){ // verificar se os ordinais pegam assim
                for(i=0; i<2; i++){
                    if(!pssr[i].ativo){
                        pssr[i].ativo = true;
                        pssr[i].img = '@';
                        pssr[i].x = 5;
                        pssr[i].y = posicaoCanhao;
                        pssr[i].traj1.C = pssr[i].y;
                        pssr[i].traj1.A = 0.005;
                        pssr[i].traj1.B = -coefAng;
                        break;
                    }
                }
            }
            else if((c == 'q') || (c == 'Q')){
                coefAng = (float)(coefAng+(0.02));
                gotoxy(10, LIMITEVERT - 3);
                printf("                        ");
                gotoxy(10, LIMITEVERT - 3);
                printf("Angulo = %.2f", coefAng);
                fflush(stdout);
                if(coefAng>(1.2)){
                    coefAng = 0;
                    gotoxy(10, LIMITEVERT - 3);
                    printf("                        ");
                    gotoxy(10, LIMITEVERT - 3);
                    printf("Angulo = %.2f", coefAng);
                    fflush(stdout);
                }
            }
            else if((c == 'a') || (c == 'A')){
                coefAng = (float)(coefAng-(0.02));
                gotoxy(10, LIMITEVERT - 3);
                printf("                        ");
                gotoxy(10, LIMITEVERT - 3);
                printf("Angulo = %.2f", coefAng);
                fflush(stdout);
                if(coefAng <= -(0.72)){
                    coefAng = 0;
                    gotoxy(10, LIMITEVERT - 3);
                    printf("                        ");
                    gotoxy(10, LIMITEVERT - 3);
                    printf("Angulo = %.2f", coefAng);
                    fflush(stdout);
                }
            }
            else if((c == 'w') || (c == 'W')){
                posicaoCanhao -= 1;
                if(posicaoCanhao <= 2){
                    posicaoCanhao = LIMITEVERT/2;
                }
            }
            else if((c == 's') || (c == 'S')){
                posicaoCanhao += 1;
                if(posicaoCanhao >= 24){
                    posicaoCanhao = LIMITEVERT/2;
                }
            }
        }
        for(i=0; i<2; i++){
            gotoxy(pssr[i].x, pssr[i].y);
            printf("    "); // apagar o passaro
            if(pssr[i].ativo){

                pssr[i].x += 2;
                pssr[i].y = (float)(solve2(pssr[i].traj1.A, pssr[i].traj1.B, pssr[i].traj1.C, pssr[i].x));

                if(pssr[i].x >= LIMITE || pssr[i].y >= 24 || pssr[i].y <= 2){
                    pssr[i].ativo = false;
                    numeroVidasJogador -= 1;
                    gotoxy(LIMITE/2 + 1, LIMITEVERT - 3);
                    printf("%d", numeroVidasJogador);
                }
                else{
                    gotoxy(pssr[i].x, pssr[i].y);
                    printf("%c", pssr[i].img);
                }
            }
            else{
                for(i=0; i<30; i++){
                    printf("  ");
                }
            }
        }
        if(coefAng == 0){
            gotoxy(1, posicaoCanhao+1);
            printf("%c", bloco); // mudar esse negocio
            fflush(stdout);
            gotoxy(2, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(3, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(4, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(1, posicaoCanhao);
            printf("-");
            fflush(stdout);
            gotoxy(2, posicaoCanhao);
            printf("-");
            fflush(stdout);
            gotoxy(3, posicaoCanhao);
            printf("-");
            fflush(stdout);
            gotoxy(1, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(2, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(3, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(4, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
        }
        else if(coefAng > 0 && coefAng < (0.2)){
            gotoxy(1, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(2, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(3, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(4, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(1, posicaoCanhao);
            printf("-");
            fflush(stdout);
            gotoxy(2, posicaoCanhao);
            printf("'");
            fflush(stdout);
            gotoxy(3, posicaoCanhao);
            printf("-");
            fflush(stdout);
            gotoxy(1, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(2, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(3, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(4, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
        }
        else if(coefAng >= (0.2) && coefAng <= (0.4)){
            gotoxy(1, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(2, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(3, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(4, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(1, posicaoCanhao);
            printf("-");
            fflush(stdout);
            gotoxy(2, posicaoCanhao);
            printf("-");
            fflush(stdout);
            gotoxy(3, posicaoCanhao);
            printf("'");
            fflush(stdout);
            gotoxy(1, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(2, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(3, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(4, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
        }
        else if(coefAng > (0.4) && coefAng <= (0.6)){
            gotoxy(1, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(2, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(3, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(4, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(1, posicaoCanhao);
            printf("-");
            fflush(stdout);
            gotoxy(2, posicaoCanhao);
            printf("'");
            fflush(stdout);
            gotoxy(3, posicaoCanhao);
            printf("'");
            fflush(stdout);
            gotoxy(1, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(2, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(3, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(4, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
        }
        else if(coefAng > (0.6)){
            gotoxy(1, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(2, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(3, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(4, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(1, posicaoCanhao);
            printf("-");
            fflush(stdout);
            gotoxy(2, posicaoCanhao);
            printf("-");
            fflush(stdout);
            gotoxy(3, posicaoCanhao);
            printf("/");
            fflush(stdout);
            gotoxy(1, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(2, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(3, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(4, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
        }
        else if(coefAng < 0 && coefAng >= -(0.2)){
            gotoxy(1, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(2, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(3, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(4, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(1, posicaoCanhao);
            printf("-");
            fflush(stdout);
            gotoxy(2, posicaoCanhao);
            printf("\ ");
            fflush(stdout);
            gotoxy(3, posicaoCanhao);
            printf("-");
            fflush(stdout);
            gotoxy(1, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(2, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(3, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(4, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
        }
        else if(coefAng < -(0.2) && coefAng >= -(0.4)){
            gotoxy(1, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(2, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(3, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(4, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(1, posicaoCanhao);
            printf("-");
            fflush(stdout);
            gotoxy(2, posicaoCanhao);
            printf("-");
            fflush(stdout);
            gotoxy(3, posicaoCanhao);
            printf("\ ");
            fflush(stdout);
            gotoxy(1, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(2, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(3, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(4, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
        }
        else if(coefAng < -(0.4) && coefAng >= -(0.6)){
            gotoxy(1, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(2, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(3, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(4, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(1, posicaoCanhao);
            printf("-");
            fflush(stdout);
            gotoxy(2, posicaoCanhao);
            printf("\ ");
            fflush(stdout);
            gotoxy(3, posicaoCanhao);
            printf("\ ");
            fflush(stdout);
            gotoxy(1, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(2, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(3, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(4, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
        }
        else if(coefAng < -(0.6)){
            gotoxy(1, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(2, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(3, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(4, posicaoCanhao+1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(1, posicaoCanhao);
            printf("\ ");
            fflush(stdout);
            gotoxy(2, posicaoCanhao);
            printf("\ ");
            fflush(stdout);
            gotoxy(3, posicaoCanhao);
            printf("\ ");
            fflush(stdout);
            gotoxy(1, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(2, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(3, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
            gotoxy(4, posicaoCanhao-1);
            printf("%c", bloco);
            fflush(stdout);
        }
        bool acertou = 0; // false
        for(i=0; i<4; i++){
            for(j=0; j<2; j++){
                if(pssr[j].ativo && prqn[i].ativo && (pssr[j].x == prqn[i].x || pssr[j].x + 1 == prqn[i].x || pssr[j].x == prqn[i].x + 1 || pssr[j].x + 3 == prqn[i].x || pssr[j].x == prqn[i].x + 3 || pssr[j].x + 2 == prqn[i].x || pssr[j].x == prqn[i].x + 2) && (pssr[j].y == prqn[i].y)){
                    acertou = true;
                    pssr[j].ativo = false;
                    prqn[i].ativo = false;
                    break;
                }
            }
        }
        if(acertou){
            pontuacaoJogador += PONTOS_ACERTO;
            gotoxy(LIMITE/2 + 2, 0);
            printf("%.2f", pontuacaoJogador);
        }
        // fim de jogo
        if(pontuacaoJogador >= 1000){
            gotoxy(35, LIMITEVERT/2);
            printf("YOU WIN!");
            break;
        }
        // game over
        if(numeroVidasJogador == 0){
            gotoxy(35, LIMITEVERT/2);
            printf("GAME OVER!");
            break;
        }
        sleep(0.9);
        intervalo -= 1;
    }
    getchar(); // pause()
}
