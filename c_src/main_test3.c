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

// Sum of n natural numbers
void sumNaturalNumbs(int n) {
  printf("Sum of n natural numbers = %d", (n * (n + 1) / 2)); // O(1) solution
}

int countDigits(int n) {
  int count = 0;
  while (n) {
    n /= 10;
    count++;
  }
  return count;
}

bool checkPalindrome(int n) {
  int original_num = n; // Remember
  int res = 0;
  while (n) {
    res = 10 * res + n % 10; // Recreating the number in reverse
    n /= 10;
  }
  return (res == original_num); // Compare and return
}

int calculateFact(int n) {
  if (n == 0)
    return n;                      // Base case
  return (n)*calculateFact(n - 1); // Tail recursive solution
}

int countTrailingZeros(int n) {
  int count = 0;
  for (int i = 5; i <= n; i = i * 5) {
    count += n / i; // Count number of 5s, 25s, 125s..
  }
  return count;
}

// Getting GCD with Euclid's algorithm
/* Algorithm definition: gcd(a, b) = gcd(a-b, b)
 * Why? Example...
 * gcd(a, b) = g            (say, 'g' gcd of a & b)
 * a = g*x, b = g*y
 * Here, gcd(x, y) = 1
 * (a - b) = g(x - y)
 * Thus, since (x-y) does not have another gcd,
 * gcd(a, b) is same as gcd(a-b). Hence, Proved!
 */
int getGCD_euclidean(int a, int b) {
  while (a != b) {
    if (a > b)
      a = a - b;
    else
      b = b - a;
  }
  return a;
}
/* Advance version of Euclidean Algorithm - using modulo */
int getGCD_euclidean_advance(int a, int b) {
  if (b == 0)
    return a;
  else
    return getGCD_euclidean_advance(b, a % b);
}

/* LCM - O(a*b - max(a, b))
 * Efficient solution?
 * (a * b) = gcd(a, b) * lcm(a, b)
 */
int getLCM(int a, int b) {
  int max = ((a > b) ? a : b);
  while ((max % a != 0) || (max % b != 0)) {
    max++;
  }
  return max;
}

// Prime number check
// Divisors always appear in pairs
bool isPrime(int n) {
  if (n <= 1)
    return false;
  if (n == 2 || n == 3)
    return true;
  if ((n % 2 == 0) || (n % 3 == 0))
    return false;
  for (int i = 5; i * i <= n; ++i) {
    if ((n % (6 * i - 1) == 0) || (n % (6 * i + 1) == 0))
      return false;
  }
  return true;
}

// Print prime factors of given number n
void printPrimeFactors(int n) {
  printf("\nPrime factors of %d = ", n);
  if (n <= 1)
    return;
  while (n % 2 == 0) { // Divide by 2
    printf("2 ");
    n /= 2;
  }
  while (n % 3 == 0) { // Divide by 3
    printf("3 ");
    n /= 3;
  }
  for (int i = 1; i * i <= n; ++i) {
    while (n % (6 * i - 1) == 0) {
      printf("%d ", (6 * i - 1));
      n /= (6 * i - 1);
    }
    while (n % (6 * i + 1) == 0) {
      printf("%d ", (6 * i + 1));
      n /= (6 * i + 1);
    }
  }
  if (n > 3) // Any prime number greater than 3
    printf("%d", n);
  return;
}

/* Print divisors of a given number
 * Algorithm: Divisors appear in pairs
 * For instance, divisors of 30 are 1, 2, 3, 5, 6, 10, 15, 30
 * Divisor pairs:
 * (1, 30); (2, 15); (3, 10); (5, 6)
 * (30, 1); (15, 2); (10, 3); (6, 5)
 */
void printDivisorsInOrder(int n) {
  int i;
  printf("\nDivisors of %d in order are: ", n);
  // Tranverse from 1 to sqrt(n)
  for (i = 1; i * i < n; ++i) {
    if (n % i == 0) {
      printf("%d ", i);
    }
  }
  // REVERSE: Traverse from sqrt(n) to 1
  for (; i >= 1; --i) {
    if (n % i == 0) {
      printf("%d ", n / i);
    }
  }
}

/* Given n, print all the prime numbers smaller than or equal to n
 * Algorithm: SieveEratothenes
 * Make a boolean array of size (n + 1)
 * Loop through all, check if prime, print it &
 * mark all next composites as false
 */
void printPrimeFactorsSieveEratothenes(int n) {
  printf("\nSieve Eratothenes algorithm to print prime factors for %d = ", n);
  bool *arr = (bool *)malloc(n * sizeof(bool));

  if (arr == NULL) {
    printf("Memory allocation failed.\n");
    return;
  }

  for (int i = 2; i <= n; ++i) {
    if (isPrime(i)) {
      printf("%d ", i);
      for (int j = i * i; j <= n; j = j + i) {
        arr[j] = false;
      }
    }
  }
  free(arr);

  return;
}

// Computer kth Power for a given number n
int computePowerRecursive(int x, int n) {
  if (n == 0 || n == 1) // Base Case
    return x;

  if (n % 2 == 0) { // n is even
    return computePowerRecursive(x, n / 2) * computePowerRecursive(x, n / 2);
  } else { // n is odd
    return computePowerRecursive(x, n - 1) * x;
  }
}

int computePowerIterative(int x, int n) {
  int res = 1;
  while (n > 0) {
    if (n & 1) { // Check if last bit is 1
      res = res * x;
    }
    x = x * x;
    n = n >> 1; // Right shift to divide by 2
  }
  return res;
}

void selfPacedDsa() {
  // Initializations
  int n = 13, m = 7, k = 2;

  // Init statement
  printf("Self Paced DSA!\n\n");

  // Sum of n natural numbers
  sumNaturalNumbs(n);

  // Count Digits
  printf("\nNumber of digits = %d",
         countDigits(n)); // O(n) solution

  // Check if palindrome. O(n) solution
  (checkPalindrome(n)) ? printf("\nPalindrome!") : printf("\nNot a Palindrome");

  // Factorial of a number
  printf("\nFactorial of %d is %d", n, calculateFact(n));

  // Trailing Zeros
  printf("\nNumber of trailing zeros = %d", countTrailingZeros(n));

  // GCD
  printf("\nGCD = %d", getGCD_euclidean_advance(m, n));

  // LCM
  printf("\nLCM = %d", getLCM(m, n));

  // Prime number check
  ((isPrime(n)) ? printf("\nPrime number") : printf("\nNot a prime number"));

  // Print prime factors
  printPrimeFactors(n);

  // Print all divisors of a number
  printDivisorsInOrder(n);

  // Print prime factors using Sieve Eratothenes algorithm
  printPrimeFactorsSieveEratothenes(n);

  // Compute Power
  printf("\n(Recursive)Kth(%d) power of %d = %d", k, n,
         computePowerRecursive(n, k));
  printf("\n(Iterative)Kth(%d) power of %d = %d", k, n,
         computePowerIterative(n, k));
}

int main() {
  init(); // Constructor like call
  selfPacedDsa();
  end(); // Destructor like call

  return 0;
}