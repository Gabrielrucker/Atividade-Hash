#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/espalhamento.h"
#include "../include/arquivo.h"

int main()
{
  unsigned long h;
  HASH tabela;
  REGISTRO p, q;
  FILE* fp;

  if (!criar_tabela_hash(&tabela))
  {
    printf("Erro na criacao da tabela\n");
    exit(1);
  }

  ocupacao_da_tabela_hash(&tabela);

  // Inserir primeira chave
  strcpy(p.nome, "Fundamentos da Programacao de Computadores");
  strcpy(p.autor, "Ana Fernanda Gomes Ascencio, Edilene Aparecida Veneruchi de Campos");
  p.ano = 2012;

  h = inserir_na_tabela_hash(&tabela, &p);

  if (h == -1)
  {
    printf("Falha na insercao\n");
    exit(1);
  }
  else
  {
    insere_no_arquivo(fp, &p, h);
    printf("Inserido\n");
  }

  // Inserir segunda chave
  strcpy(p.nome, "Engenharia de Software");
  strcpy(p.autor, "Ian Sommerville");
  p.ano = 2011;

  h = inserir_na_tabela_hash(&tabela, &p);

  if (h == -1)
  {
    printf("Falha na insercao\n");
    exit(1);
  }
  else
  {
    insere_no_arquivo(fp,&p,h);
    printf("Inserido\n");
  }
 

  // Inserir primeira chave
  strcpy(p.nome, "Java: Como Programar");
  strcpy(p.autor, "Paul Deitel e Harvey Deitel");
  p.ano =  2010;

  h = inserir_na_tabela_hash(&tabela, &p);

  if (h == -1)
  {
    printf("Falha na insercao\n");
    exit(1);
  }
  else
  {
    insere_no_arquivo(fp,&p,h);
    printf("Inserido\n");
  }

  h = inserir_na_tabela_hash(&tabela, &p);

  // Inserir chave duplicada para produzir colisao
  if (h == -1)
  {
    printf("Falha na insercao\n");
    exit(1);
  }
  else
  {
    insere_no_arquivo(fp,&p,h);
    printf("Inserido\n");
  }

  ocupacao_da_tabela_hash(&tabela);


  // ***

  // Recuperando uma chave que existe
  strcpy(q.nome, "Fundamentos da Programacao de Computadores");
  if (!busca_na_tabela_hash(&tabela, &q))
  {
    printf("Erro na recuperacao\n");
  }
  else
  {
    printf("O(A) autor(a) de %s eh %s\n", q.nome, q.autor);
  }

  // Recuperando uma chave que existe
  strcpy(q.nome, "Engenharia de Software");
  if (!busca_na_tabela_hash(&tabela, &q))
  {
    printf("Erro na recuperacao\n");
  }
  else
  {
    printf("O(A) autor(a) de %s eh %s\n", q.nome, q.autor);
  }

  // Recuperando uma chave que nao existe
  strcpy(q.nome, "Graphs: An Introductory Approach");
  if (!busca_na_tabela_hash(&tabela, &q))
  {
    printf("Erro na recuperacao\n");
  }
  else
  {
    printf("O(A) autor(a) de %s eh %s\n", q.nome, q.autor);
  }

  // ***

  // Removendo uma chave que existe
  strcpy(q.nome, "Java: Como Programar");
  if (apagar_da_tabela_hash(&tabela, &q))
  {
    printf("%s removido\n", q.nome);
  }
  else
  {
    printf("%s nao existe na tabela\n", q.nome);
  }

// Removendo uma chave que existe
  strcpy(q.nome, "Engenharia de Software");
  if (apagar_da_tabela_hash(&tabela, &q))
  {
    printf("%s removido\n", q.nome);
  }
  else
  {
    printf("%s nao existe na tabela\n", q.nome);
  }

  // ***

  // Recuperando uma chave que existe
  strcpy(q.nome, "Fundamentos da Programacao de Computadores");
  if (!busca_na_tabela_hash(&tabela, &q))
  {
    printf("Erro na recuperacao\n");
  }
  else
  {
    printf("O(A) autor(a) de %s eh %s\n", q.nome, q.autor);
  }

  // Removendo uma chave que nao existe
  strcpy(q.nome, "Estrutura de Dados e Algoritmos em C++");
  if (apagar_da_tabela_hash(&tabela, &q))
  {
    printf("%s removido\n", q.nome);
  }
  else
  {
    printf("%s nao existe na tabela\n", q.nome);
  }

  // mostrando a tabela
  ocupacao_da_tabela_hash(&tabela);

  // Ampliando
  printf("Expandindo a tabela...\n");
  expandir_tabela_hash(&tabela);

  // mostrando a tabela
  ocupacao_da_tabela_hash(&tabela);

  if (destruir_tabela_hash(&tabela))
  {
    printf("Tabela destruida\n");
  }
  else
  {
    printf("Problema para destruir a tabela\n");
  }

  return 0;
}
