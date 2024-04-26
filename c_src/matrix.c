// Standard libraries
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b)) ? (a) : (b)
#define MAX_OF_THREE(a, b, c) (MAX(MAX((a), (b)), (c)))

void init() { // This will be like a constructor call
  printf("\n*************** Out ***************\n\n");
}

void end() { // This will be like a destructor call
  printf("\n\n***********************************\n\n");
}

void printMatrix(char *str, int *arr, size_t size) {
  printf("%s", str);
  for (int i = 0; i < size; ++i) {
    printf("%d ", arr[i]);
  }
}

void selfPacedDsa() {
  // Initializations
  int arr[][2] = {
      {10, 20},
      {30, 40},
      {50, 60}}; // Omitting first dimension as compiler can still understand it
  size_t size = sizeof(arr) / sizeof(arr[0]);
  int x = 50;

  // Init statement
  printf("Matrix!\n");
}

int main() {
  init(); // Constructor like call
  selfPacedDsa();
  end(); // Destructor like call

  return 0;
}