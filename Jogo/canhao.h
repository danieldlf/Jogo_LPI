#include <stdio.h>
#include <stdlib.h>
#include "gotoxy.h"

void canhao (char a, char b, char c)
    gotoxy(1, posicaoCanhao+1);
    printf("%c", bloco); // mudar esse negocio
    //fflush(stdout);
    gotoxy(2, posicaoCanhao+1);
    printf("%c", bloco);
    //fflush(stdout);
    gotoxy(3, posicaoCanhao+1);
    printf("%c", bloco);
    //fflush(stdout);
    gotoxy(4, posicaoCanhao+1);
    printf("%c", bloco);
    //fflush(stdout);
    gotoxy(1, posicaoCanhao);
    printf("%c", a);
    //fflush(stdout);
    gotoxy(2, posicaoCanhao);
    printf("%c", b);
    //fflush(stdout);
    gotoxy(3, posicaoCanhao);
    printf("%c", c);
    //fflush(stdout);
    gotoxy(1, posicaoCanhao-1);
    printf("%c", bloco);
    //fflush(stdout);
    gotoxy(2, posicaoCanhao-1);
    printf("%c", bloco);
    //fflush(stdout);
    gotoxy(3, posicaoCanhao-1);
    printf("%c", bloco);
    //fflush(stdout);
    gotoxy(4, posicaoCanhao-1);
    printf("%c", bloco);
    //fflush(stdout);
