#include <bits/stdc++.h>

using namespace std;

#define NMAX 128

char A[NMAX][NMAX];

int main() {
  char s[NMAX];
  int n = 0;
  memset(A, '0', sizeof(A));
  while (scanf("%s", s) && strcmp(s, "0") != 0) {
    strcpy(&A[n++][NMAX-1-strlen(s)], s);
  }
  if (n == 0) {
    printf("0\n");
    return 0;
  }
  string output = "";
  int overflow = 0;
  for (int d = NMAX-2; d >= -200; d--) {
    int val = overflow;
    if (d >= 0) {
      for (int i = 0; i < n; i++) {
        val+= A[i][d]-'0';
      }
    }
    char c = '0' + (val % 10);
    output = c + output;
    overflow = val / 10;
  }
  while (output[0] == '0') {
    output.erase(output.begin());
  }
  printf("%s\n", output.c_str());
  return 0;
}
