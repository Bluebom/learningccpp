#include <stdio.h>
#include <stdlib.h>

int max(int num1, int num2)
{
  int result = num1;
  if(num2 > num1)
  {
    result = num2;
  }
  return result;
}

int main()
{
  int num1 = 9;
  int num2 = 10;

  printf("O maior entre %d e %d é %d", num1, num2, max(num1,num2));

  return 0;
}
