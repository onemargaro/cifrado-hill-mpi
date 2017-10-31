#include <stdio.h>
#include "utilities/library.h"
// #include <mpi.h>

/**
 * Nota el texto tiene de entrada tiene que ser en mayusculas
 */

int main(int argc, char *argv[])
{
  struct node *alpha = NULL, *searched;
  int vector[3];
  int *multVector, *module;
  char *cad;
  int i, j, k, count=0, rank, size;
  alpha = loadAlphabet(alpha);
  // MPI_Init(&argc, &argv);
  // MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  // MPI_Comm_size(MPI_COMM_WORLD, &size);
    FILE *fptr;
    char buff[1000];
    if ((fptr = fopen("./test.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }
    // TODO: repetir esto por cada uno de los procesos ejecutados
    while((cad = readText(fptr, buff)) != NULL)
    {
        cad = removeSpaces(cad);
        // printf("%d\n", (int)strlen(cad)/4);
        // Separar la cadena por n que es 3
        for (i = 0; i < strlen(cad); i++)
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
    }
    fclose(fptr);
  return 0;
}
