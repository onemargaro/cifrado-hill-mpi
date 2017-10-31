#include <stdio.h>
#include "utilities/library.h"
#include <mpi.h>
#include <stdlib.h>
/**
 * Nota el texto tiene de entrada tiene que ser en mayusculas
 */

int main(int argc, char *argv[])
{
  struct node *alpha = NULL, *searched;
  int vector[3];
  int *multVector, *module;
  int i, j, k, count=0, rank, size;
  char *cad;
  char linea[12];
  char *cadenota;
  cadenota = calloc(12, sizeof(char));
  alpha = loadAlphabet(alpha);
  FILE *fptr;
  char work[4];
  char buff[12];
  if ((fptr = fopen("./test.txt", "r")) == NULL)
  {
      printf("Error! opening file");
      exit(1);
  }
  while (fgets(linea, 12, fptr) != NULL) {
     cadenota = (char *) realloc (cadenota, 12);
     strcat(cadenota, linea);
     printf("%s", linea);
  }
  free(cadenota);
  // MPI_Init(&argc, &argv);
  // MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  // MPI_Comm_size(MPI_COMM_WORLD, &size);
    // TODO: repetir esto por cada uno de los procesos ejecutados
    // if((cad = readText(fptr, buff, (size*3)+1)) != NULL)
    // {
    //   cad = formatText(cad);
    //   MPI_Scatter(cad, 3, MPI_CHAR, work, 3, MPI_CHAR, 0, MPI_COMM_WORLD);
    //   work[3] = '\0';
    //   for (i = 0; i < strlen(work); i++)
    //   {
    //     searched = search(alpha, 0, (char)work[i], "value");
    //     vector[count++] = searched->key;
    //     if (count == 3)
    //     {
    //       // aqui se multiplica
    //       multVector = multiplyVector(vector);
    //       module = getVectorThatContainsTheModule(multVector);
    //       for (k = 0; k < count; k++)
    //       {
    //         searched = search(alpha, *(module+k), ' ', "key");
    //         printf("%c", searched->value);
    //       }
    //       count=0;
    //     }
    //   }
    // }
  // MPI_Finalize();
  fclose(fptr);
  return 0;
}
