#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  int age;
  double gpa;
  char grade;
};

int main()
{
  struct Person person1;

  int age = 33;
  int *pAge = &age;

  person1.age = 30;
  person1.gpa = 3.4;
  person1.grade = 'A';
  
  printf("Idade:  %d\npIdade: %d\n", age, *pAge);

  return 0;
}
