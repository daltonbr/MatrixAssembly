/*
https://github.com/daltonbr/MatrixAssembly

Authors:
Dalton Lima @daltonbr
Lucas Pinheiro @lucaspin

Description:
Consider three matrices of integers A, B, C and L x L size, defined in C
language (these matrices could be randomly generated). Implement three
equivalent functions (all functions must run in C language application):
The matrices must be static instantiates in C, at compiling-time.
These matrix must be ramdonly POPULATED, not randonly sized. In relation to L,
its good that the size could vary in fixed intervals (5x5, 10x10, 50x50,
 100x100, etc).
Group 1: (a * 2b) - returning the greater value in the main diagonal.
*/
#include <stdio.h>
#include <stdlib.h> //malloc
#include <time.h>  // srand

#define L 5

  void printMatrix(int matrix[L][L]);
  void printDiagonal(int matrix[L][L]);
  void randomPopulateMatrix(int matrix[L][L]);
  int greaterValueInDiagonal(int matrix[L][L]);

int main(void) {

  int a[L][L];
  int b[L][L];
  int c[L][L];

  int i, j, r;
  srand(time(NULL));

  printf("Matrix Operations in Assembly!\n");

  /* populating matrix with values not random
    00 01 02
    10 11 12
    20 21 22
  */
  for (i = 0; i < L; i++) {
    for (j = 0; j < L; j++) {
        a[i][j] = (i*10)+j;
    }
  }

  printf("\nPrinting Matrix a %dx%d\n", L, L);
  printMatrix(a);

  printf("\nPrinting Diagonal: \n");
  printDiagonal(a);

  randomPopulateMatrix(b);
  printf("Printing B Matrix: \n");
  printMatrix(b);
  int greaterInDiagonal = greaterValueInDiagonal(b);
  printf("Greater in Diagonal: %d\n", greaterInDiagonal);
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
