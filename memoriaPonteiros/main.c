#include <stdio.h>
#include <stdlib.h>

void func(int *pX, int *pY)
{
  pX = pY; // pX recebe o endereço de memoria armazenado no ponteiro pY, o conteudo desse endereço é y.
  *pY = (*pY) * (*pX); // y * y
  *pX = (*pX) + 2; // y + 2
}

int main()
{
  int x, y;

  scanf("%d", &x);
  scanf("%d", &y);
  
  func(&x, &y);

  printf("x = %d, y = %d\n", x, y);
  return 0;
}
