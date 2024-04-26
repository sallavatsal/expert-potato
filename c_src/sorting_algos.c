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

/* Swap two elements */
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

/* Bubble sort
 * Swap adjacent and bubble up
 * In - Place & Stable algorithm
 */
void bubbleSort(int *arr, size_t n) {
  for (int i = 0; i < (n - 1); ++i) { // First to second last
    bool swapped = false;
    for (int j = 0; j < (n - 1 - i); ++j) { // Second to last element
      if (arr[j] >
          arr[j + 1]) { // Left element greater than right element, swap!
        swap(&arr[j], &arr[j + 1]);
        swapped = true;
      }
    }
    if (swapped == false) // No elements swapped in this iteration
      break;
  }
}

/*  Selection Sort
 * Find out the minimum element put it in first position,
 * find second minimum element to second and so on
 * In - Place(Does not use aux space) & Unstable algorithm
 */
void selectionSort(int *arr, size_t n) {
  for (int i = 0; i < (n - 1); ++i) {
    int min_index = i;
    for (int j = i + 1; j < n; ++j) {
      if (arr[min_index] > arr[j]) {
        min_index = j;
      }
    }
    swap(&arr[min_index], &arr[i]);
  }
}

/* Insertion sort
 * Inject elements which into left assumed sorted portion
 * In - Place & Stable algorithm. There are ways to make it stable
 * Left side is considered sorted. Start with 1 element sorted element
 * and keep injecting one element from the unsorted in the right location
 */
