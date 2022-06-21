#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno
{
  char nome[20];
  int rgm;
} aluno_arv;

typedef struct No
{
  struct Aluno aluno;
  struct No *direita, *esquerda;
} no_arv;

/*no_arv* inserir(no_arv *raiz, aluno_arv aluno)
{
  if(raiz == NULL)
  {
    no_arv *aux = (no_arv*)malloc(sizeof(no_arv));
    aux->aluno = aluno;
    aux->esquerda = NULL;
    aux->direita = NULL;
    return aux;
  }else
  {
    if(aluno.rgm < raiz->aluno.rgm)
    {
      raiz->esquerda = inserir(raiz->esquerda, aluno);
    }else
    {
      raiz->direita = inserir(raiz->direita, aluno);
    }
    return raiz;
  }
}*/

/*void inserir(no_arv **raiz, aluno_arv aluno)
{
   *raiz == raiz (do main()) 
  if(*raiz == NULL)
  {
    *raiz = malloc(sizeof(no_arv));
    (*raiz)->aluno = aluno;
    (*raiz)->esquerda = NULL;
    (*raiz)->direita = NULL;
  }else
  {
    if(aluno.rgm < (*raiz)->aluno.rgm)
    {
      inserir( &((*raiz)->esquerda), aluno );
    }else
    {
      inserir( &((*raiz)->direita), aluno );
    }
  }

}*/

void inserir(no_arv **raiz, aluno_arv aluno)
{
  no_arv *aux = *raiz;
  while(aux)
  {
    if(aluno.rgm < aux->aluno.rgm)
      raiz = &aux->esquerda;
    else
      raiz = &aux->direita;

    aux = *raiz;
  }
  aux = malloc(sizeof(no_arv));
  aux->aluno = aluno;
  aux->esquerda = NULL;
  aux->direita = NULL;
  *raiz = aux;
}

/*no_arv* buscar_binaria(no_arv *raiz, int rgm)
{
  if(raiz)
  {
    if(rgm == raiz->aluno.rgm)
      return raiz;
    else if(rgm < raiz->aluno.rgm)
      return buscar_binaria(raiz->esquerda, rgm);
    else
      return buscar_binaria(raiz->direita, rgm);
  }
  return NULL;
}
*/

no_arv* buscar_binaria(no_arv *raiz, int rgm)
{
  while(raiz)
  {
    if(rgm < raiz->aluno.rgm)
      raiz = raiz->esquerda;
    else if(rgm > raiz->aluno.rgm)
      raiz = raiz->direita;
    else
      return raiz;
  }
  return NULL;
}

no_arv* remover(no_arv *raiz, int rgm)
{
  if(raiz == NULL){
    printf("Valor não encontrado!");
  }else
  {
    if(raiz->aluno.rgm == rgm)
    {
      if(raiz->esquerda == NULL && raiz->direita == NULL)
      {
        /*Remove nó folha*/
        free(raiz);
        printf("\n\tAluno com RGM: %d foi removido.\n", rgm);
        return NULL;
      }else
      {
        no_arv *aux;
        /*Remove nó com um ou mais filhos*/
        if(raiz->esquerda != NULL && raiz->direita != NULL)
        {
        /*Remove nó com dois filhos*/
           aux = raiz->esquerda;
           while(aux->direita != NULL)
             aux = aux->direita;
           raiz->aluno = aux->aluno;
           aux->aluno.rgm = rgm;
           /* remove nó folha */ 
           raiz->esquerda = remover(raiz->esquerda, rgm);
           return raiz;
        }else
        {
        /*Remove nó com um filho*/
          if(raiz->esquerda != NULL)
            aux = raiz->esquerda;
          else
            aux = raiz->direita;
          free(raiz);
          printf("\n\tAluno com RGM: %d foi removido.\n", rgm);
          return aux;
        }
      }
    }else
    {
      if(rgm < raiz->aluno.rgm)
        raiz->esquerda = remover(raiz->esquerda, rgm);
      else
        /* Ao encontrar ele retorna NULL ou o ponteiro do filho */
        raiz->direita = remover(raiz->direita, rgm);

      return raiz;
    }
  }
}

no_arv* esvaziar_arvore(no_arv *raiz)
{
   if(raiz != NULL)
  {
    no_arv *aux;
    do{
      if(raiz->esquerda)
        aux = raiz->esquerda;
      else if(raiz->direita)
        aux = raiz->direita;
      else
        aux = raiz;

      raiz = remover(raiz, aux->aluno.rgm);
    }while(raiz);
    return raiz;
  }
}

