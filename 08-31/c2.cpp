#include <bits/stdc++.h>

using namespace std;

#define NMAX 4003

char s[NMAX];
int n;

int PD[NMAX][NMAX];
int M[NMAX][NMAX];

inline int is_pal(char *s, int n) {
  for (int i = 0; 2*i < n; i++) {
    if (s[i] != s[n-1-i]) {
      return 0;
    }
  }
  return 1;
}

int f(int b, int e) {
  if (PD[b][e] != -1) {
    return PD[b][e];
  }
  if (is_pal(s+b, e-b)) {
    PD[b][e] = 1;
    M[b][e] = e;
  } else {
    PD[b][e] = e-b;
    M[b][e] = b+1;
    for (int m = b+1; m < e; m++) {
      int x = f(b, m);
      int y = f(m, e);
      if (x+y < PD[b][e]) {
        PD[b][e] = x+y;
        M[b][e] = m;
      }
    }
  }
  return PD[b][e];
}

void ps(int b, int e) {
  if (M[b][e] == e) {
    for (int i = b; i < e; i++) {
      putc(s[i], stdout);
    }
    if (e != n) {
      putc(' ', stdout);
    }
  } else {
    ps(b, M[b][e]);
    ps(M[b][e], e);
  }
}

int main() {
  scanf("%s", s);
  n = strlen(s);

  memset(PD, -1, sizeof(PD));
  int output = f(0, n);

  printf("%d\n", output);
  ps(0, n);
  printf("\n");
  return 0;
}
