// Standard libraries
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b)) ? (a) : (b)
#define MAX_OF_THREE(a, b, c) (MAX(MAX((a), (b)), (c)))
#define ROWS1 4

void init() { // This will be like a constructor call
  printf("\n*************** Out ***************\n\n");
}

void end() { // This will be like a destructor call
  printf("\n\n***********************************\n\n");
}

/* Swap two elements */
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printMatrix(char *str, int **arr, int rows, int cols) {
  printf("%s", str);
  for (int i = 0; i < rows; ++i) {   // Rows
    for (int j = 0; j < cols; ++j) { // Cols
      arr[i][j] = i + j;
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

void printMatrixOnly(char *str, int **arr, int rows, int cols) {
  printf("%s", str);
  for (int i = 0; i < rows; ++i) {   // Rows
    for (int j = 0; j < cols; ++j) { // Cols
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

/* M-row N-column matrix */
int **createMatrix(int rows, int cols) {
  int **temp;
  temp = malloc(rows * sizeof(int *)); // Allocating memory for rows
  for (int i = 0; i < rows; ++i) {     // Allocating memory for cols
    temp[i] = malloc(cols * sizeof(int));
  }
  return temp;
}

/* Array of pointers */
int **arrayOfPointers(int rows, int cols) {
  static int *arr99[ROWS1]; // As C/C++ always have a row major array
  for (int i = 0; i < rows; ++i) {
    arr99[i] = malloc(cols * sizeof(int));
    if (arr99[i] == NULL) {
      fprintf(stderr, "Memory allocation failed\n");
      exit(EXIT_FAILURE);
    }
  }
  printMatrix("Matrix using array of pointers = \n", arr99, 4, 4);

  return arr99;
}

// Snake Pattern
void printMatrixSnakePattern(int **brr, int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < r; j++) {
      if (i % 2 == 0) { // Even rows
        printf("%d ", brr[i][j]);
      } else { // Odd rows
        printf("%d ", brr[i][c - j - 1]);
      }
    }
    printf("\n");
  }
}

// Boundary traversal
void boundaryTraversal(int **brr, int rows, int cols) {
  // First row
  for (int j = 0; j < cols; ++j) {
    printf("%d ", brr[0][j]);
  }
  // Last col
  for (int i = 0; i < rows; ++i) {
    printf("%d ", brr[i][cols - 1]);
  }
  // Last row in reverse
  for (int j = (cols - 1); j >= 0; --j) {
    printf("%d ", brr[(rows - 1)][j]);
  }

  // First col in reverse
  for (int i = (rows - 1); i >= 0; --i) {
    printf("%d ", brr[i][0]);
  }
}

// Transpose of a matrix
void transpose(int **brr, int rows, int cols) {
  for (int i = 0; i < rows; ++i) {
    for (int j = i + 1; j < cols; ++j) {
      swap(&(brr[i][j]), &(brr[j][i]));
    }
  }
}

// Counter clockwise rotation of a matrix
void rotateCounterClockwise(int **brr, int rows, int cols) {
  transpose(brr, rows, cols);
  for (int i = 0; i < rows / 2; ++i) {
    for (int j = 0; j < cols; ++j) {
      swap(&brr[i][j], &brr[rows - i - 1][j]);
    }
  }
}

// Spiral Traversal of a matrix
void spiralTraversal(int **brr, int rows, int cols) {
  int top = 0, bottom = rows - 1;
  int left = 0, right = cols - 1;
  printf("\n");

  while ((top <= bottom) || (left <= right)) {
    // 1
    for (int j = left; j <= right; ++j) {
      printf("%d ", brr[top][j]);
    }
    top++;

    // 2
    for (int i = top; i <= bottom; ++i) {
      printf("%d ", brr[i][right]);
    }
    right--;

    // 3
    if (top <= bottom) {
      for (int j = right; j >= left; --j) {
        printf("%d ", brr[bottom][j]);
      }
      bottom--;
    }

    // 4
    if (left <= right) {
      for (int i = bottom; i >= top; --i) {
        printf("%d ", brr[i][left]);
      }
      left++;
    }
  }
}

bool checkDiagonal(int **arr, int i, int j, int rows, int cols) {
  int res = arr[i][j];
  while ((++i < rows) && (++j < cols)) {
    if (arr[i][j] != res) {
      return false;
    }
  }
  return true;
}

bool isToeplitz(int **arr, int rows, int cols) {
  // For each element in the first row
  for (int j = 0; j < cols; ++j) {
    if (!checkDiagonal(arr, 0, j, rows, cols))
      return false;
  }

  // For each element in the first coloumn
  for (int i = 0; i < rows; ++i) {
    if (!checkDiagonal(arr, i, 0, rows, cols))
      return false;
  }
  return true;
}

void selfPacedDsa() {
  // Initializations
  int n = 4, m = 4;

  // int arr[][2] = {
  //     {10, 20},
  //     {30, 40},
  //     {50, 60}}; // Omitting first dimension as compiler can still
  //     understand it

  // Init statement
  printf("Matrix!\n");

  printf("\nDouble pointer");
  int **arr = createMatrix(3, 3);
  printMatrix("Matrix using double pointers = \n", arr, (int)3, (int)3);
  free(arr);

  printf("\nArray of pointers");
  int **arr1 = arrayOfPointers(4, 4);
  for (int i = 0; i < 4; ++i) {
    free(arr1[i]);
  }

  // Snake pattern
  int r = 4, c = 4;
  int **brr = createMatrix(4, 4);
  printMatrix("\nGiven Matrix:\n", brr, 4, 4);
  printf("\nMatrix in snake pattern:\n");
  printMatrixSnakePattern(brr, r, c);

  // Boundary Traversal
  printMatrix("\nGiven Matrix:\n", brr, 4, 4);
  printf("\nBoundary traversal = ");
  boundaryTraversal(brr, 4, 4);

  // Transpose of a matrix
  printMatrixOnly("\nGiven Matrix:\n", brr, 4, 4);
  transpose(brr, 4, 4);
  printMatrixOnly("\nTranspose:\n", brr, 4, 4);

  // Rotate by 90 degrees
  printMatrixOnly("\nGiven Matrix:\n", brr, 4, 4);
  rotateCounterClockwise(brr, 4, 4);
  printMatrixOnly("\n90 degree rotation:\n", brr, 4, 4);

  // Spiral traversal
  int **crr = createMatrix(4, 4);
  printMatrix("\nGiven Matrix:\n", crr, 4, 4);
  printf("\nSpiral Traversal: ");
  spiralTraversal(crr, 4, 4);

  // Toeplitz
  int mat[5][4] = {
      {6, 7, 8, 9}, {4, 6, 7, 8}, {1, 4, 6, 7}, {0, 1, 4, 6}, {2, 0, 1, 4}};
  int **drr = createMatrix(5, 4);
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 4; ++j) {
      drr[i][j] = mat[i][j];
    }
  }

  printMatrixOnly("\n\nGiven:\n", drr, 5, 4);
  if (isToeplitz((int **)drr, 5, 4))
    printf("\nIs toeplitz");
  else
    printf("\nIsn't toeplitz");
}

int main() {
  init(); // Constructor like call
  selfPacedDsa();
  end(); // Destructor like call

  return 0;
}