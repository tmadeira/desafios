#include <bits/stdc++.h>

using namespace std;

#define NMAX 4003

char s[NMAX];
int n;
int PD[NMAX], M[NMAX];
char P[NMAX][NMAX];
int sol[NMAX];

int main() {
  scanf("%s", s);
  n = strlen(s);

  memset(P, 0, sizeof(P));
  
  for (int c = 0; c < n; c++) {
    P[c][c] = 1;

    int l = c-1;
    int r = c+1;
    while (l >= 0 && r < n && s[l] == s[r]) {
      P[l][r] = 1;
      l--;
      r++;
    }

    l = c;
    r = c+1;
    while (l >= 0 && r < n && s[l] == s[r]) {
      P[l][r] = 1;
      l--;
      r++;
    }
  }

  PD[0] = 0;
  for (int k = 1; k <= n; k++) {
    PD[k] = k;
    M[k] = k-1;
    for (int i = 0; i < k; i++) {
      if (P[i][k-1]) {
        if (PD[i]+1 < PD[k]) {
          PD[k] = PD[i]+1;
          M[k] = i;
        }
      }
    }
  }

  int output = PD[n], c = 0, a = n;
  printf("%d\n", output);
  for (int o = output-1; o >= 0; o--) {
    sol[o] = n-M[a]-c;
    c += n-M[a]-c;
    a = M[a];
  }

  char *p = s;
  for (int o = 0; o < output; o++) {
    if (o != 0) {
      putc(' ', stdout);
    }
    char tmp = p[sol[o]];
    p[sol[o]] = '\0';
    printf("%s", p);
    p[sol[o]] = tmp;
    p += sol[o];
  }
  printf("\n");
  return 0;
}
