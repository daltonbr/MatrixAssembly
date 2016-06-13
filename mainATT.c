/*
https://github.com/daltonbr/MatrixAssembly

Authors:
Bruno Vedovetto @bleandro
Dalton Lima @daltonbr
Lucas Pinheiro @lucaspin
Wesley Otto @ottozinho

Description:
Consider three matrices of integers A, B, C and L x L size, defined in C
language (these matrices could be randomly generated). Implement three
equivalent functions (all functions must run in C language application):
The matrices must be static instantiates in C, at compiling-time.
These matrix must be ramdonly POPULATED, not randonly sized. In relation to L,
its good that the size could vary in fixed intervals (5x5, 10x10, 50x50,
 100x100, etc).
Group 1: (a * 2b) - returning the greater value in the main diagonal.

* This version uses Inline function using AT&T Assembly

$ as --32 -o greaterInDiagonalATT.o greaterInDiagonal.s
$ gcc -m32 -o mainATT.out mainATT.c greaterInDiagonalATT.o

*/

#include <stdio.h>
#include <stdlib.h> //malloc
#include <time.h>  // srand

#define L 3

  void printMatrix(int matrix[L][L]);
  void printDiagonal(int matrix[L][L]);
  void randomPopulateMatrix(int matrix[L][L]);
  int greaterValueInDiagonal(int matrix[L][L]);
  void scalarTimesMatrix (int _scalar, int matrix[L][L], int outputMatrix[L][L]);
  void matrixTimesMatrix (int firstMatrix[L][L], int secondMatrix[L][L], int outputMatrix[L][L]);

int main(void) {

  int a[L][L];
  int b[L][L];
  int outputMatrix[L][L];
  int bTimes2[L][L];

  int i, j, r;
  srand(time(NULL));

  printf("--== Matrix Operations in Assembly AT&T! ==--\n");
  printf("* All matrices bellow has a fixed [%dx%d] size\n",L, L);
  printf("* They are randomly populate with integers between 0 and 99\n");
  printf("* We calculate (a*2b)\n");
  printf("* We return the greater element from the main diagonal\n");

  printf("\nPrinting 'a' matrix\n");
  randomPopulateMatrix(a);
  printMatrix(a);

  int greaterAssembly = 0;
  extern int greaterInDiagonal_s (int, int *);
  greaterAssembly = greaterInDiagonal_s(L, *a);
  printf("[AT&T]Greater Element in 'a' matrix's diagonal: %d\n", greaterAssembly);

  randomPopulateMatrix(b);
  printf("\nPrinting 'b' matrix: \n");
  printMatrix(b);

  /* (2*b) */
  extern int scalarTimesMatrix_s (int, int, int *, int *);
  scalarTimesMatrix_s(L, 2, *b, *bTimes2);
  printf("\nPrinting 2 * 'b' matrix: \n");
  printMatrix(bTimes2);

/*
  // [WIP] matrixTimesMatrix_s
  extern int matrixTimesMatrix_s (int, int *, int *, int *);
  int test;
  test = matrixTimesMatrix_s(L, *a, *bTimes2, *outputMatrix);
  printf("\n(a * 2b) = %d\n", test);
  printMatrix(outputMatrix);

*/
}

void printMatrix(int matrix[L][L]) {
  int i, j, tempElement;
  for (i = 0; i < L ; i++) {
    for (j = 0; j < L; j++) {
      tempElement = matrix[i][j];
      printf(" [%d%d]: (%d) |", i, j, tempElement);
    }
    printf("\n");
  }
}

void printDiagonal(int matrix[L][L]) {
  int i, tempElement;
    for (i = 0; i < L; i++) {
      tempElement = matrix[i][i];
      printf(" [%d%d]: (%d) |", i, i, tempElement);
  }
}

void randomPopulateMatrix(int matrix[L][L]) {
  int i, j, tempElement;
  for (i = 0; i < L ; i++) {
    for (j = 0; j < L; j++) {
      matrix[i][j] = rand() % 100;    //returns a pseudo-random integer between 0 and 99
    }
  }
}

int greaterValueInDiagonal(int matrix[L][L]) {
  int i = 0, greaterElement;
    greaterElement = matrix[i][i];
    for (i = 1; i < L; i++) {
      if (greaterElement < matrix[i][i]) {
        greaterElement = matrix[i][i];
      }
    }
  return greaterElement;
}

/* void or return an outputMatrix */
void scalarTimesMatrix (int _scalar, int matrix[L][L], int outputMatrix[L][L]) {
  int i, j;
  for (i = 0; i < L ; i++) {
    for (j = 0; j < L; j++) {
      outputMatrix[i][j] = _scalar * matrix[i][j];
    }
  }
}

void matrixTimesMatrix (int firstMatrix[L][L], int secondMatrix[L][L], int outputMatrix[L][L]) {
  int i, j, k, accumulator;
  for (i = 0; i < L ; i++) {
    for (j = 0; j < L; j++) {
      accumulator = 0;
      for (k = 0; k < L ; k++) {
        accumulator += firstMatrix[i][k] * secondMatrix[k][j];
      }
      outputMatrix[i][j] = accumulator;
    }
  }
}
