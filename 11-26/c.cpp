#include <bits/stdc++.h>

using namespace std;

#define NMAX 16
#define MMAX 128

int A[NMAX][MMAX], B[NMAX][MMAX], C[NMAX][MMAX];
pair <int,int> tmp[MMAX];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    scanf("%*s");
    for (int j = 0; j < m; j++) {
      scanf("%d %d %d", &A[i][j], &B[i][j], &C[i][j]);
    }
  }
  int best = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      for (int l = 0; l < m; l++) {
        tmp[l] = make_pair(B[j][l] - A[i][l], C[i][l]);
      }
      sort(tmp, tmp+m);
      int kk = k;
      int sum = 0;
      for (int l = m-1; l >= 0 && tmp[l].first > 0 && kk; l--) {
        sum += tmp[l].first * min(tmp[l].second, kk);
        kk -= min(tmp[l].second, kk);
      }
      if (sum > best) {
        best = sum;
      }
    }
  }
  printf("%d\n", best);
  return 0;
}
