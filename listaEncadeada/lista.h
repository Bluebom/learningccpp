#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#endif

typedef struct No
{
  int valor;
  struct No *prox;
}No;

typedef struct Lista
{
  No *inicio;
  int tam;
}Lista;

void inserirInicio(Lista *lista, int valor)
{
  No *novo = (No*)malloc(sizeof(No));
  novo->valor = valor; // (*novo).valor = valor
  novo->prox = lista->inicio;
  lista->inicio = novo;
  lista->tam++;
}

void inserir(Lista *lista, int valor)
{
  No *novo = (No*)malloc(sizeof(No));
  novo->valor = valor;
  novo->prox = NULL;
  if(lista->inicio == NULL)
  {
    lista->inicio = novo;
  }else
  {
    No *no = lista->inicio;
    while(no->prox != NULL)
    {
      no = no->prox;
    }
    no->prox = novo;
  }
  lista->tam++;
}

void remover(Lista *lista, int valor)
{
 if(lista->inicio == NULL)
  {
    free(lista);
  }else{
    No *no = lista->inicio;
    while(no->prox != NULL && no->valor != valor && no->prox->valor != valor)
    {
      no = no->prox;
    }
    if(no->prox != NULL && no->valor != valor){
      No *aux = no->prox->prox;
      free(no->prox);
      no->prox = aux;
    }else {
      No *aux = no->prox;
      free(no);
      lista->inicio = aux;
    } 
    lista->tam--;
  }
}

void imprimir(Lista *lista)
{
  No *inicio = lista->inicio;
  while(inicio != NULL)
  {
    printf("%d->", inicio->valor);
    inicio = inicio->prox;
  }
  printf("\n\n");
}
