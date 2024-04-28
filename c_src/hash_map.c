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
  int value;
  char *key;
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

// Hash function
int hash(const char *key, int val) {
  int hash = 0;
  int len = strlen(key);
  for (int i = 0; i < len; i++) {
    hash += key[i];
  }
  hash += val;
  return hash % kBucketSize;
}

// Create Linked List node
node_t *createNode(char *key, int data) {
  node_t *temp = malloc(sizeof(node_t)); // Create the node
  temp->value = data;                    // Put the key in the int pointer
  temp->key = strdup(key);               // Copy the key
  temp->link = NULL;                     // Pointer init with NULL
  return temp;
}

// Search key in the hash table
bool searchKey(node_t **hashMap, char *key, int val) {
  int hashKey = hash(key, val);
  node_t *ptr = hashMap[hashKey];
  while (ptr != NULL) {
    if (strcmp(ptr->key, key) == 0) {
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
void insertKey(node_t **hashMap, char *key, int val) {
  // Create a node to be stored
  node_t *temp = createNode(key, val); // Argument: data = key
  int hashKey = hash(key, val);        // Get hash key
  if (hashMap[hashKey] == NULL) {      // If the bucket is empty
    hashMap[hashKey] = temp;           // Set the new node as the head
  } else {                             // If the bucket already has nodes
    node_t *ptr = hashMap[hashKey];
    while (ptr->link != NULL) { // Traverse to the end of the linked list
      ptr = ptr->link;
    }
    ptr->link = temp; // Append the new node to the end
  }
  printf("\nKey inserted");
}

// Delete key in the hash table
void deleteKey(node_t **hashMap, char *key, int val) {
  int hashKey = hash(key, val);
  node_t *ptr = hashMap[hashKey];
  node_t *prev = NULL;
  while (ptr != NULL) {
    if (strcmp(ptr->key, key) == 0) {
      printf("\nKey found and deleted");
      if (prev == NULL) { // If the key to delete is at the head
        hashMap[hashKey] = ptr->link;
      } else {
        prev->link = ptr->link;
      }
      free(ptr->key); // Free the memory for the key
      free(ptr);      // Free the memory for the node
      break;          // Break out of the loop after deleting
    }
    prev = ptr;
    ptr = ptr->link;
  }
}

// Create a hash table
node_t **createHashMap(int size) {
  node_t **arr = malloc(kBucketSize * sizeof(node_t *)); // Allocate array space
  for (int i = 0; i < kBucketSize; ++i) {                // Iniatise the array
    arr[i] = NULL;
  }
  return arr; // Hash table
}

void selfPacedDsa() {
  // Initializations
  // Create a hash data structure
  node_t **hashMap = createHashMap(kBucketSize); // Init hash table

  // Init statement
  printf("Hashing!");
  printf("\nImplement chaining");

  // Insert Keys
  char keys[kBucketSize][20] = {"giberish", "giberis",  "giberizz", "gibarish",
                                "gberish",  "geberish", "jiberish"};
  const int keySize = sizeof(keys) / sizeof(keys[0]);
  for (int i = 0; i < keySize; ++i) {
    int val = i;
    insertKey(hashMap, keys[i], val);
    searchKey(hashMap, keys[i], val);
  }
  printf("\n");
  deleteKey(hashMap, keys[3], 3);
  searchKey(hashMap, keys[3], 3);
}

int main() {
  init(); // Constructor like call
  selfPacedDsa();
  end(); // Destructor like call

  return 0;
}