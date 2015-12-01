#include <bits/stdc++.h>

using namespace std;

#define NMAX 302
#define TMAX 100010
#define MOD ((int) 1e9 + 7)

int A[NMAX];
int D[NMAX];
int E[NMAX];
int M[NMAX];
int PD[NMAX][TMAX];

int main() {
  int n, q, t;
  scanf("%d %d %d", &n, &q, &t);
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  memset(E, -1, sizeof(E));
  for (int i = 0; i < q; i++) {
    int b, c;
    scanf("%d %d", &b, &c);
    E[b-1] = c-1;
  }
  memset(D, 0, sizeof(D));
  for (int s = 0; s < n; s++) {
    int v = s;
    memset(M, 0, sizeof(M));
    while (E[v] != -1) {
      M[v] = 1;

      t -= A[s];
      D[E[v]] += A[s];

      v = E[v];
      if (M[v] || t < 0) {
        printf("0\n");
        return 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    A[i] += D[i];
  }
  memset(PD, 0, sizeof(PD));
  PD[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    PD[i][0] = 1;
    for (int j = 1; j <= t; j++) {
      PD[i][j] = PD[i-1][j];
      if (j >= A[i-1]) {
        PD[i][j] += PD[i][j-A[i-1]];
        PD[i][j] %= MOD;
      }
    }
  }
  printf("%d\n", PD[n][t]);
  return 0;
}
