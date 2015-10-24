#include <bits/stdc++.h>

#define INF 1000000000

#define NMAX 5005

using namespace std;

int A[NMAX], D[NMAX];
int T[NMAX], L[NMAX], R[NMAX], M[NMAX];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    A[i] = INF;
  }
  memset(D, 0, sizeof(D));
  for (int k = 0; k < m; k++) {
    int t, l, r, d;
    scanf("%d %d %d %d", &t, &l, &r, &d);
    T[k] = t;
    L[k] = --l;
    R[k] = r;
    M[k] = d;
    if (t == 1) {
      for (int i = l; i < r; i++) {
        D[i] += d;
      }
    } else {
      int can = 0;
      for (int i = l; i < r; i++) {
        if (A[i] >= d - D[i]) {
          can = 1;
          A[i] = d - D[i];
        }
      }
      if (!can) {
        printf("NO\n");
        return 0;
      }
    }
  }
  memset(D, 0, sizeof(D));
  for (int k = 0; k < m; k++) {
    int t = T[k], l = L[k], r = R[k], d = M[k];
    if (t == 1) {
      for (int i = l; i < r; i++) {
        D[i] += d;
      }
    } else {
      int can = 0;
      for (int i = l; i < r; i++) {
        if (A[i] == d - D[i]) {
          can = 1;
        }
      }
      if (!can) {
        printf("NO\n");
        return 0;
      }
    }
  }
  printf("YES\n");
  for (int i = 0; i < n; i++) {
    if (i != 0) {
      printf(" ");
    }
    printf("%d", A[i]);
  }
  printf("\n");
  return 0;
}
