#include <bits/stdc++.h>

using namespace std;

#define NMAX 128

int A[NMAX][NMAX];
int B[NMAX][NMAX];

vector <int> E[NMAX*NMAX];

int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };

int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &A[i][j]);
    }
  }
  memset(B, 0, sizeof(B));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      for (int d = 0; d < 4; d++) {
        int ni = i+di[d];
        int nj = j+dj[d];
        if (0 <= ni && ni < m && 0 <= nj && nj < n) {
          if (A[i][j] != A[ni][nj]) {
            E[i*n+j].push_back(ni*n+nj);
          }
        }
      }
    }
  }
  queue <int> Q;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!B[i][j] && E[i*n+j].size() == 1) {
        Q.push(i*n+j);
      }
    }
  }

  int k = 1;

  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    int ui = u/n, uj = u%n;

    if (!B[ui][uj]) {
      int v = E[u][0];
      int vi = v/n, vj = v%n;

      B[ui][uj] = k;
      B[vi][vj] = k;
      k++;

      for (int i = 0; i < E[v].size(); i++) {
        int w = E[v][i];
        for (int j = 0; j < E[w].size(); j++) {
          if (E[w][j] == v) {
            E[w].erase(E[w].begin()+j);
            break;
          }
        }
        if (E[w].size() == 1) {
          Q.push(w);
        }
      }
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", B[i][j]);
    }
    printf("\n");
  }

  return 0;
}
