#include <stdio.h>
#include <stdlib.h>

int main()
{
  /*READ A FILE*/
  char line[255];

  FILE *fpointer = fopen("employees.txt","r");
  
  while(!feof(fpointer))
  {
    fgets(line, 255, fpointer);
    printf(" %s",line);
  }

  fclose(fpointer);

  /*STORE A FILE*/
  /*
  FILE *fpointer = fopen("employees.txt","w");
  
  fprintf(fpointer, "Jim, Salesman\nPam, Developer\nRobert, Receptionist\nOscar, Accounting\n");

  fprintf(fpointer, "See you next!");

  fclose(fpointer);
  */

  return 0;
}
