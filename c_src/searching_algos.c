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

void printArray(char *str, int *arr, size_t size) {
  printf("%s", str);
  for (int i = 0; i < size; ++i) {
    printf("%d ", arr[i]);
  }
}

/* Binary search - Iterative */
int bSearch_it(int *arr, size_t size, int x) {
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2; // Middle element
    if (arr[mid] == x) {
      return mid;
    } else if (arr[mid] > x) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}

/* Binary search - Recursive */
int bSearch_rec(int *arr, int lo, int hi, int x) {
  if (lo > hi) {
    return -1;
  }
  int mid = lo + (hi - lo) / 2;
  if (arr[mid] == x)
    return mid;
  else if (arr[mid] > x) {
    return bSearch_rec(arr, lo, mid - 1, x);
  } else {
    return bSearch_rec(arr, mid + 1, hi, x);
  }
}

/* Find the first occurence in a sorted array */
int firstOccurence(int *arr, size_t size, int x) {
  int lo = 0;
  int hi = size - 1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (arr[mid] < x) {
      lo = mid + 1;
    } else if (arr[mid] > x) {
      hi = mid - 1;
    } else {
      if ((arr[mid - 1] != arr[mid]) || (mid == 0)) {
        return mid;
      }
      hi = mid - 1;
    }
  }
  return -1;
}

/* Find the last occurence in a sorted array */
int lastOccurence(int *arr, int lo, int hi, size_t size, int x) {
  if (lo > hi) {
    return -1;
  }
  int mid = lo + (hi - lo) / 2; // Avoid overflow
  if (arr[mid] < x) {
    return lastOccurence(arr, mid + 1, hi, size, x);
  } else if (arr[mid] > x) {
    return lastOccurence(arr, lo, mid - 1, size, x);
  } else {
    if ((mid == (size - 1)) || (arr[mid + 1] != arr[mid])) {
      return mid;
    }
    return lastOccurence(arr, mid + 1, hi, size, x);
  }
}

// Square root of a number
int getSquareRoot(int x) {
  int lo = 0;
  int hi = x;
  int ans = -1;

  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    int sq = mid * mid;
    if (sq == x) {
      return mid;
    } else if (sq > x) {
      hi = mid - 1;
    } else {
      ans = lo;
      lo = mid + 1;
    }
  }
  return ans;
}

/* Search in an infinite size array */
/* Unbounded binary search */
bool searchInfinite(int *arr, int x) {
  int i = 1;
  while (i < x) {
    i = 2 * i;
  }
  if (i == x) { // Found it?
    return true;
  }
  if ((bSearch_rec(arr, (i / 2 + 1), i - 1, x)) != 0)
    return true;
  return false;
}

/* Peak element */
/* FACT: If left element is greater than or equal to mid, then there will always
 * be a peak element on the left side */

/* Median of two arrays */
/* a1<a2 if not, swap pointers */
/* log(size1)*/
int median(int *a1, size_t n1, int *a2, size_t n2) {
  // Init

  // Swap if a1 is not smaller than a2. It has to be smaller
  if (n1 > n2) {
    int *temp = a1;
    a1 = a2;
    a2 = temp;
  }
  int i1 = n1 / 2;            // Pointer for the first array
  int i2 = (n1 + n2 + 1) / 2; // Pointers for the second array

  while (1) {
    if ((a1[i1 - 1] < a1[i1]) && (a1[i2 - 1] < a2[i2])) {
      if ((n1 + n2) % 2 == 1) { // If total is odd
        if (a1[i1 - 1] > a2[i2 - 1]) {
          return a1[i1 - 1];
        }
        return a2[i2 - 1];
      } else {
        int temp1 = ((a1[i1 - 1] > a2[i2 - 1]) ? a1[i1 - 1] : a2[i2 - 1]);
        int temp2 = ((a1[i1] > a2[i2]) ? a2[i2] : a1[i1]);
        return (temp1 + temp2) / 2;
      }
    }
    if (a2[i2 - 1] > a1[i1]) {
      i1++;
    } else {
      i1--;
    }
    return -1; // Code does not work
  }
  return 1;
}

/* Repeating element
 * Elements range from 0 to max all are present, where max is
 * Solution 1 = 2 loops
 * Solution 2 = Hashing
 * Solution 3 = Visited array
 * Solution 4 = Floyd's algorithm (Same as Linked List, but for arrays)
 */
int repeatingElements(int *arr, size_t size) {
  int slow = arr[0] + 1;
  int fast = arr[0] + 1;
  do {
    slow = arr[slow] + 1;          // One link move at a time
    fast = arr[arr[fast] + 1] + 1; // Double link move at a time
  } while (slow != fast);

  // Re-initialize slow
  slow = arr[0] + 1;
  // They will meet at the first item of your cycle. The repeating element
  while (slow != fast) {
    slow = arr[slow] + 1; // One link move at a time
    fast = arr[fast] + 1; // One link move at a time
  }
  return slow - 1;
}

void selfPacedDsa() {
  // Initializations
  int arr[] = {10, 20, 20, 20, 30, 40, 50, 60};
  size_t size = sizeof(arr) / sizeof(arr[0]);
  int x = 50;

  // Init statement
  printf("Searching Algorithms!\n");

  // Binary search - Iterative
  printArray("Array: ", arr, size);
  printf("\nBinary search Iterative = %d", bSearch_it(arr, size, x));
  printf("\nBinary search Recursive = %d", bSearch_rec(arr, 0, (size - 1), x));

  // First occurence
  printArray("\nArray: ", arr, size);
  printf("\nFirst occurence in a sorted array = %d",
         firstOccurence(arr, size, x));

  // Last occurence
  printf("\nLast occurence in a sorted array = %d",
         lastOccurence(arr, 0, (size - 1), size, x));

  // Square root
  printf("\nSquare root of %d = %d", x, getSquareRoot(x));

  // Search in an inifite sized array
  int arr_i[] = {1, 5, 10, 30, 50, 60, 90, 100, 120, 135, 165, 200};
  if (searchInfinite(arr_i, x)) {
    printf("\nFound element in infinite sized array!");
  } else {
    printf("\nNot found in infinite sized array!");
  }

  // Median of two sorted arrays
  int a1[] = {10, 20, 30, 40, 50};
  int a2[] = {5, 15, 25, 30, 35, 55, 65, 75, 85};
  int n1 = sizeof(a1) / sizeof(a1[0]);
  int n2 = sizeof(a2) / sizeof(a2[0]);
  printf("\nMedian of two arrays a1 and a2 = %d", median(a1, n1, a2, n2));

  // Repeating element
  // array = 0 -> 2 -> 1 -> 3 -> 5 -> 4 -> 6 -> 2
  // index = 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
  int arr1[] = {0, 2, 1, 3, 5, 4, 6, 2};
  size = sizeof(arr1) / sizeof(arr1[0]);
  printArray("\nArray: ", arr1, size);
  printf("\nRepearting element = %d", repeatingElements(arr1, size));
}

int main() {
  init(); // Constructor like call
  selfPacedDsa();
  end(); // Destructor like call

  return 0;
}