#include <bits/stdc++.h>

using namespace std;

char A[64][64];
int M[64][64];
int n;
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
int c;

void dfs(int i, int j) {
  if (M[i][j]) {
    return;
  }
  M[i][j] = 1;
  for (int d = 0; d < 4; d++) {
    int k = i+di[d], l = j+dj[d];
    if (A[k][l] == '#') {
      c++;
    } else {
      if (1 <= k && k <= n && 1 <= l && l <= n) {
        dfs(k, l);
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  memset(A, '#', sizeof(A));
  memset(M, 0, sizeof(M));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf(" %c", &A[i][j]);
    }
  }
  A[0][1] = A[1][0] = '.';
  A[n][n+1] = A[n+1][n] = '.';
  c = 0;
  dfs(1, 1);
  dfs(n, n);
  printf("%d\n", c*9);
  return 0;
}
