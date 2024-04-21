#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX 10
// // Maximum of two numbers. Only works for *GCC*
// #define MAX(a, b) \
//   __type__(a) _a = a; \
//   __type__(b) _b = b; \ _a > _b ? _a : _b;

// Struct about cars
typedef struct {
  int year;
  char make[10];
} cars_t;

void init() { // This will be like a constructor call
  printf("\n*************** Out ***************\n\n");
}

void end() { // This will be like a destructor call
  printf("\n\n***********************************\n\n");
}

// Print bits
void print_bits(uint8_t a, int size) {
  for (int i = (size - 1); i >= 0; --i) {
    printf("%d ", (a >> i) & (0x1)); // Print bits
  }
}

// Bitwise operators activities
void bitwise_ops() {
  uint8_t a = 0x9B;            // Binary: b1001_1011
  int size = sizeof(a) * 8;    // Size of a in bits
  uint8_t bit4 = (a >> 3) & 1; // Bit number 4 in a
  uint8_t bit7 = (a >> 6) & 1; // Bit number 7 in a

  printf("Bitwise operators fun exercise\n");
  printf("Set bit numbers 3, and 6. Clear bit number 8\n");
  printf("Before: b ");
  print_bits(a, size);
  printf("\n");

  a |= (1 << 2);    // set bit number 3
  a |= (1 << 5);    // set bit number 6
  a &= (~(1 << 7)); // clear number 8
  printf("After:  b ");
  print_bits(a, size);

  printf("\n\nSwap bit number 4 and 7");
  printf("\nBefore: b ");
  print_bits(a, size);
  printf("\n");
  if (bit4 != bit7) { // Check if these numbers are same. If so don't swap
    a ^= (1 << 3);    // XOR with 1 flips, with 0 keeps it as it is
    a ^= (1 << 6);    // XOR with 1 flips, with 0 keeps it as it is
    printf("Swapped\n");
  } else {
    printf("They are same\n");
  }
  printf("After:  b ");
  print_bits(a, size);
}

void string_ops() {
  const char src[MAX] = "Vatsal_S";
  char dest[MAX] = "";

  size_t src_size = sizeof(src) - 1;   // Size of source string buffer
  size_t dest_size = sizeof(dest) - 1; // Size of destination string buffer

  // String copy, Mem copy, Mem move
  if (dest_size >= src_size) {
    printf("\n\nString before copy: %s", dest);
    strncpy(dest, src, strlen(src));
    printf("\nString after copy: %s", dest);
  } else {
    printf("\n\nDestination cannot hold src data as it's size is smaller\n"
           "Warning! Potential buffer overflow!");
  }
  int src1[MAX] = {1, 2, 3}, src2[MAX] = {4, 5, 6}; // New strings defined
  int dest1[MAX] = {}, dest2[MAX] = {};             // New strings defined
  memcpy(dest1, src1, sizeof(src1));                // Copy using memcpy
  memmove(dest2, src2, sizeof(src2));               // Copy using memmove
  printf("\nContents of dest1 = ");
  for (int i = 0; i < MAX; ++i) {
    printf("%d ", dest1[i]);
  }
  printf("\nContents of dest2 = ");
  for (int i = 0; i < MAX; ++i) {
    printf("%d ", dest2[i]);
  }

  // String comparison, Mem comparison
  if (strlen(src) == strlen(dest)) { // Check if it's a fair comparison
    int comp = strncmp(src, dest, src_size);
    if (comp == 0)
      printf("\n\nSrc and dest strings are equal");
    else if (comp > 0)
      printf("\n\nSrc is greater than destination");
    else
      printf("\n\nSrc is smaller than destination");
  } else { // If it's not a fiar comparison
    printf("\n\nNot comparable as lenghths are different");
  }
  int comp_mem = memcmp(dest1, dest2, MAX); // Compare two blocks of memory
  printf("\n\nComparison value = %d", comp_mem);

  cars_t car1 = {1990, "Ford"};
  cars_t car2 = {2000, "Ferrari"};
  if (memcmp(&car1, &car2, sizeof(cars_t)) == 0)
    printf("\n\nCustom data structures are equal");
  else
    printf("\n\nStructs are not equal");

  // String catenation
  char cat_str[2 * MAX] = ""; // Variable to test string catenation results
  if (sizeof(cat_str) >=
      (strlen(src) + strlen(dest))) { // Check if string catenation is possible
    strncat(cat_str, src, strlen(src));
    strncat(cat_str, dest, strlen(dest)); // Catenate dest string
    printf("\n\nConcatenated str = %s", cat_str);
  } else { // Print if it was not succesful
    fprintf(stdout, "\nString catenation did not complete successfully");
  }

  // String tokenization
  char str[10 * MAX] = "Visual Studio Code Is Good For Programming";
  const char delim[1] = " ";        // String literal
  char *token = strtok(str, delim); // Tokenizing. First token
  if (token == NULL) {
    printf("\n\nTokenizing was not succesful");
  }
  printf("\n\nFirst token was successful = %s", token);
  while (token != NULL) {
    token = strtok(NULL, delim); // Keep going until you see token = NULL
    if (token != NULL)           // String literal
      printf("\nToken successfull = %s", token); // String literal
  }

  // Mem-set: Used to set a block of memory
  // Can be used to initialize a block of memory
  memset(str, 'A',
         (sizeof(str) -
          1)); // Removing the null character and printing max characters
  printf("\n\nstr = %s", str);

  // First occurence, NULL if not found
  printf("\n\nString to find first & last occurence = %s", cat_str);
  char *ptr1 = strchr(cat_str, 'a');
  if (ptr1 != NULL)
    printf("\nFirst occurence of %c is at index = %d", 'a',
           (int)(ptr1 - cat_str)); // First occurence
  else
    printf("\nNo match found!");
  //  Last occurence, NULL if not found
  char *ptr2 = strrchr(cat_str, 'a');
  if (ptr2 != NULL)
    printf("\nLast occurence of %c is at index = %d", 'a',
           (int)(ptr2 - cat_str)); // Last occurence
  else
    printf("\nNo match found!");
}

int main() {
  init(); // Constructor like call
  bitwise_ops();
  string_ops();
  end(); // Destructor like call

  return 0;
}