#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
typedef unsigned long long llu;

int G[128];
vector <int> E[128];
int M[128];

int main() {
  int n;
  scanf("%d", &n);
  memset(G, 0, sizeof(G));
  for (int u = 0; u < n; u++) {
    int v;
    while (scanf("%d", &v) && v != 0) {
      E[u].push_back(v-1);
      G[v-1]++;
    }
  }
  memset(M, 0, sizeof(M));
  queue <int> Q;
  for (int i = 0; i < n; i++) {
    if (!G[i]) {
      Q.push(i);
      M[i] = 1;
    }
  }
  vector <int> O;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    O.push_back(u);
    for (int i = 0; i < E[u].size(); i++) {
      int v = E[u][i];
      G[v]--;
      if (G[v] == 0 && !M[v]) {
        M[v] = 1;
        Q.push(v);
      }
    }
  }
  for (int i = 0; i < O.size(); i++) {
    if (i != 0) {
      printf(" ");
    }
    printf("%d", O[i]+1);
  }
  printf("\n");
  return 0;
}
