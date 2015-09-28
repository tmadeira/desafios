#include <bits/stdc++.h>

using namespace std;

#define NMAX 128

vector <int> E[NMAX];
int C[NMAX];
int imp = 0;

void dfs(int u, int c) {
  C[u] = c;
  for (int i = 0; i < E[u].size(); i++) {
    int v = E[u][i];
    if (C[v] == -1) {
      dfs(v, !c);
    } else if (C[v] == c) {
      imp = 1;
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int u = 0; u < n; u++) {
    int v;
    while (scanf("%d", &v) && v != 0) {
      v--;
      E[u].push_back(v);
      E[v].push_back(u);
    }
  }
  memset(C, -1, sizeof(C));
  for (int i = 0; i < n && !imp; i++) {
    if (C[i] == -1) {
      dfs(i, 0);
    }
  }
  if (imp) {
    printf("-1\n");
  } else {
    for (int i = 0; i < n; i++) {
      printf("%d", C[i]);
    }
    printf("\n");
  }
  return 0;
}
