#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
typedef unsigned long long llu;

int n;
int A[9][9];
vector < pair<int,int> > V;
int linha[9], coluna[9], box[3][3];
const int P[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };

int f(int l) {
  if (l == V.size()) {
    for (int i = 0; i < n*n; i++) {
      for (int j = 0; j < n*n; j++) {
        if (j != 0) {
          printf(" ");
        }
        printf("%d", A[i][j]);
      }
      printf("\n");
    }
    return 1;
  }
  int i = V[l].first;
  int j = V[l].second;
  for (int k = 1; k <= n*n; k++) {
    if (linha[i] % P[k-1] != 0 && coluna[j] % P[k-1] != 0 && box[i/n][j/n] % P[k-1] != 0) {
      linha[i] *= P[k-1];
      coluna[j] *= P[k-1];
      box[i/n][j/n] *= P[k-1];
      A[i][j] = k;
      if (f(l+1)) {
        return 1;
      }
      linha[i] /= P[k-1];
      coluna[j] /= P[k-1];
      box[i/n][j/n] /= P[k-1];
    }
  }
  return 0;
}

int main() {
  for (int test = 1; scanf("%d", &n) != EOF; test++) {
    int p = 0;
    int fi = n*n, fj = n*n;
    V.clear();
    for (int i = 0; i < n*n; i++) {
      linha[i] = 1;
      coluna[i] = 1;
      box[i/n][i%n] = 1;
    }
    for (int i = 0; i < n*n; i++) {
      for (int j = 0; j < n*n; j++) {
        scanf("%d", &A[i][j]);
        if (A[i][j] == 0) {
          V.push_back(make_pair(i, j));
        } else {
          linha[i] *= P[A[i][j]-1];
          coluna[j] *= P[A[i][j]-1];
          box[i/n][j/n] *= P[A[i][j]-1];
        }
      }
    }
    if (test != 1) {
      printf("\n");
    }
    if (!f(0)) {
      printf("NO SOLUTION\n");
    }
  }
  return 0;
}
