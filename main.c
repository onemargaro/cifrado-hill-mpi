#include <stdio.h>
#include "utilities/library.h"
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
  char *cad;
  int i, j, k, count=0, rank, size;
  alpha = loadAlphabet(alpha);
  MPI_File fh;
  MPI_Status status;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
    FILE *fptr;
    char work[4];
    bufsize = FILESIZE/size;
    int nchars = bufsize/sizeof(char);
    char buf[nchars];
    // if ((fptr = fopen("./test.txt", "r")) == NULL)
    // {
    //     printf("Error! opening file");
    //     exit(1);
    // }
    // TODO: repetir esto por cada uno de los procesos ejecutados
    MPI_File_open(MPI_COMM_WORLD,"./test.txt",MPI_MODE_RDONLY,MPI_INFO_NULL,&fh);
    // while()
    MPI_File_seek(fh, rank * bufsize, MPI_SEEK_SET);
    MPI_File_read_ordered(fh, buf, nchars, MPI_CHAR, &status);
    // printf("\nrank: %d, buf[%d]: %s", rank, rank*bufsize, buf);
    cad = formatText(buf);
    // printf("rank: %d ->%s\n", rank,cad);
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
          printf("rank: %d -> %c\n", rank,searched->value);
        }
        count=0;
      }
    }
    MPI_File_close(&fh);
    // if((cad = readText(fptr, buff, (size*3)+1)) != NULL)
    // {
      // cad = formatText(cad);
      // printf("%s\n", cad);
      // cad = formatText(cad);
      // MPI_Scatter(cad, 3, MPI_CHAR, work, 3, MPI_CHAR, 0, MPI_COMM_WORLD);
      // work[3] = '\0';
      // for (i = 0; i < strlen(work); i++)
      // {
      //   searched = search(alpha, 0, (char)work[i], "value");
      //   vector[count++] = searched->key;
      //   if (count == 3)
      //   {
      //     // aqui se multiplica
      //     multVector = multiplyVector(vector);
      //     module = getVectorThatContainsTheModule(multVector);
      //     for (k = 0; k < count; k++)
      //     {
      //       searched = search(alpha, *(module+k), ' ', "key");
      //       printf("%c", searched->value);
      //     }
      //     count=0;
      //   }
      // }
    // }
    // fclose(fptr);
  MPI_Finalize();
  return 0;
}
