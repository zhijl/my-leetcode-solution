
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* sortArrayByParity(int* A, int ASize, int* returnSize) {
  int* out_arr = NULL;
  out_arr = (int*)malloc(ASize * sizeof(int));
  int m = 0;
  int n = ASize-1;
  int i = 0;
  for (; i < ASize; ++i) {
    if (A[i] % 2 == 0) {
      out_arr[m] = A[i];
      ++m;
    } else {
      out_arr[n] = A[i];
      --n;
    }
  }
  *returnSize = ASize;
  return out_arr;
}

int main() {
  int A[] = {1, 2, 3, 4, 5};
  int *out_arr = NULL;
  int returnSize;
  out_arr = sortArrayByParity(A, 5, &returnSize);
  for (int i = 0; i < 5; ++i) {
    printf("%d ", out_arr[i]);
  }
  printf("\n");
  return 0;
}

