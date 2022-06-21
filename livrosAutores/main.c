#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
  int mes;
  int ano;
}TP_DATA;

typedef struct livro
{
  char nome[30];
  char autor[50];
  TP_DATA data_pub;
}TP_LIVRO;

/* PASSANDO PARAMETRO POR PONTEIRO */
void mostra(TP_LIVRO *livro)
{
  printf("Livro em mostra(): %s\n Autor: %s\n Ano: %d\n", livro->nome, livro->autor, livro->data_pub.ano);
  livro->data_pub.ano = 2015;
}

int main()
{
  TP_LIVRO l1 = {"Primo Basilio", "Eca de Queiroz"};
  l1.data_pub.ano = 2015;
  mostra(&l1);
  
  printf("Livro depois de mostra(): %s\n Autor: %s\n Ano: %d\n", l1.nome, l1.autor, l1.data_pub.ano);
  return 0;
}