void pre_ordem(no_arv *raiz)
{
  if(raiz != NULL)
  {
    printf("\n\tAluno: %s\n\tRGM: %d\n", raiz->aluno.nome, raiz->aluno.rgm);
    pre_ordem(raiz->esquerda);
    pre_ordem(raiz->direita);
  }
}

void em_ordem(no_arv *raiz)
{
  if(raiz != NULL)
  {
    em_ordem(raiz->esquerda);
    printf("\n\tAluno: %s\n\tRGM: %d\n", raiz->aluno.nome, raiz->aluno.rgm);
    em_ordem(raiz->direita);
  }
}

void pos_ordem(no_arv *raiz)
{
  if(raiz != NULL)
  {
    pos_ordem(raiz->esquerda);
    pos_ordem(raiz->direita);
    printf("\n\tAluno: %s\n\tRGM: %d\n", raiz->aluno.nome, raiz->aluno.rgm);
  }
}

int altura(no_arv *raiz)
{
  if(raiz == NULL){
    return -1;
  }
  else
  {
    int esq = altura(raiz->esquerda);
    int dir = altura(raiz->direita);
    if(esq > dir)
      return esq + 1;
    else
      return dir + 1;
  }
}

int quantidade_nos(no_arv *raiz)
{
  if(raiz == NULL)
    return 0;
  else
    return 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);
}

int quantidade_folhas(no_arv *raiz)
{
  if(raiz == NULL)
    return 0;
  else if(raiz->esquerda == NULL && raiz->direita == NULL)
    return 1;
  else{
    return quantidade_folhas(raiz->esquerda) + quantidade_folhas(raiz->direita);
  }
}

int main()
{
  no_arv *raiz = NULL,
         *busca; 
  aluno_arv aluno;
  int opcao, rgm;

  do{
    printf("\n=======================================================\n\n");
    printf("\tDigite um valor: ");
    printf("\n\t0 - Sair\n\t1 - Inserir Aluno\n\t2 - Remover Aluno por RGM\n\t3 - Pesquisar Aluno por RGM\n\t");
    printf("4 - Esvaziar a árvore\n\t5 - Exibir a árvore (pré-ordem)\n\t6 - Exibir a árvore (em-ordem)\n\t");
    printf("7 - Exibir a árvore (pós-ordem)\n\t");
    scanf("%d", &opcao);
    printf("\n=======================================================\n");
    switch(opcao)
    {
      case 1:
        printf("\n\tDigite o Nome do aluno: ");
        scanf("%s",aluno.nome);
        printf("\n\tDigite o RGM do aluno: ");
        scanf("%d", &aluno.rgm);
        /* Envia o endereço de memória do ponteiro raiz */
        inserir(&raiz, aluno);
        break;
      case 2:
        printf("\t");
        em_ordem(raiz);
        printf("\n\tDigite o RGM a ser removido: ");
        scanf("%d",&rgm);
        busca = buscar_binaria(raiz,rgm);
        if(busca){
          printf("\n\tAluno Removido!\n\n\tAluno: %s\n\tRGM: %d\n", busca->aluno.nome, rgm);
          raiz = remover(raiz,rgm);
        }else
        {
          printf("\n\tValor não encontrado.\n");
        }
        break;
      case 3:
        printf("\n\tDigite o RGM a ser buscado: ");
        scanf("%d",&rgm);
        busca = buscar_binaria(raiz,rgm);
        if(busca)
          printf("\n\tAluno encontrado!\n\n\tAluno: %s\n\tRGM: %d\n", busca->aluno.nome, rgm);
        else
          printf("\n\tAluno não encontrado.\n");
        break;
      case 4: 
        printf("\n\tEsvaziando árvore...");
        raiz = esvaziar_arvore(raiz);
        em_ordem(raiz);
        break;
      case 5:
        printf("\n\tImprimir\n");
        pre_ordem(raiz);
        break;
      case 6:
        printf("\n\tImprimir\n");
        em_ordem(raiz);
        break;
      case 7:
        printf("\n\tImprimir\n");
        pos_ordem(raiz);
        break;
      default:
        if(opcao != 0)
        {
          printf("Opção inválida!");
        }
    }
  }while(opcao != 0);

  return 0;
}
