#include <bits/stdc++.h>

using namespace std;

#define NMAX 64
#define MMAX 64

int G[MMAX][NMAX][NMAX];
int PD[MMAX][MMAX][NMAX][NMAX];
int n, m, r;

int pd(int fc, int k, int s, int t) {
  if (PD[fc][k][s][t] != -1) {
    return PD[fc][k][s][t];
  }

  int out = G[fc][s][t];

  if (k != 0) {
    for (int i = 0; i < m; i++) {
      for (int city = 0; city < n; city++) {
        out = min(out, G[fc][s][city] + pd(i, k-1, city, t));
      }
    }
  }

  return PD[fc][k][s][t] = out;
}

int main() {
  memset(PD, -1, sizeof(PD));
  scanf("%d %d %d", &n, &m, &r);
  for (int c = 0; c < m; c++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", &G[c][i][j]);
      }
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          G[c][i][j] = min(G[c][i][j], G[c][i][k]+G[c][k][j]);
        }
      }
    }
  }
  for (int i = 0; i < r; i++) {
    int s, t, k;
    scanf("%d %d %d", &s, &t, &k);
    s--; t--;
    k = min(k, n);
    int mi = 1e9;
    for (int j = 0; j < m; j++) {
      mi = min(mi, pd(j, k, s, t));
    }
    printf("%d\n", mi);
  }
  return 0;
}
