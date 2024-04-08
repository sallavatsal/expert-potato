#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1

void printfBinaryUnsigned(unsigned int num, size_t size) {
  printf("\nUnsigned Binary = b");
  for (int i = (size - 1); i >= 0; --i) {
    printf("%d", (num >> i) & 1);
  }
  printf("\nActual Number = %d\n", num);
}

void printfBinarySigned(int num, size_t size) {
  printf("\nSigned Binary = b");
  for (int i = (size - 1); i >= 0; --i) {
    printf("%d", (num >> i) & 1);
  }
  printf("\nActual Number = %d\n", num);
}

void init() { // This will be like a constructor call
  printf("\n*************** Out ***************\n");
}

void end() { // This will be like a destructor call
  printf("\n***********************************\n\n");
}

// Swap two numbers
void swap(int *a, int *b) {
  (*a) = (*a) ^ (*b);
  (*b) = (*a) ^ (*b);
  (*a) = (*a) ^ (*b);
}

int main() {
  int a1 = 1, b = -23;        // signed number
  unsigned int a = 23;        // unsigned number
  char str[MAX];              // 1 character sized string
  void (*fPtr)(int *, int *); // function pointer
  fPtr = swap;                // Initializing

  init(); // Constructor like call

  printf("Get a string of size greater than 1 from the user: ");
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored                                                 \
    "-Wdeprecated-declarations" // Ignoring the warning
  if (gets(str) == NULL) {      // Check if data valid
    printf("gets error copying data");
    exit(1);
  } else {
    puts(str);
  }
#pragma GCC diagnostic pop

  printf("Max size that 'gets' can accept is %d character\nSize of string "
         "entered is %lu characters\nThis is why 'gets' is dangerous",
         MAX, strlen(str));
  (a1 > b) ? printf("\n\na is greater") : printf("\n\nb is greater");
  printf("\n");
  printfBinaryUnsigned(a, 8 * sizeof(a));
  printfBinarySigned(b, 8 * sizeof(b));
  printf("\n");

  printf("Before swap a = %d. b = %d\n", a1, b);
  fPtr(&a1, &b);
  printf("After swap a = %d. b = %d\n", a1, b);

  end(); // Destructor like call

  return 0;
}