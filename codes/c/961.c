
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int repeatedNTimes(int* A, int ASize) {
  if (ASize == 0) {
    return 0;
  }
  if (ASize <= 2) {
    return A[0];
  }
  if (ASize == 4) {
    if (A[3] == A[0]) {
      return A[0];
    }
  }
  for (int i = 2; i < ASize; ++i) {
    if (A[i] == A[i-1] || A[i] == A[i-2]) {
      return A[i];
    }
  }
  return 0;
}

int main() {
  int A1[10] = {1, 2, 10, 10, 5, 10, 7, 10, 9, 10};
  int A2[10] = {1, 2, 10, 10, 5, 10, 7, 9, 10, 10};
  int A3[10] = {1, 10, 2, 10, 5, 10, 7, 10, 8, 10};
  int A4[4] = {9, 5, 6, 9};
  printf("%d\n", repeatedNTimes(A1, 10));
  printf("%d\n", repeatedNTimes(A2, 10));
  printf("%d\n", repeatedNTimes(A3, 10));
  printf("%d\n", repeatedNTimes(A4, 4));
  return 0;
}

