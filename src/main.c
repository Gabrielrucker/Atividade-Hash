#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/espalhamento.h"
#include "../include/arquivo.h"

int menu()
{
  int op;
  printf("\n================================\n");
  printf("1- Carregar arquivo\n");
  printf("2- Criar tabela hash\n");
  printf("3- Inserir na tabela hash\n");
  printf("4- Buscar na tabela hash\n");
  printf("5- Remover da tabela hash\n");
  printf("6- Mostrar ocupação\n");
  printf("7- Excluir tabela hash\n");
  printf("8- Salvar e Sair");
  printf("\n================================\n");

  printf("\n\nDigite uma opcao: ");
  scanf("%d",&op);
  return op;
}

int main()
{
  unsigned long h;
  HASH* tabela;
  REGISTRO p, q;
  FILE* fp;
  int op;

  op = menu();

  while(op >= 1 && op <= 8)
  {
      switch(op)
      {
        case 1 : 
        carrega_do_arquivo(&tabela, fp);
        if(tabela == NULL)
        {
          return 0;
        }
        printf("\nTabela carregada com sucesso!\n");
        break;
    
        case 2 :
        if (!criar_tabela_hash(tabela))
        {
          printf("Erro na criacao da tabela\n");
          exit(1);
        }
        else
        {
          printf("\nTabela criada com sucesso!\n");
        }
        break;

        case 3 :
        getchar();
        printf("Digite o nome do artigo: ");
        fgets(p.nome, sizeof(p.nome), stdin);
        printf("Digite o autor: ");
        fgets(p.autor, sizeof(p.autor), stdin);
        printf("Digite o ano de publicacao: ");
        scanf("%d",& p.ano);

        if (!inserir_na_tabela_hash(tabela, &p))
        {
          printf("Falha na insercao\n");
          exit(1);
        }
        else
        {
          printf("Inserido\n");
        }
        break;

        case 4 :
        getchar();
        printf("Digite o nome do artigo a ser buscado: ");
        fgets(q.nome, sizeof(q.nome), stdin);
        if (!busca_na_tabela_hash(tabela, &q))
        {
          printf("Erro na recuperacao\n");
        }
        else
        {
          printf("O(A) Autor(a) de %s eh %s\n", q.nome, q.autor);
        }
        break;

        case 5 :
        getchar();
        printf("Digite o nome do artigo a ser removido: ");
        fgets(q.nome, sizeof(q.nome), stdin);
        if (apagar_da_tabela_hash(tabela, &q))
        {
          printf("%s removido\n", q.nome);
        }
        else
        {
          printf("%s nao existe na tabela\n", q.nome);
        }
        break;

        case 6:
        ocupacao_da_tabela_hash(tabela);
        break;

        case 7:
        if (destruir_tabela_hash(tabela))
        {
          printf("Tabela destruida\n");
        }
        else
        {
          printf("Problema para destruir a tabela\n");
        }
        break;

        case 8:
        printf("\nSalvando e Saindo...\n");
        insere_no_arquivo(tabela, fp);
        exit(0);
        break;

        default:
        printf("Selecione uma opcao valida!");
      }
      op = menu();
    }
  return 0;
}
