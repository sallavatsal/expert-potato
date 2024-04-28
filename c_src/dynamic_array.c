// Standard libraries
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b)) ? (a) : (b)
#define MAX_OF_THREE(a, b, c) (MAX(MAX((a), (b)), (c)))
#define ROWS1 4

// Constants
const int kBucketSize = 7;

// Dynamic sized array
typedef struct {
  size_t size;
  size_t cap;
  int *arr;
} vector_t;

// Singly Linked List
struct node {
  int data;
  struct node *link;
};
typedef struct node node_t; // Typedef struct node

void init() { // This will be like a constructor call
  printf("\n*************** Out ***************\n\n");
}

void end() { // This will be like a destructor call
  printf("\n\n***********************************\n\n");
}

/* Swap two elements */
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

vector_t *dynamicArrayInit(const int cap) {
  vector_t *temp;
  temp->arr = malloc(cap * sizeof(int));
  temp->cap = cap;
  temp->size = 0;
  return temp;
}

void freeArrayOfLinkedLists(node_t **heads) {
  // Free
  free(heads);
}

void deleteDynamicArray(vector_t *temp) {
  // Free array space
  free(temp->arr);
}

int getSize(vector_t *temp) {
  // Get size
  return temp->size;
}

int getCap(vector_t *temp) {
  // Get capacity
  return temp->size;
}

void append(vector_t *temp, int x) {
  if (temp->size == temp->cap) {
    temp->cap = 2 * (temp->cap);               // Update capacity
    temp->arr = realloc(temp->arr, temp->cap); // Reallocate memory
    if (temp->arr == NULL) {
      printf("\nMalloc error reported");
    }
    (temp->size)++; // Increment size
    temp->arr[temp->size] = x;
  }
}

void selfPacedDsa() {
  // Initializations

  // Init statement
  printf("Dynamic array in C - Vector properties of Cpp!");
}

int main() {
  init(); // Constructor like call
  selfPacedDsa();
  end(); // Destructor like call

  return 0;
}