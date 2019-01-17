
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numUniqueEmails(char** emails_input, int emailsSize) {
  // copy input data
  char** emails;
  emails = (char**)malloc(emailsSize * sizeof(char*));
  
  for (int i = 0; i < emailsSize; ++i) {
    int email_length = strlen(emails_input[i]);
    emails[i] = (char*)malloc(email_length * sizeof(char));
    memcpy(emails[i], emails_input[i], email_length * sizeof(char));
  }

  for (int i = 0; i < emailsSize; ++i) {
    int email_length = strlen(emails[i]);
    int j = 0;
    int plus_flag = 0;
    for (; j < email_length; ++j) {
      if (emails[i][j] == '+') {
        plus_flag = 1;
      }
      if (emails[i][j] == '@') {
        break;
      }
      if (1 == plus_flag) {
        emails[i][j] == '.';
      }
    }
    for (; j < email_length; ++j) {
      if (emails[i][j] == '.') {
        emails[i][j] = '+';
      }
    }
  }

  int* checked = NULL;
  checked = malloc(emailsSize * sizeof(int)) ;
  memset(checked, 0, emailsSize * sizeof(int));

  int ret = 0;
  for (int i1 = 0; i1 < emailsSize; ++i1) {
    if (checked[i1] == 0) {
      ++ret;
      checked[i1] = 1;
      for (int i2 = i1+1; i2 < emailsSize; ++i2) {
        int email_length1 = strlen(emails[i1]);
        int email_length2 = strlen(emails[i2]);
        int j1 = 0;
        int j2 = 0;
        int equal = 1;
        while (j1 < email_length1 && j2 < email_length2) {
          while (emails[i1][j1] == '.' && j1 < email_length1 - 1) {
            ++j1;
          }
          while (emails[i2][j2] == '.' && j2 < email_length2 - 1) {
            ++j2;
          }
          if (emails[i1][j1] != emails[i2][j2]) {
            equal = 0;
            break;
          }
          ++j1;
          ++j2;
        }
        if (equal == 1) {
          checked[i2] = 1;
        }
      }
    } 
  }

  // free memory
  free(checked);
  for (int i = 0; i < emailsSize; ++i) {
    free(emails[i]);
  }
  free(emails);
  return ret;
}

int main(int argc, char** argv) {

  char* emails[2] = {"........." ,"."};
  int ret =  numUniqueEmails(emails, 2);
  printf("%d\n", ret);

  return 0;
}

