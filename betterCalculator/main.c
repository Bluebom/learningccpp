#include <stdio.h>
#include <stdlib.h>

void myPrint(char desc[])
{
  printf("%s ", desc);
  fgetc(stdin);
}

int main()
{
  double num1;
  double num2;
  char op;

  printf("Enter a number: ");
  scanf("%lf", &num1);
  myPrint("Enter operator:");
  scanf(" %c", &op);
  myPrint("Enter another number:");
  scanf("%lf", &num2);

  if(op == '+')
  {
    printf("%.2lf", num1 + num2);
  }else if(op == '-')
  {
    printf("%.2lf", num1 - num2);
  }else if(op == '/')
  {
    printf("%.2lf", num1 / num2);
  }else if(op == '*')
  {
    printf("%.2lf", num1 * num2);
  }else
  {
    printf("Operador inválido!");
  }

  return 0;
}
