/*
https://github.com/daltonbr/MatrixAssembly

Authors:
Dalton Lima @daltonbr
Lucas Pinheiro @lucaspin

Description:
Consider three matrices of integers A, B, C and L x L size, defined in C
language (these matrices could be randomly generated). Implement three
equivalent functions (all functions must run in C language application):
*/
#include <stdio.h>
#include <stdlib.h> //malloc
#define L 3

void printMatrix(int *matrix);
void printDiagonal(int *matrix);
int getElementByIndex(int i, int j, int *matrix);
void setElementsByIndex(int value, int i, int j, int *matrix);

int main() {
  printf("Matrix Operations in Assembly!\n");

  int* a = malloc(L*L*sizeof(int));

  /* populating matrix with values
    00 01 02
    03 04 05
    06 07 08
  */
  int i, j;
  for (i = 0; i < L*L; i++) {
        *(a+i) = i;;
  }

  /* getting an element by its index */
  int element = getElementByIndex(2, 2, a);
  printf("getElementByIndex: %d\n", element);

  /* setting an element by its index */
  setElementsByIndex(99, 2, 2, a);
  element = getElementByIndex(2, 2, a);
  printf("getElementByIndex: %d\n", element);

  printf("Printing a Matrix %dx%d\n", L, L);
  printMatrix(a);

  printf("Printing Diagonal: \n");
  printDiagonal(a);
  return 0;
}

int getElementByIndex(int i, int j, int *matrix) {
  if (((i+1) * (j+1)) > (L*L)) {
      fprintf(stderr, "Index Out of Bounds Error!\n");
      exit(-1);  //failure
  }
  int output = *(matrix+(L*i + j));
  return output;
}

void setElementsByIndex(int value, int i, int j, int *matrix) {
  if (((i+1) * (j+1)) > (L*L)) {
      fprintf(stderr, "Index Out of Bounds Error!\n");
      exit(-1);  //failure
  }
  *(matrix+(L*i + j)) = value;
}

void printMatrix(int *matrix) {
  int i, j, tempElement;
  for (i = 0; i < L ; i++) {
    for (j = 0; j < L; j++) {
      tempElement = getElementByIndex(i, j, matrix);
      printf(" [%d%d]: (%d) |", i, j, tempElement);
    }
    printf("\n");
  }
}

void printDiagonal(int *matrix) {
  int i, tempElement;
    for (i = 0; i < L; i++) {
      tempElement = getElementByIndex(i, i, matrix);
      printf(" [%d%d]: (%d) |", i, i, tempElement);
  }
}
