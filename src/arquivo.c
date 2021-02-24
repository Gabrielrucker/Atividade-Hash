

#include "../include/espalhamento.h"
#include "../include/arquivo.h"

#include <string.h>
#include <stdlib.h>

void carrega_do_arquivo(HASH** t, FILE* fp) {

    if(fp = fopen("dados.bin", "rb"))
    {
        fseek(fp, 0, SEEK_END);
        if(ftell(fp) == 0)
        {
            printf("Arquivo sem dados!\n");
            exit(0);
        }
        else
        {
            fseek(fp, -sizeof(unsigned long), SEEK_END);
            fread(&(*t)->tamanho, sizeof(unsigned long), 1, fp);
            //printf("Tamanho: %lu\n", (*t)->tamanho);
            (*t)->chaves = (REGISTRO *) malloc(sizeof(REGISTRO) * (*t)->tamanho);
            (*t)->estados = (EstadoDoSlot *) malloc(sizeof(EstadoDoSlot) * (*t)->tamanho);
            for(int j=0; j<(*t)->tamanho; j++)
            {
                (*t)->estados[j] = LIVRE;
            }
            for(int i=0; i<(*t)->tamanho; i++)
            {
                fseek(fp, i * sizeof(REGISTRO), SEEK_SET);
                fread(&(*t)->estados[i], sizeof(EstadoDoSlot), 1, fp);
                fread(&(*t)->chaves[i], sizeof(REGISTRO), 1, fp);
                /*DEBUG
                printf("\nNome: %s", (*t)->chaves[i].nome);
                printf("    Autor: %s", (*t)->chaves[i].autor);
                printf("        Ano: %d", (*t)->chaves[i].ano);
                printf("Estado: %u", (*t)->estados[i]);
                if((*t)->estados[i] == (int) LIVRE)
                {
                    printf("    LIVRE\n");
                    (*t)->estados[i] == LIVRE;
                }
                else if((*t)->estados[i] == (int) OCUPADO)
                {
                    printf("    OCUPADO\n");
                    (*t)->estados[i] == OCUPADO;
                }
                else if((*t)->estados[i] == REMOVIDO)
                {
                    printf("    REMOVIDO\n");
                    (*t)->estados[i] = REMOVIDO;
                }*/
            }
            fseek(fp, -18, SEEK_END);
            fread(&(*t)->ocupados, sizeof(unsigned long), 1, fp);
            //printf("Ocupados: %lu\n", (*t)->ocupados);
            fread(&(*t)->N, sizeof(unsigned long), 1, fp);
            //printf("N: %u\n", (*t)->N);
        }
        fclose(fp);
    }
    else
    {
        printf("Arquivo inexistente!\n Criando...\n");
        fp = fopen("dados.bin", "w");
        fclose(fp);
    }                  
}


void insere_no_arquivo(HASH* t, FILE* fp) {

    fp = fopen("dados.bin", "wb"); //abre para escrita
    for(int i=0; i<t->tamanho; i++) 
    {
        fseek(fp, (i * sizeof(REGISTRO)), SEEK_SET); // começa a partir do início
        fwrite(&t->estados[i], sizeof(int), 1, fp); // escreve o estado do slot 
        fwrite(&t->chaves[i], sizeof(REGISTRO), 1, fp); // escreve os registros no arquivo

     /* DEBUG
     
         if(t->estados[i] == LIVRE)
        {
            printf("LIVRE\n");
        }
        else if (t->estados[i] == OCUPADO)
        {
            printf("OCUPADO\n");
        }
        else if(t->estados[i] == REMOVIDO)
        {
            printf("REMOVIDO\n");
        } 
        
        */
    }
    fseek(fp, -2*sizeof(unsigned long) + sizeof(unsigned short), SEEK_END);
    // escreve os dados da tabela hash no arquivo
    fwrite(&t->ocupados, sizeof(unsigned long), 1, fp);
    fwrite(&t->N, sizeof(unsigned short), 1, fp);
    fwrite(&t->tamanho, sizeof(unsigned long), 1, fp);
    fclose(fp);
}

