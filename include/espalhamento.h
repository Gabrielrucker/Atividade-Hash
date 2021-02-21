//
// Created by danie on 01/09/2020.
//

#ifndef ESPALHAMENTO_ESPALHAMENTO_H
#define ESPALHAMENTO_ESPALHAMENTO_H

#include <stdbool.h>


typedef struct registro
{
  char nome[70];
  char autor[70];
  int ano;
} REGISTRO;

typedef enum
{
  LIVRE, OCUPADO, REMOVIDO
} EstadoDoSlot;

typedef struct hash
{
  REGISTRO *chaves;
  EstadoDoSlot *estados;
  unsigned long tamanho;
  unsigned long ocupados;
  unsigned short N;
} HASH;

bool criar_tabela_hash(HASH *tabela);
bool destruir_tabela_hash(HASH *tabela);
unsigned long inserir_na_tabela_hash(HASH *tabela, REGISTRO *registro);
bool apagar_da_tabela_hash(HASH *tabela, REGISTRO *registro);
bool busca_na_tabela_hash(HASH *tabela, REGISTRO *registro);

void ocupacao_da_tabela_hash(HASH *tabela);

unsigned long tamanho_da_tabela_hash(HASH *tabela);
unsigned long registros_na_tabela_hash(HASH *tabela);
double densidade_da_tabela_hash(HASH *tabela);
bool expandir_tabela_hash(HASH *tabela);
bool encolher_tabela_hash(HASH *tabela);
bool calcula_primo_proximo_2aN(unsigned short N, unsigned long *primo);

unsigned long calcular_valor_do_hash(char *chave, unsigned long M);

#endif //ESPALHAMENTO_ESPALHAMENTO_H