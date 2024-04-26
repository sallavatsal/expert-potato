// Standard libraries
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b)) ? (a) : (b)
#define MAX_OF_THREE(a, b, c) (MAX(MAX((a), (b)), (c)))

// Global varaibles
typedef struct {
  int *arr;
  int size;
  int cap;
} dynamic_array_t;

void init() { // This will be like a constructor call
  printf("\n*************** Out ***************\n\n");
}

void end() { // This will be like a destructor call
  printf("\n\n***********************************\n\n");
}

void arrayInit(int *arr, size_t size) {
  for (int i = 0; i < size; ++i) {
    arr[i] = i + 33;
  }
}

/* Amortized time complexity = O(1) */
dynamic_array_t *dynamic_array_init(int capacity) {
  dynamic_array_t *temp;
  temp->size = 0;
  temp->cap = capacity;
  temp->arr = malloc(capacity * sizeof(int));

  return temp;
}

void append_dynamic_array(dynamic_array_t *temp, int x) {
  // Array size full
  if (temp->cap == temp->size) {
    printf("\nDynamic Double!");
    temp->cap *= 2;
    temp->arr = realloc(temp->arr, (temp->cap) * sizeof(int));
  }
  temp->arr[temp->size++] = x;
}

void freeDynamicArray(dynamic_array_t *temp) {
  temp->size = 0;
  temp->cap = 0;
  free(temp->arr);
}

void printArray(char *str, int *arr, size_t size) {
  printf("%s", str);
  for (int i = 0; i < size; ++i) {
    printf("%d ", arr[i]);
  }
}

// Search
int search(int *arr, size_t size, int x) {
  for (int i = 0; i < size; ++i) {
    if (arr[i] == x)
      return arr[i];
  }
  return -1;
}

// Insert
int insert(int *arr, size_t size, int x, int cap, int pos) {
  if (cap == size) { // Array size full
    return -1;
  }
  for (int i = size - 1; i > pos; --i) {
    arr[i + 1] = arr[i];
  }
  arr[pos] = x;
  return ++size;
}

// Delete an element in array
void delete(int *arr, size_t size, int x) {
  int i = 0;
  bool flag = false;
  for (; i < size - 1; ++i) {
    if (arr[i] == x) {
      flag = true;
      break;
    }
  }
  if (flag == true) {
    for (; i < size - 1; ++i) {
      arr[i] = arr[i + 1];
    }
    arr[i] = 0;
  }
}

// Largest element
int largest(int *arr, size_t size) {
  int idx = 0;
  for (int i = 1; i < size; ++i) {
    if (arr[i] > arr[idx])
      idx = i;
  }
  return idx;
}

// Second largest element
int secondLargest(int *arr, size_t size) {
  int largest = 0;
  int second = -1;
  for (int i = 1; i < size; ++i) {
    if (arr[i] > arr[largest]) {
      largest = i;
    }
    if (arr[i] != arr[largest]) {
      if (arr[i] > arr[second] || second == -1) {
        second = i;
      }
    }
    largest = i; // Next, update largest
  }
  return second;
}

// Check if it's sorted
bool checkSorted(int *arr, size_t size) {
  for (int i = 1; i < size; ++i) {
    if (arr[i] < arr[i - 1])
      return false;
  }
  return true;
}

// Swap two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Reverse an array
void reverse(int *arr, size_t size) {
  int lo = 0;
  int hi = size - 1;
  while (lo <= hi) {
    swap(&arr[lo], &arr[hi]);
    lo++;
    hi--;
  }
}

/* Remove duplicates
 * 1, 2, 3, 4, 4, 5.
 * Remove one 4 from above
 */
int removeDuplicates(int *arr, size_t size) {
  int idx = 1;
  for (int i = 1; i < size; ++i) {
    if (arr[idx - 1] != arr[i]) {
      arr[idx] = arr[i];
      idx++;
    }
  }
  return idx;
}

/* Left rotate an array by 1
 *
 */
void leftRotateArray1(int *arr, size_t size) {
  int element = arr[0];
  for (int i = 1; i < size; ++i) {
    arr[i - 1] = arr[i];
  }
  arr[size - 1] = element;
}

void reversal(int *arr, int low, int high) {
  while (low <= high) {
    swap(&arr[low], &arr[high]);
    low++;
    high--;
  }
}

/* Left rotate an array by d
 * Reversal algorithm
 */
void leftRotateArrayD(int *arr, size_t n, int d) {
  reversal(arr, 0, d - 1);
  reversal(arr, d, n - 1);
  reversal(arr, 0, n - 1);
}

/* Move zeros to the end
 * Keep count of non-zero elements
 */
int moveZerosToEnd(int *arr, size_t size) {
  int count = 0;
  for (int i = 0; i < size; ++i) {
    if (arr[i] != 0) {
      swap(&arr[count], &arr[i]);
      count++;
    }
  }
  return count;
}

