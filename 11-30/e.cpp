#include <bits/stdc++.h>

using namespace std;

#define NMAX 302

int A[NMAX];
int E[NMAX];
int M[NMAX];

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
  for (int s = 0; s < n; s++) {
    int v = s;
    memset(M, 0, sizeof(M));
    while (E[v] != -1) {
      M[v] = 1;

      t -= A[s];
      A[E[v]] += A[s];

      v = E[v];
      if (M[v]) {
        printf("0\n");
        return 0;
      }
    }
  }
  if (t < 0) {
    printf("0\n");
    return 0;
  }
  printf("goal = %d\n", t);
  for (int i = 0; i < n; i++) {
    printf("-> %d\n", A[i]);
  }
  return 0;
}
