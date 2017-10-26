#include <stdio.h>
#include "utilities/library.h"

/**
 * Nota el texto tiene de entrada tiene que ser en mayusculas
 */

int main(int argc, char *argv[])
{
  struct node *alpha = NULL, *searched;
  int vector[3];
  int *multVector, *module;
  int i, j, k, count=0;
  alpha = loadAlphabet(alpha);
  printf("Ingrese cadena que quiere cifrar\n");
  char* cad = readinput();
  // Separar la cadena por n que es 3
  for (i = 0; i < strlen(cad)-1; i++)
  {
    searched = search(alpha, 0, (char)cad[i], "value");
    vector[count++] = searched->key;
    if (count == 3)
    {
      // aqui se multiplica
      multVector = multiplyVector(vector);
      module = getVectorThatContainsTheModule(multVector);
      for (k = 0; k < count; k++)
      {
        searched = search(alpha, *(module+k), ' ', "key");
        printf("%c", searched->value);
      }
      count=0;
    }
  }
  return 0;
}
