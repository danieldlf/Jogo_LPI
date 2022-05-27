#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>

int const LIMITE = 120
int const LIMITE_VERT = 30

int const PONTOS_ACERTO = 100
int const PONTOS_ERRO = 5

int i, j;

int init(int lines){
    clrscr();
    for(i=0; i<lines; i++){
        print('\n');
    }
}

void jogar(){

    int dif = 0;
    while (dif != 1 && dif != 2 && dif != 3){
        clrscr();
        printf("Configuracoes do JOGO:");
        printf("- Dificuldade:\n 1 - Dificil\n 2 - Medio\n 3 - Facil");
        printf("Qual a dificuldade desejada? ");
        scanf("%d", &dif);
        if(int isdigit(dif) = 0){
            dif = 0;
        }
    }

    getchar(); // ou pause()
    init(LIMITE_VERT);
    goto(0, LIMITE_VERT);
    printf("▬" * LIMITE, fflush(stdin));// mudar
    goto (1, LIMITE_VERT - 4);
    printf("▬" * LIMITE, fflush(stdin)); //mudar
    goto ((LIMITE/2) - 5, 0);
    printf("Pontos:", fflush(stdin));
    goto ((LIMITE/2) - 5, LIMITE_VERT - 3);
    printf("Vidas:", fflush(stdin));
    getchar()

    struct traj {
        float A, B, C;
    }traj1;

    struct passaros {
        char img; // dps mudar pra tentar o desenho real
        int x, y;
        bool ativo = false;
        traj1 = {0, 0, 0};
    }pssr[2];

    struct porquinhos{
        char img;
        int x, y;
        bool ativo = false;
    }prqn[4];

    unsigned float pontuacaoJogador = 0.0;
    float coefAng = 0;
    int intervalo = 5;
    float posicaoCanhao = LIMITE_VERT/2
    unsigned int numeroVidasJogador = 0;

    if (dif == 1){
        numeroVidasJogador = 5;
    }else if(dif == 2){
        numeroVidasJogador = 8;
    }else if(dif == 3){
        numeroVidasJogador = 10;
    }

    goto(LIMITE/2 + 2, 0);
    printf("0");

    goto (LIMITE/2 + 1, LIMITE_VERT - 3);
    printf("%d", numeroVidasJogador);

    while(true){
        if((rand()%15)%strlen(prqn) == 0 && intervalo < 0){ // nao sei se strlen funciona aq
            intervalo = strlen(prqn) + rand()%10; // strlen, msm coisa aq
            //int j = 0; ja declarei j
            for(i=0; i<4; i++){
                if(!prqn[i].ativo){
                    prqn[i].ativo = true;
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
            goto(prqn[i].x, prqn[i].y);
            printf("       "); //end = ''

            if(prqn[i].ativo){
                goto(prqn[i].x, prqn[i].y);
                printf("%c", prqn[i].img);
            }else{
                for(i=0; i<30; i++){
                    printf(" ");
                }

            }
        }

        //apagar o canhao

    }
}
