#include <stdio.h>

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

int main() {
  int b = 38;
  unsigned int a = 23;

  init(); // Constructor like call

  printfBinaryUnsigned(a, 8 * sizeof(a));
  printfBinarySigned(b, 8 * sizeof(b));

  end(); // Destructor like call

  return 0;
}