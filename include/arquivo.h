#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include<stdio.h>
#include"espalhamento.h"

FILE *fp;

void carrega_do_arquivo(HASH** t, FILE*);

void insere_no_arquivo(HASH*, FILE*);

/* bool busca_no_arquivo(HASH*, FILE*, REGISTRO*); */

#endif