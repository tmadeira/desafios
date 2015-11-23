#include <bits/stdc++.h>
using namespace std;
#define NMAX 64
int A[NMAX][NMAX];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int si = NMAX, sj = NMAX, ti = -1, tj = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf(" %c", &A[i][j]);
      if (A[i][j] == '*') {
        si = min(si, i);
        ti = max(ti, i);
        sj = min(sj, j);
        tj = max(tj, j);
      }
    }
  }
  for (int i = si; i <= ti; i++) {
    for (int j = sj; j <= tj; j++) {
      printf("%c", A[i][j]);
    }
    printf("\n");
  }
  return 0;
}
