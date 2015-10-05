#include <bits/stdc++.h>

using namespace std;

#define NMAX 512

vector <int> E[NMAX];
int M[NMAX];
int guys;

void dfs(int u) {
  M[u] = 1;
  guys++;
  for (int i = 0; i < E[u].size(); i++) {
    int v = E[u][i];
    if (!M[v]) {
      dfs(v);
    }
  }
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int w = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      int c;
      scanf("%d", &c);
      c--;
      if (c != i) {
        E[i].push_back(c);
        w++;
      }
    }
  }

  memset(M, 0, sizeof(M));
  int comp = 0;
  for (int i = 0; i < n; i++) {
    if (!M[i]) {
      guys = 0;
      dfs(i);
      if (guys > 1) {
        comp++;
      }
    }
  }

  printf("%d\n", w+max(comp-1, 0));

  return 0;
}
