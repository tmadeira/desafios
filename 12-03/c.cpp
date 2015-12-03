#include <bits/stdc++.h>

using namespace std;

#define NMAX 100010

long long A[NMAX];
int L[NMAX], R[NMAX], D[NMAX];
long long Q[NMAX], O[NMAX];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    A[i] = a;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &L[i], &R[i], &D[i]);
    L[i]--;
    R[i]--;
  }
  memset(Q, 0, sizeof(Q));
  for (int i = 0; i < k; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--;
    y--;
    Q[x]++;
    Q[y+1]--;
  }
  memset(O, 0, sizeof(O));
  long long q = 0;
  for (int i = 0; i < m; i++) {
    q += Q[i];
    O[L[i]] += q * D[i];
    O[R[i]+1] -= q * D[i];
  }
  long long o = 0;
  for (int i = 0; i < n; i++) {
    o += O[i];
    A[i] += o;
  }
  for (int i = 0; i < n; i++) {
    printf("%I64d ", A[i]);
  }
  printf("\n");
  return 0;
}
