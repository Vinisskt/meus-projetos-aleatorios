#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define LETTERS 26

typedef struct Node {
  char value;
  struct Node *next;
} Node;

int check_node(Node *node) {
  if (node == NULL) {
    printf("error memory allocated");
    return 1;
  }
  return 0;
}

Node *cheate_node(char *value) {
  Node *node = malloc(sizeof(Node));
  node->next = NULL;
  node->value = *value;
  return node;
}

void print_list(Node *node) {
  Node *current = node;

  while (current != NULL) {
    printf("-> %c ", current->value);
    current = current->next;
  }
}

void free_linked_list(Node *node) {
  Node *current = node;
  Node *temp;

  while (current != NULL) {
    temp = current;
    current = current->next;
    free(temp);
  }
}

void  free_item_list(Node *node, char *item, Node **head) {
  Node *current = node;
  Node *prev = current;
  Node *temp;
  
  if (node == NULL) {
    return;
  }

  if (current->value == *item) {
    temp = current;
    current = current->next;
    *head  = current;
    free(temp);
    return;
  }

  while (current != NULL) {
    if (current->value == *item) {
      temp = current;
      current = current->next;
      prev->next = current;
      free(temp);
      break;
    }

    prev = current;
    current = current->next;
  }
}

int main(void) {

  srand(time(NULL));

  char first_letter = '0';
  Node *node = cheate_node(&first_letter);
  if (check_node(node) == 1) {
    return 1;
  }

  for (int i = 0; i < N; i++) {
    char letter = 'A' + rand() % LETTERS;
    Node *new_node = cheate_node(&letter);
    if (check_node(new_node) == 1) {
      return 1;
    }

    Node *current = node;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }

  print_list(node);

  char character = getchar();
  free_item_list(node, &character, &node);

  print_list(node);
  return 0;
}
