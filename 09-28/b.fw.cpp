#include <bits/stdc++.h>

using namespace std;

#define NMAX 128

int G[NMAX][NMAX], D[NMAX][NMAX], E[NMAX][NMAX];

int main() {
  int n;
  while (scanf("%d", &n) && n != -1) {
    memset(G, -1, sizeof(G));
    memset(E, -1, sizeof(E));
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      a--;
      b--;
      if (G[a][b] == -1 || G[a][b] > c) {
        E[a][b] = E[b][a] = c;
        G[a][b] = G[b][a] = c;
        D[a][b] = D[b][a] = 1;
      }
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        if (G[i][k] == -1) continue;
        for (int j = 0; j < n; j++) {
          if (G[k][j] == -1) continue;
          if (G[i][j] == -1 || G[i][k] + G[k][j] < G[i][j]) {
            G[i][j] = G[i][k] + G[k][j];
            D[i][j] = D[i][k] + D[k][j];
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (j == i) continue;
        for (int k = 0; k < n; k++) {
          if (k == i) continue;
          if (E[j][k] != -1 && D[i][j] + D[i][k] > 2) {
            printf("solucao %d-...-%d-%d-...-%d com custo %d eh valida\n", i, j, k, i, G[i][j]+G[i][k]+E[j][k]);
          }
        }
      }
    }
    printf("==\n");
  }
  return 0;
}
