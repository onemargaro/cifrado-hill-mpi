#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// TODO: algoritmo de cifrado hill


char* removeSpaces(char* input){
    int i;
    char *output = (char*) malloc (strlen(input));
    char *dest = output;

    if (output)
    {
        for (i=0; i<strlen(input); i++)
            if (input[i] != ' ')
                *dest++ = input[i];

        *dest = '\0';
    }
    return output;
}

char* readinput(){
  #define CHUNK 200
   char* input = NULL;
   char tempbuf[CHUNK];
   size_t inputlen = 0, templen = 0;
   do {
       fgets(tempbuf, CHUNK, stdin);
       templen = strlen(tempbuf);
       inputlen += templen;
       input = realloc(input, inputlen+1);
       strcat(input, tempbuf);
    } while (templen==CHUNK-1 && tempbuf[CHUNK-2]!='\n');
    input = removeSpaces(input);
    return input;
}


int main(){
	
	int c,d,n,j,k;
	int first[3][3], cod[5][3], res[3][1];
    
  printf("Ingrese cadena que quiere cifrar\n");
  char* cad = readinput();

  printf("Ingrese n: \n");
  scanf("%d",&n);

  printf("Ingresa los elementos de la matriz de cifrado\n");
 
  for (c = 0; c < 3; c++)
    for (d = 0; d < 3; d++)
      scanf("%d", &first[c][d]);

/*printf("Matriz de cifrado\n");
    for (c = 0; c < 3; c++) {
      for (d = 0; d < 3; d++)
        printf("%d\t", first[c][d]);
      printf("\n");
    }*/    
  printf("%s\n",cad);
  printf("Tamaño de la palabra: %lu\n",strlen(cad));
  
  free(cad);
  
  return 0;
}