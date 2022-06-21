#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista.h"


int display()
{
  int opcao;
  printf("1 - Inserir no início\n2 - Imprimir\n3 - Inserir no fim\n4 - remover 1 item da lista\n5 - Sair\n ");
  scanf("%d", &opcao);
  return opcao;
}

int main()
{
  int opcao = -2, valor;

  Lista lista;
  lista.inicio = NULL;
  lista.tam = 0;

  do{
    opcao = display();
    switch(opcao)
    {
      case 1:
        printf("Digite um valor a ser inserido: ");
        scanf("%d", &valor);
        inserirInicio(&lista, valor);
        break;
      case 2: 
        imprimir(&lista);
        break;
      case 3:
        printf("Digite um valor a ser inserido: ");
        scanf("%d", &valor);
        inserir(&lista, valor);
        break;
      case 4:
        printf("Digite o valor a ser removido: ");
        scanf("%d", &valor);
        remover(&lista, valor);
        break;
      case 5:
        printf("Finalizando...\n");
        break;
      default:
        printf("Opção inválida\n");
    }
  }while(opcao != 5);

  return 0;
}
