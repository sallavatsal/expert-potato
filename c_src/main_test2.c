#include <stdint.h>
#include <stdio.h>

void init() { // This will be like a constructor call
  printf("\n*************** Out ***************\n\n");
}

void end() { // This will be like a destructor call
  printf("\n\n***********************************\n\n");
}

void bitwise_ops() {
  uint8_t a = 0x9B;            // Binary: b1001_1011
  int size = sizeof(a) * 8;    // Size of a in bits
  uint8_t bit4 = (a >> 3) & 1; // Bit number 4 in a
  uint8_t bit7 = (a >> 6) & 1; // Bit number 7 in a

  printf("Bitwise operators fun exercise\n");
  printf("Set bit numbers 3, and 6. Clear bit number 8\n");
  printf("Before: b ");
  for (int i = (size - 1); i >= 0; --i) {
    printf("%d ", (a >> i) & (0x1)); // Print bits
  }
  printf("\n");

  a |= (1 << 2);    // set bit number 3
  a |= (1 << 5);    // set bit number 6
  a &= (~(1 << 7)); // clear number 8
  printf("After:  b ");
  for (int i = (size - 1); i >= 0; --i) {
    printf("%d ", (a >> i) & (0x1)); // Print bits
  }

  printf("\n\nSwap bit number 4 and 7");
  printf("\nBefore: b ");
  for (int i = (size - 1); i >= 0; --i) {
    printf("%d ", (a >> i) & (0x1)); // Print bits
  }
  printf("\n");
  if (bit4 != bit7) { // Check if these numbers are same. If so don't swap
    a ^= (bit7 << 3);
    a ^= (bit4 << 6);
    printf("Swapped\n");
  } else {
    printf("They are same\n");
  }
  printf("After:  b ");
  for (int i = (size - 1); i >= 0; --i) {
    printf("%d ", (a >> i) & (0x1)); // Print bits
  }
}

int main() {
  init(); // Constructor like call
  bitwise_ops();
  end(); // Destructor like call

  return 0;
}