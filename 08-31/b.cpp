#include <bits/stdc++.h>

using namespace std;

#define NMAX 10100
#define PMAX 256
#define MMAX 1000

#define MOD 1000000009

int PD[NMAX][MMAX];
int P[MMAX];
int p = 0;
map < int, set<int> > S;

int f(int n, int l2) {
  if (PD[n][l2] != -1) {
    return PD[n][l2];
  }
  if (n == 2) {
    return PD[n][l2] = 1;
  }
  if (S.find(l2) == S.end()) {
    return PD[n][l2] = 0;
  }
  PD[n][l2] = 0;
  for (set<int>::iterator it = S[l2].begin(); it != S[l2].end(); it++) {
    PD[n][l2] += f(n-1, *it);
    if (PD[n][l2] >= MOD) {
      PD[n][l2] %= MOD;
    }
  }
  return PD[n][l2];
}

int main() {
  int M[MMAX];
  memset(M, 0, sizeof(M));
  for (int i = 2; i < MMAX; i++) {
    if (!M[i]) {
      for (int j = i*i; j < MMAX; j+= i) {
        M[j] = 1;
      }
      if (i > 100) {
        P[p++] = i;
        S[i/10].insert(i%100);
      }
    }
  }
  memset(PD, -1, sizeof(PD));
  int n;
  scanf("%d", &n);
  int o = 0;
  for (int i = 0; i < p; i++) {
    o += f(n-1, P[i] % 100);
    if (o >= MOD) {
      o %= MOD;
    }
  }
  printf("%d\n", o);
  return 0;
}
