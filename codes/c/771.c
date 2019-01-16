
#include <stdio.h>
#include <string.h>

int numJewelsinStones(char* J, char* S) {
  int j_len = strlen(J);
  int s_len = strlen(S);
  int ret = 0;
  for (int i = 0; i < s_len; i++) {
    for (int j = 0; j < j_len; j++) {
      if (S[i] == J[j]) {
        ++ret;
      }
    }
  }
  return ret;
}

int main(int argc, char** argv) {
  int ret = 0;
  ret = numJewelsinStones(argv[1], argv[2]);
  printf("%d\n", ret);
  return 0;
}

