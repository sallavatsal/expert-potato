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

/* Factorial of a number using recursion
 * Recursion steps:
 *
 * 1. Try to think if you can come up with a solution where you can solve the
 * problem for (n-1) elements
 *
 * 2. Think of the Base case to stop recurssion at some point
 *
 * 3. See if you can write a tail recursive solution which modern compilers can
 * make use of and make it iterative and so, efficient
 *
 * factorial(n) = n*factorial(n-1)
 *
 * Base case: Input for which we cannot break our problem into smaller
 * sub-problems
 *
 */
int factorial(int n, int k) {
  // Base case for recursion
  if (n == 0) {
    return k;
  }
  return (factorial(n - 1, n * k));
}

/* Find nth Fibonacci number
 * Series: 0, 1, 1, 2, 3, 5, 8...
 */
int fibo(int n) {
  // Base case
  if (n <= 1) {
    return n;
  }
  return (fibo(n - 1) + fibo(n - 2));
}

/* Sum of n natural numbers */
int getSum(int n) {
  if (n == 0) {
    return 0;
  }
  return (n + getSum(n - 1));
}

/* Palindrome check using recursion */
bool checkPalindrome(char *str, int start, int end) {
  if (start >= end)
    return true;
  return ((str[start] == str[end]) && checkPalindrome(str, start + 1, end - 1));
}

/* Sum of digits
 * n>=0. If n = 9987
 * return (9 + 8 + 8 + 7);
 */
int sumOfDigits(int n) {
  if (n == 0) {
    return 0;
  }
  return (n % 10 + sumOfDigits(n / 10));
}

/* Rope cutting using recursion
 * Given: n is the rope sizes. a, b, and c are the scisors
 * See if you can make cuts of a, b, c or a combination of these
 * Return -1 if you cannot
 * When you draw a recursive tree, you can always tell what are the base cases
 * from leaf nodes
 */

int maxPieces(int n, int a, int b, int c) {
  if (n < 0)
    return -1;
  if (n == 0)
    return 0;

  int res = MAX_OF_THREE(maxPieces(n - a, a, b, c), maxPieces(n - b, a, b, c),
                         maxPieces(n - c, a, b, c));
  if (res == -1) // When all cuts came out to be -1
    return -1;
  return (res + 1);
}

/* Generate subsets of strings or subsequences of a string
 * I/P: s = "AB"
 * O/P: "", "A", "B", "AB"
 *
 * Assume: All characters of the string are distinct
 * Generate subsets of the strings in order
 * What is a subsequence? Obtained by removing 0 or more characters from the
 * given string and keeping the order of characters same
 *
 * For a string of length n, there are going to be 2^n subsets or subsequences
 *
 */
void genSubStrings(const char *s, char *curr, int index) {
  if (index == strlen(s)) { // Base case: Printing at level 3
                            // if (strlen(curr) > 3)
    printf("%s ", curr);
    curr[0] = '\0';
    return;
  }
  genSubStrings(s, curr, (index + 1)); // Don't add a character
  strcat(curr, &s[index]);
  genSubStrings(s, curr, (index + 1)); // Add a character
}

void selfPacedDsa() {
  // Initializations
  int n = 5, k = 1;

  // Init statement
  printf("Recursion!\n");

  // Print factorial of a number
  printf("\nFactorial of %d is %d", n, factorial(n, k));

  // Nth fibonacci number
  printf("\n%dth fibonacci number is %d", n, fibo(n));

  // Sum of natural numbers
  printf("\nSum of %d natural numbers is %d", n, getSum(n));

  // Check if given string is palindrome
  char *str = "abbcdcbba";
  int start = 0, end = strlen(str) - 1;
  checkPalindrome(str, start, end) ? printf("\nYes it's a Palindrome")
                                   : printf("\nNo it's not a palindrom");

  // Sum of natural numbers
  int num = 9987;
  printf("\nSum of digits in %d is %d", num, sumOfDigits(num));

  // Rope cutting using recurssion
  //   int ropeLen = 9, a = 2, b = 2, c = 3;
  int ropeLen = 23, a = 11, b = 12, c = 9;
  printf("\nMax rope pieces = %d", maxPieces(ropeLen, a, b, c));

  // Generate sub-strings
  const char *s = "ABC";
  char *curr = malloc(strlen(s) * sizeof(char));
  curr[0] = '\0';
  int index = 0;
  printf("\nSub sequences of string %s are as follows: ", s);
  genSubStrings(s, curr, index);
}

int main() {
  init(); // Constructor like call
  selfPacedDsa();
  end(); // Destructor like call

  return 0;
}