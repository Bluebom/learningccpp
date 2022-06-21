#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
  char name[50];
  char major[50];
  int age;
  double gpa;
};

int main()
{

  struct Student student1;
  student1.age = 22;
  student1.gpa = 3.2;
  strcpy( student1.name, "Jim" );
  strcpy( student1.major, "Businness" );
  

  struct Student student2;
  student2.age = 32;
  student2.gpa = 2.2;
  strcpy( student2.name, "Pam" );
  strcpy( student2.major, "Art" );

  printf("Nome: %s\nIdade: %d\n", student1.name, student1.age);
  printf("Nome: %s\nIdade: %d\n", student2.name, student2.age);
  return 0;
}