/* Max difference. j>i arr[j]>arr[i] */
int maxDiff(int *arr, int size) {
  int minVal = arr[0];
  int maxDiff = arr[1] - arr[0];
  for (int j = 1; j < size; ++j) {
    // Calculate current difference
    int currDiff = (arr[j] - minVal);
    // Get the max difference
    maxDiff = MAX(maxDiff, currDiff);
    // Update min difference if need be
    if (arr[j] < minVal)
      minVal = arr[j];
  }
  return maxDiff;
}

// Print frequency
void printFreq(int *arr, int size) {
  int freq = 1;
  int curr = arr[0];
  printf("\nRes: ");
  for (int i = 1; i < size; ++i) {
    if (arr[i] != arr[i - 1]) {
      printf("%d %d, ", curr, freq);
      freq = 1;
      curr = arr[i];
    } else {
      freq++;
    }
  }
  printf("%d %d", curr, freq);
}

void selfPacedDsa() {
  // Initializations
  int n = 5, k = 1;

  // Init statement
  printf("Arrays!\n");

  int arr[8] = {1, 5, 3, 6, 8, 4};
  size_t size = 6;
  int x = 56, pos = 2, cap = 8;

  // Search in an unsorted array
  printf("Element exists in array at location: %d", search(arr, size, x));

  // Insert in an unsorted array
  printArray("\nBefore insert: ", arr, size);
  printf("\nElement inserted in array at location: %d", pos);
  int new_size = insert(arr, size, x, cap, pos);
  printArray("\nAfter insert: ", arr, new_size);

  // Dynamic sized array operations
  dynamic_array_t *d = dynamic_array_init(3);
  append_dynamic_array(d, 2);
  append_dynamic_array(d, 4);
  append_dynamic_array(d, 8);
  append_dynamic_array(d, 88);
  printArray("\nDynamic array: ", d->arr, d->size);
  freeDynamicArray(d);

  // Delete an element in an array
  size = 6;
  x = 36;
  arrayInit(arr, size);
  printArray("\nBefore delete: ", arr, size);
  delete (arr, size, x);
  printArray("\nAfter delete: ", arr, size);

  // Largest element
  int arr1[] = {10, 10, 10, 10, 10, 10, 10, 10, 10};
  size = sizeof(arr1) / sizeof(arr1[0]);
  printArray("\nArray 1: ", arr1, size);
  printf("\nLargest element in array: %d", arr1[largest(arr1, size)]);

  // Second largest element
  int element = secondLargest(arr1, size);
  if (element == -1)
    printf("\nNo second largest");
  else
    printf("\nSecond Largest element in array: %d", arr1[element]);

  // Check if sorted
  int arr2[] = {1, 2, 3, 4, 5, 5, 5};
  size = sizeof(arr2) / sizeof(arr2[0]);
  printArray("\nArray = ", arr2, size);
  if (checkSorted(arr2, size))
    printf("\nSorted");
  else
    printf("\nUnsorted");

  // Remove duplicates above array
  size = removeDuplicates(arr2, size);
  printArray("\nDuplicates removed = ", arr2, size);

  // Reverse above array
  reverse(arr2, size);
  printArray("\nReverse = ", arr2, size);

  // Move zeros to end
  int arr3[] = {8, 5, 0, 10, 0, 20};
  size = (sizeof(arr3) / sizeof(arr3[0]));
  printArray("\nZeros to end = ", arr3, size);
  moveZerosToEnd(arr3, size);
  printArray("\nZeros to end = ", arr3, size);

  // Left rotate an array by 1
  leftRotateArray1(arr3, size);
  printArray("\nLeft rotate by 1 = ", arr3, size);

  // Left rotate an array by d
  int arr4[] = {1, 2, 3, 4, 5, 6};
  int _d = 3;
  printArray("\nBEFORE: Left rotate by d = ", arr4, size);
  leftRotateArrayD(arr4, size, _d);
  printArray("\nAFTER: Left rotate by d = ", arr4, size);

  // Max difference in array
  int arr5[] = {2, 3, 10, 6, 4, 8, 1};
  size = sizeof(arr5) / sizeof(arr5[0]);
  printArray("\nArray given = ", arr5, size);
  printf("\nMax difference for j>i such that (arr[j]>arr[i]): %d",
         maxDiff(arr5, size));

  // Print frequency
  int arr6[] = {40, 50, 50, 50, 60};
  size = (sizeof(arr6) / sizeof(arr6[0]));
  printArray("\nArray given for freq = ", arr6, size);
  printFreq(arr6, size);
}

int main() {
  init(); // Constructor like call
  selfPacedDsa();
  end(); // Destructor like call

  return 0;
}