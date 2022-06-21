#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tipo base dos elementos da lista
typedef struct elementos {
  int valor;
} t_elemento;

// Estrutura da lista
typedef struct no {
  t_elemento dado; // elemento contendo os dados
  struct no * prox; // ponteiro para o proximo elemento
} t_no; // tipo da estrutura

typedef t_no * t_lista; // t_lista é igual a t_no *
t_lista L, M;


int main()
{
  L->dado.valor = 1;

  printf("L: %p\nM: %d\n", &L, M);
  return 0;
}
