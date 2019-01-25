
#include <stdio.h>
#include <stdlib.h>

int** flipAndInvertImage(int** A, int ARowSize, int *AColSizes,
                         int** columnSizes, int* returnSize) {
  int** out_arr = NULL;
  out_arr = (int**)malloc(ARowSize * sizeof(int*));
  columnSizes = (int**)malloc(ARowSize * sizeof(int*));
  for (int i = 0; i < ARowSize; ++i) {
    out_arr[i] = (int*)malloc(*AColSizes * sizeof(int));
    columnSizes[i] = (int*)malloc(sizeof(int));
    columnSizes[i][0] = *AColSizes;
    for (int j = 0; j < *AColSizes; ++j) {
      out_arr[j][j] = !A[i][*AColSizes - j + 1];
    }
  }
  *returnSize = ARowSize;
  return out_arr;
}

int main() {
  int A[2][3] = {{0, 1, 0}, {0, 1, 1}};
   
  return 0;
}

