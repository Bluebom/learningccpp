#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa{
  char nome[20]; 
  int idade;
  char profissao[20];
} Pessoa;

int main()
{
  Pessoa pessoa1;

  pessoa1.idade = 22;
  strcpy(pessoa1.nome, "Franklin");
  strcpy(pessoa1.profissao, "programador");
  
  printf("Nome: %s\nIdade: %d\nProfissão: %s\n", pessoa1.nome, pessoa1.idade, pessoa1.profissao);
  return 0;
}
