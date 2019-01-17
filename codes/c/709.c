
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* toLowerCase(char* str) {
  int length = strlen(str);
  if (length <= 0) {
    return "";
  }
  char* dst = (char *)malloc(length * sizeof(char) + 1);
  memcpy(dst, str, length * sizeof(char) + 1);
  printf("%s\n", dst);
  for (int i = 0; i < length; ++i) {
    if (dst[i] < 'Z') {
      dst[i] = dst[i] - 'A' + 'a';
    }
  }
  return dst;
}

int main(int argc, char** argv) {
  printf("%s\n", toLowerCase(argv[1]));
  return 0;
}

