// Standard libraries
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void init() { // This will be like a constructor call
  printf("\n*************** Out ***************\n\n");
}

void end() { // This will be like a destructor call
  printf("\n\n***********************************\n\n");
}

void printBinary(uint8_t n) {
  for (int i = 7; i >= 0; --i) {
    if (((n >> i) & 1) == 1) {
      printf("1");
    } else {
      printf("0");
    }
  }
}

/* Check if kth bit is set in integer n
 * Algorithm: Brian Kerningam's to count set bits
 */
bool checkKthBitSet(int n, int k) { return ((n >> (k - 1)) & 1); }

// Count set bits in integer n
int countSetBits(int n) {
  int count = 0;
  while (n) { // Reduce n until it becomes 0
    n = n & (n - 1);
    count++;
  }
  return count;
}

/* Count set bits in O(1) time with some pre-processing
 * Use Brian Kerningam's algorithm
 * Pre-compute all the values for a 8-bit number
 * and use it for 32 bit number
 */
int countSetBitsTable(int n) {
  int res;

  // Pre-processing
  int *table = malloc(256 * sizeof(int));

  // Initialize the table
  table[0] = 0;

  // Brian Kerningam's algorithm to get remaning table elements
  for (int i = 1; i < 256; ++i) {
    table[i] = table[i & (i - 1)] + 1; // Clearing last bit and adding 1
                                       // to re-use previous compute values
  }
  // Computing results in O(1) time
  res = table[n & (0xFF)] + table[(n >> 8) & (0xFF)] +
        table[(n >> 16) & (0xFF)] + table[(n >> 24) & (0xFF)];

  free(table); // Clearing heap used

  return res;
}

/* Count number of streams of 1s in a number
 * Test cases tried:
 * n = 21378;       // 0b101001110000010
 * n = 21845;       // 0b101010101010101
 * n = 0;           // 0b0
 * n = 0xFFFFFFFF;  // 0b1111_1111_1111_1111_1111_1111_1111_1111
 * n = 0xAAAAAAAA;  // 0b1010_1010_1010_1010_1010_1010_1010_1010
 */
int countBitStream(long int n) {
  int count = 0;
  while (n) { // 1
    if (n & 1) {
      count++;
      while (n & 1)
        n >>= 1;
    } else { // 0
      n >>= 1;
    }
  }
  return count;
}

// Find the two odd appearing numbers elements and print
void findTwoOdd(int *arr, size_t size) {
  int res = 0;
  int num1 = 0;
  int num2 = 0;
  for (int i = 0; i < size; ++i) {
    res ^= arr[i];
  }
  // Rightmost set bit
  int k = res & (~(res & (res - 1)));
  for (int i = 0; i < size; ++i) {
    if ((arr[i] & k) != 0) { // Find if kth bit is 1
      num1 ^= arr[i];
    } else { // If kth bit is 0
      num2 ^= arr[i];
    }
  }
  printf("%d %d", num1, num2);

  return;
}

// Power Set using bitwise operator for a modifiable character array
void genPowerSet(char *s, size_t size) {
  for (int i = 0; i < pow(2, size); ++i) {
    for (int j = 0; j < size; ++j) {
      if ((i & (1 << j)) != 0) {
        printf("%c", s[j]);
      }
    }
    printf(" ");
  }
  return;
}

// Swap the nibbles of two number
void swapNibbles(uint8_t *n) {
  uint8_t temp = *n;
  temp = (((temp & 0x0F) << 4) | ((temp & 0xF0) >> 4));
  *n = temp;
}

// Swap bits in a given number
void swapBits(int *n, int p1, int p2) {
  // Check if these bits are different. If they are, swap them!
  if (((*n >> p1) & 1) != ((*n >> p2) & 1)) {
    *n ^= (1U << p1);
    *n ^= (1U << p2);
  }
}

void swapNbits(int *n, int p1, int p2, int numBits) {
  int mask = (1U << numBits) - 1; // Left shift of 1U is like multiplying by 2
  int set1 = (*n >> p1) & mask;
  int set2 = (*n >> p2) & mask;
  int xor = set1 ^ set2;
  xor = (xor << p1) | (xor << p2);
  *n = *n ^ xor;
}

void selfPacedDsa() {
  // Initializations
  int n = 47, m = 7, k = 2;
  uint8_t num = 32;

  // Init statement
  printf("Bit manipulation!\n");

  // Check if kth bit set
  printf("\nIs bit %d set in %d? ", k, n);
  if (checkKthBitSet(n, k)) {
    printf("Yes");
  } else {
    printf("No");
  }

  // Number of set bits count with O(log n) and O(1) solutions
  printf("\nNumber of set bits using O(log n) solution in %d is %d", n,
         countSetBits(n));
  printf("\nNumber of set bits using table pre-processing in %d is %d", n,
         countSetBitsTable(n));

  // Count bit streams of 1
  printf("\nBit streams of 1 = %d", countBitStream(n));

  // Find the two odd appearing numbers elements
  int arr1[] = {3, 4, 3, 32, 16, 4, 6, 6, 7, 7};
  printf("\nTwo odd appearing elements = ");
  findTwoOdd(arr1, (size_t)(sizeof(arr1) / sizeof(arr1[0])));

  // Generate power set of a set of characters: a, b, c for instance
  char s[] = {'a', 'b', 'c'}; // Modifiable character array
  printf("\nPower set of character array s = ");
  genPowerSet(s, (size_t)(sizeof(s) / sizeof(s[0])));

  // Nibble swaps of two numbers
  printf("\nBefore nibble swap: \t0b ");
  printBinary(num);
  swapNibbles(&num);
  printf("\nAfter nibble swap: \t0b ");
  printBinary(num);

  // Swap bits
  int p1 = 1, p2 = 4;
  printf("\nBefore bit 1 and bit 4 swap: \t0b ");
  printBinary(n);
  swapBits(&n, p1, p2);
  printf("\nAfter bit 1 and bit 4 swap: \t0b ");
  printBinary(n);

  // Swap multiple bits
  int numBits = 3;
  n = 47;
  printf("\nBefore swapping bits at locations bit 1 and bit 4: \t0b ");
  printBinary(n);
  swapNbits(&n, p1, p2, numBits); // p1<p2 and bits do not overlap
  printf("\nAfter swapping bits at locations bit 1 and bit 4: \t0b ");
  printBinary(n);
}

int main() {
  init(); // Constructor like call
  selfPacedDsa();
  end(); // Destructor like call

  return 0;
}