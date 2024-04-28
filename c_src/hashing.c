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

// Hash function
int hash(int key) {
  // Putting the entry in the hash table
  return (key % kBucketSize);
}

// Create Linked List node
node_t *createNode(int data) {
  node_t *temp = malloc(sizeof(node_t)); // Create the node
  temp->data = data;                     // Put the key in the int pointer
  temp->link = NULL;                     // Pointer init

  return temp;
}

// Search key in the hash table
bool searchKey(node_t **hashTable, int key) {
  int hashKey = hash(key);
  node_t *ptr = hashTable[hashKey];
  while (ptr != NULL) {
    if (ptr->data == key) {
      printf("\nKey found");
      return true;
    } else {
      ptr = ptr->link;
    }
  }
  printf("\nKey not found");
  return false;
}

// Insert key in the hash table
void insertKey(node_t **hashTable, int key) {
  // Create a node to be stored
  node_t *temp = createNode(key);   // Arguement: data = key
  int hashKey = hash(key);          // Get hash key
  node_t *ptr = hashTable[hashKey]; // Get the corresponding pointer
  if (ptr == NULL) {                // First location to insert
    hashTable[hashKey] = temp;      // New head
    return;
  }
  while (ptr->link != NULL) { // Did not find an empty spot?
    ptr = ptr->link;
  }
  ptr->link = temp;
  printf("\nKey inserted");

  return;
}

// Delete key in the hash table
void deleteKey(node_t **hashTable, int key) {
  // Create a node to be stored
  int hashKey = hash(key);          // Get hash key
  node_t *ptr = hashTable[hashKey]; // Get the corresponding pointer
  while (ptr != NULL) {             // Did not find an empty spot?
    if (ptr->data == key) {
      printf("\nKey found and deleted");
      free(ptr);
    }
    ptr = ptr->link;
  }
}

// Create a hash table
node_t **createHashTable(int size) {
  node_t **arr = malloc(kBucketSize * sizeof(node_t *)); // Allocate array space
  for (int i = 0; i < kBucketSize; ++i) {                // Iniatise the array
    arr[i] = NULL;
  }
  return arr; // Hash table
}

void selfPacedDsa() {
  // Initializations
  // Create a hash data structure
  node_t **hashTable = createHashTable(kBucketSize); // Init hash table

  // Init statement
  printf("Hashing!");
  printf("\nImplement chaining");

  // Insert Keys
  int keys[] = {70, 71, 9, 56, 72};
  const int keySize = sizeof(keys) / sizeof(keys[0]);
  for (int i = 0; i < keySize; ++i) {
    insertKey(hashTable, keys[i]);
    searchKey(hashTable, keys[i]);
  }
  printf("\n");
  deleteKey(hashTable, keys[3]);
  searchKey(hashTable, keys[3]);
}

int main() {
  init(); // Constructor like call
  selfPacedDsa();
  end(); // Destructor like call

  return 0;
}