#include <stdio.h>
#include <stdlib.h>

double cube(double num)
{
  return num * num * num;
}

void helloU(char name[], int age)
{
  printf("Hello %s, %d.\n", name, age);
}

int main()
{
  helloU("Franklin", 22);
  printf("Answer: %.2lf.", cube(5.0));
  return 0;
}

