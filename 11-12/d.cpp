#include <bits/stdc++.h>

using namespace std;

#define NMAX 64
#define MMAX 64

int G[MMAX][NMAX][NMAX];
int PD[NMAX][NMAX][NMAX];
int n, m, r;

int pd(int k, int s, int t) {
  if (PD[k][s][t] != -1) {
    return PD[k][s][t];
  }

  int out = 1e9;

  for (int i = 0; i < n; i++) {
    out = min(out, pd(k-1, s, i) + pd(0, i, t));
  }

  return PD[k][s][t] = out;
}

int main() {
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

  memset(PD, -1, sizeof(PD));
  for (int s = 0; s < n; s++) {
    for (int t = 0; t < n; t++) {
      PD[0][s][t] = 1e9;
      for (int i = 0; i < m; i++) {
        PD[0][s][t] = min(PD[0][s][t], G[i][s][t]);
      }
    }
  }

  for (int i = 0; i < r; i++) {
    int s, t, k;
    scanf("%d %d %d", &s, &t, &k);
    s--; t--;
    k = min(k, n);
    printf("%d\n", pd(k, s, t));
  }
  return 0;
}
