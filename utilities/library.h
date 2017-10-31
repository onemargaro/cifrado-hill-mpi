#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int key;
    char value;
    struct node *next;
};

void insert(struct node **head, int key, char value);
char* readinput();
char* removeSpaces(char* input);
struct node* search(struct node *head, int key, char value, char *searchBy);
void print(struct node *head);
struct node* loadAlphabet(struct node *alpha);
int* getVectorThatContainsTheModule(int *vector);
int* multiplyVector(int *vector);

char* readText(FILE *fptr, char buff[1000]) {
  if (fgets(buff, 1000, fptr) == NULL){
    return NULL;
  }else{
    return buff;
  }
}

char* removeSpaces(char* input){
    int i;
    char *output = (char*) malloc (strlen(input));
    char *dest = output;

    if (output)
    {
        for (i=0; i<strlen(input); i++)
            if (input[i] != ' ' && input[i] != '\n')
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

/**
 * load alphabet with struct passed
 * @param  alpha node for load the alphabet
 * @return       pointer to alphabet
 */
struct node* loadAlphabet(struct node *alpha){
    insert(&alpha, 0, 'A');
    insert(&alpha, 1, 'B');
    insert(&alpha, 2, 'C');
    insert(&alpha, 3, 'D');
    insert(&alpha, 4, 'E');
    insert(&alpha, 5, 'F');
    insert(&alpha, 6, 'G');
    insert(&alpha, 7, 'H');
    insert(&alpha, 8, 'I');
    insert(&alpha, 9, 'J');
    insert(&alpha, 10, 'K');
    insert(&alpha, 11, 'L');
    insert(&alpha, 12, 'M');
    insert(&alpha, 13, 'N');
    insert(&alpha, 14, 'O');
    insert(&alpha, 15, 'P');
    insert(&alpha, 16, 'Q');
    insert(&alpha, 17, 'R');
    insert(&alpha, 18, 'S');
    insert(&alpha, 19, 'T');
    insert(&alpha, 20, 'U');
    insert(&alpha, 21, 'V');
    insert(&alpha, 22, 'W');
    insert(&alpha, 23, 'X');
    insert(&alpha, 24, 'Y');
    insert(&alpha, 25, 'Z');
    insert(&alpha, 26, '0');
    insert(&alpha, 27, '1');
    insert(&alpha, 28, '2');
    insert(&alpha, 29, '3');
    insert(&alpha, 30, '4');
    insert(&alpha, 31, '5');
    insert(&alpha, 32, '6');
    insert(&alpha, 33, '7');
    insert(&alpha, 34, '8');
    insert(&alpha, 35, '9');
    insert(&alpha, 36, ' ');
    return alpha;
}

/**
 * insert a key=>value struct in a list
 * @param head  pointer to head list
 * @param key   key to insert
 * @param value value to insert
 */
void insert(struct node **head, int key, char value){
    int i;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->value = value;
    if (*head == NULL){
        *head = temp;
        temp->next = NULL;
    }else{
        temp->next = *head;
        *head = temp;
    }
}

/**
 * search in list(key, value) by "key" or "value"
 * @param  head     pointer to list
 * @param  key      key to search | default 0 int
 * @param  value    value to search | default " " char
 * @param  searchBy type of serach "key" or "value"
 * @return          pointer with element
 */
struct node* search(struct node *head, int key, char value, char *searchBy){
    while (head != NULL){
      if (!strcmp(searchBy, "key")){
        if (head->key == key){
            return head;
        }
        head = head->next;
      }else if(!strcmp(searchBy, "value")){
        if (head->value == value){
            return head;
        }
        head = head->next;
      }else{
        printf("Especifica una busqueda valida\n");
        return NULL;
      }
    }
    return NULL;
}

void print(struct node *head){
  while (head != NULL){
    printf("key=%d  value=%c\n", head->key, head->value);
    head = head->next;
  }
}

/**
 * get the requested vector module
 * @param   vector      pointer to vector
 * @return  resultVector  pointer to new vector
 */
int* getVectorThatContainsTheModule(int *vector) {
  int numModule = 36;
  int i;
  int *resultVector = (int*) calloc(3, sizeof(int));

  for(i=0; i<3; i++) {
    *(resultVector+i) = *(vector+i) % numModule;
  }

  return resultVector;
}

/**
 * multiply vector by preset matrix
 * @param   vector      pointer to vector
 * @return  resultVector  pointer to new vector
 */
int* multiplyVector(int *vector) {
  //Def Matrix
  int matrix[3][3] = {1,2,3, 0,4,5, 1,0,6};
  //Reserving memory for new vector
  int *resultVector = (int*) calloc(3, sizeof(int));
  int i,j;
  //Iterating the matrix and multiplying by the vector pointer
  for(i=0; i<3; i++) {
    for(j=0; j<3; j++) {
      *(resultVector + i) += matrix[i][j] * (*(vector + j));
    }
  }
  return resultVector;
}