void insertionSort(int *arr, size_t n) {

  for (int i = 1; i < n; ++i) { // Unsorted portion of the array
    int key = arr[i];           // Element to compare
    int j = (i - 1);            // Sorted portion
    while ((j >= 0) && (arr[j] > key)) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

/* Merge two sorted arrays */
void merge_sorted(int *a1, size_t n1, int *a2, size_t n2) {
  int i = 0, j = 0;
  printf("\n(a1 + a2) = ");
  while ((i < n1) && (j < n2)) {
    if (a1[i] <= a2[j]) {
      printf("%d ", a1[i]);
      i++;
    } else {
      printf("%d ", a2[j]);
      j++;
    }
  }
  while (i < n1) {
    printf("%d ", a1[i]);
    i++;
  }
  while (j < n2) {
    printf("%d ", a2[j]);
    j++;
  }
}
/* Merge function of merge sort */
void merge(int *arr, int low, int mid, int high) {
  int n1 = mid - low + 1;
  int n2 = high - mid;

  int *left = malloc(n1 * sizeof(int));
  int *right = malloc(n2 * sizeof(int));

  // Filling the left array
  for (int i = low; i < (mid + 1); ++i) {
    left[i - low] = arr[i];
  }
  // printArray("\nLeft = ", left, n1);

  // Filling the right array
  for (int j = (mid + 1); j < (high + 1); ++j) {
    right[j - (mid + 1)] = arr[j];
  }
  // printArray("\nRight = ", right, n2);

  int i = 0;
  int j = 0;
  int k = low;

  while ((i < n1) && (j < n2)) {
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      ++i;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = left[i];
    ++i;
    ++k;
  }
  while (j < n2) {
    arr[k] = right[j];
    ++j;
    ++k;
  }
}

/* Merge sort
 * Divide and Conquer Algorithm
 * Sort: First divides input array or list in  two parts and then
 * recursively sorts these two parts. After sorting, merge 'em! Stable but
 * uses extra space! For linked lists, works in O(1) For arrays, Quick sort
 * works better
 */
void mergeSort(int *arr, int l, int r) {
  if (r > l) {               // At least two elements
    int m = l + (r - l) / 2; // Avoid overflow
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

/* Parition function - Naive */
void naivePartition(int *arr, int l, int h, int p) {
  int *temp = malloc((h - l + 1) * sizeof(int));
  int k = 0;

  // Elements less than or equal to arr[p]
  for (int i = l; i <= h; ++i) {
    if (arr[i] <= arr[p]) {
      temp[k] = arr[i];
      k++;
    }
  }
  // Elements greater than arr[p]
  for (int i = l; i <= h; ++i) {
    if (arr[i] > arr[p]) {
      temp[k] = arr[i];
      ++k;
    }
  }
  // Getting back elements from temp -> arr
  for (int i = l; i <= h; ++i) {
    arr[i] = temp[i - l];
  }
  free(temp);
}

// Lomuto partition
void hoaresPartition(int *arr, int l, int h) {
  int pivot = arr[l];
  int i = l - 1;
  int j = h + 1;
  while (true) {
    do {
      i++;
    } while (arr[i] < pivot);
    do {
      j--;
    } while (arr[j] > pivot);

    if (i >= j)
      break;

    swap(&arr[i], &arr[j]);
  }
}

void segregateNegativePositive(int *arr, int l, int h) {
  int j = l - 1; // Set of elements shorter than pivot
  for (int i = l; i <= h; ++i) {
    if (arr[i] < 0) {
      ++j;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[++j], &arr[h]);
}

void segregateThreeWay(int *arr, int l, int h) {}

void selfPacedDsa() {
  // Initializations
  int arr[] = {2, 10, 8, 7};
  size_t size = sizeof(arr) / sizeof(arr[0]);

  // Init statement
  printf("Sorting Algorithms!\n");

  // Bubble sort
  printf("\n\nBefore Bubble sort");
  printArray("\nArray: ", arr, size);
  bubbleSort(arr, size);
  printf("\nAfter Bubble sort");
  printArray("\nArray: ", arr, size);

  // Selection sort
  int arr1[] = {10, 5, 8, 20, 2, 18};
  size_t size1 = sizeof(arr1) / sizeof(arr1[0]);

  printf("\n\nBefore Selection sort");
  printArray("\nArray: ", arr1, size1);
  selectionSort(arr1, size1);
  printf("\nAfter Selection sort");
  printArray("\nArray: ", arr1, size1);

  // Insertion sort
  int arr2[] = {10, 5, 8, 20, 2, 18};
  size_t size2 = sizeof(arr2) / sizeof(arr2[0]);

  printf("\n\nBefore Insertion sort");
  printArray("\nArray: ", arr2, size2);
  insertionSort(arr2, size2);
  printf("\nAfter Insertion sort");
  printArray("\nArray: ", arr2, size2);

  // Merge two sorted arrays
  int a1[] = {10, 15, 20};
  int a2[] = {5, 6, 6, 15};
  int size_a1 = (sizeof(a1) / sizeof(a1[0]));
  int size_a2 = (sizeof(a2) / sizeof(a2[0]));
  printArray("\n\nArray a1: ", a1, size_a1);
  printArray("\nArray a2: ", a2, size_a2);
  merge_sorted(a1, size_a1, a2, size_a2);

  // Merge function of merge sort
  int arr3[] = {10, 15, 20, 11, 30};
  size_t size3 = sizeof(arr3) / sizeof(arr3[0]);
  int mid = 2;
  printf("\n\nBefore Merge function of merge sort");
  printArray("\nArray: ", arr3, size3);
  merge(arr3, 0, mid, size3 - 1);
  printf("\nAfter Merge function of merge sort");
  printArray("\nArray: ", arr3, size3);

  // Merge sort
  int arr4[] = {10, 5, 30, 15, 7};
  size_t size4 = sizeof(arr4) / sizeof(arr4[0]);
  printf("\n\nBefore Merge sort");
  printArray("\nArray: ", arr4, size4);
  mergeSort(arr4, 0, size4 - 1);
  printf("\nAfter Merge sort");
  printArray("\nArray: ", arr4, size4);

  // Naive Partition
  int arr5[] = {3, 8, 6, 12, 10, 7};
  int p = 5; // Parition index
  size_t size5 = sizeof(arr5) / sizeof(arr5[0]);
  printf("\n\nBefore naive parition");
  printArray("\nArray: ", arr5, size5);
  naivePartition(arr5, 0, size5 - 1, p);
  printf("\nAfter naive parition");
  printArray("\nArray: ", arr5, size5);

  // Hoare's Partition
  int arr6[] = {11, 8, 6, 12, 10, 7};
  size_t size6 = sizeof(arr6) / sizeof(arr6[0]);
  printf("\n\nBefore hoare's parition");
  printArray("\nArray: ", arr6, size6);
  hoaresPartition(arr6, 0, size6 - 1);
  printf("\nAfter hoare's parition");
  printArray("\nArray: ", arr6, size6);

  // Segregate positive and negative array elements
  int arr7[] = {15, -3, -2, 18};
  size_t size7 = sizeof(arr7) / sizeof(arr7[0]);
  printf("\n\nBefore segregration of even odd");
  printArray("\nArray: ", arr7, size7);
  segregateNegativePositive(arr7, 0, size7 - 1);
  printf("\nAfter segregration of even odd");
  printArray("\nArray: ", arr7, size7);
}

int main() {
  init(); // Constructor like call
  selfPacedDsa();
  end(); // Destructor like call

  return 0;
}