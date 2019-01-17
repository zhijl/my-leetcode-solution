
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
        emails[i][j] = '.';
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

  char* emails[] = {"j+ezsorqlmc@rfpycgjuf.com","j+k+ri+rigt.ad@rfpycgjuf.com","hfmeqzk.isx+i@fiidmdrsu.com","j+p+h+d+d+p+z.j.k.g@rfpycgjuf.com","zygekdy.l.w+s@snh.owpyu.com","j+m.l+ia+qdgv+w@rfpycgjuf.com","r+hwbjwefkp@wcjaki.n.com","zygekdy.l.w+d@snh.owpyu.com","bizdm+sz.f.a.k@il.cjjlp.com","hfmeqzk.isx+t@fiidmdrsu.com","hfmeqzk.isx+i@fiidmdrsu.com","bizdm+f+j+m.l.l@il.cjjlp.com","zygekdy.l.w+g@snh.owpyu.com","r+evgvxmksf@wcjaki.n.com","hfmeqzk.isx+h@fiidmdrsu.com","bizdm+lov+cy@il.cjjlp.com","hfmeqzk.isx+o@fiidmdrsu.com","bizdm+hs+qao@il.cjjlp.com","r+v+z+rcuznrj@wcjaki.n.com","j+r.kn+h.w.a.h+bh@rfpycgjuf.com","hfmeqzk.isx+t@fiidmdrsu.com","hfmeqzk.isx+a@fiidmdrsu.com","zygekdy.l.w+o@snh.owpyu.com","zygekdy.l.w+i@snh.owpyu.com","r+vy.u.y+f.er+aw@wcjaki.n.com","zygekdy.l.w+c@snh.owpyu.com","bizdm+wztzg@il.cjjlp.com","j+h.fwbsr+chp@rfpycgjuf.com","zygekdy.l.w+s@snh.owpyu.com","zygekdy.l.w+d@snh.owpyu.com","bizdm+qq.o.q+p@il.cjjlp.com","zygekdy.l.w+o@snh.owpyu.com","j+c+zqbq+h.dyt@rfpycgjuf.com","r+hl.b.i+fz.hz.t@wcjaki.n.com","r+cbabpf.k+w+e@wcjaki.n.com"};
  int ret =  numUniqueEmails(emails, 35);
  printf("%d\n", ret);

  return 0;
}

