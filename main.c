#include <stdio.h>
#include "utilities/library.h"

int main(int argc, char *argv[])
{
  struct node *alpha = NULL, *searched=NULL;
  alpha = loadAlphabet(alpha);
  printf("Ingrese cadena que quiere cifrar\n");
  char* cad = readinput();
  printf("%s\n",cad);
  // Separar la cadena por n que es 3

  return 0;
}
