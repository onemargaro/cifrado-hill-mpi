
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int key;
    char value;
    struct node *next;
};

void insert(struct node **head, int key, char value);
struct node* search(struct node *head, int key, char value, char *searchBy);
void print(struct node *head);
struct node* loadAlphabet(struct node *alpha);

int main(){
  struct node *alpha = NULL, *searched=NULL;
  alpha = loadAlphabet(alpha);
  searched = search(alpha, 23, ' ', "key");
  printf("find key=%d value=%c\n", searched->key, searched->value);
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
