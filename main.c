#include <stdio.h>
#include "utilities/library.h"
#include <stdlib.h>
#include <mpi.h>
#define FILESIZE 30
/**
 * Nota el texto tiene de entrada tiene que ser en mayusculas
 */

int main(int argc, char *argv[])
{
  struct node *alpha = NULL, *searched;
  int vector[3];
  int *multVector, *module, bufsize;
  char *cad, *buffer;
  int i, j, k, count=0, rank, size, length, start, end;
  MPI_Offset filesize;
  alpha = loadAlphabet(alpha);
  MPI_File fh;
  MPI_Status status;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_File_open(MPI_COMM_WORLD,"./test.txt",MPI_MODE_RDONLY,MPI_INFO_NULL,&fh);
    MPI_File_get_size(fh, &filesize);
    length = filesize / size;
    start = length * rank;
    if (rank == size-1)
          end = filesize;
    else
          end = start + length;
    fprintf(stdout, "Proc %d: range = [%d, %d]\n", rank, start, end);
    buffer = (char *)malloc((end - start) * sizeof(char));
    if (buffer == NULL)
    {
      MPI_Finalize();
    }
    MPI_File_seek(fh, start, MPI_SEEK_SET);
    MPI_File_read_ordered(fh, buffer, end-start, MPI_BYTE, &status);
    cad = buffer;
    for (i = 0; i < strlen(cad); i++)
    {
      searched = search(alpha, 0, (char)cad[i], "value");
      vector[count++] = searched->key;
      if (count == 3)
      {
        multVector = multiplyVector(vector);
        module = getVectorThatContainsTheModule(multVector);
        for (k = 0; k < count; k++)
        {
          searched = search(alpha, *(module+k), ' ', "key");
          printf("%c",searched->value);
        }
        count=0;
      }
    }
    printf("\n");
    MPI_File_close(&fh);
  MPI_Finalize();
  return 0;
}
