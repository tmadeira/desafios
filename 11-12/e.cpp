#include <bits/stdc++.h>

using namespace std;

#define NMAX 100010

vector <int> E[NMAX];
int K[NMAX];
int n, m, k, s, t;
int S[NMAX], D[NMAX], F[NMAX];

int uf_find(int v) {
  if (F[v] == v) {
    return v;
  }
  return F[v] = uf_find(F[v]);
}

void uf_union(int u, int v) {
  u = uf_find(u);
  v = uf_find(v);
  F[v] = u;
}

int f(int q) {
  memset(D, -1, sizeof(D));
  memset(S, -1, sizeof(S));
  queue <int> Q;

  S[s] = s;
  D[s] = 0;
  Q.push(s);
  F[s] = s;

  S[t] = t;
  D[t] = 0;
  Q.push(t);
  F[t] = t;

  for (int i = 0; i < k; i++) {
    S[K[i]] = K[i];
    D[K[i]] = 0;
    Q.push(K[i]);
    F[K[i]] = K[i];
  }

  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int i = 0; i < E[u].size(); i++) {
      int v = E[u][i];
      if (D[v] == -1) {
        D[v] = D[u] + 1;
        S[v] = S[u];
        Q.push(v);
      } else if (D[u] + D[v] + 1 <= q) {
        uf_union(S[u], S[v]);
      }
    }
  }

  return uf_find(s) == uf_find(t);
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    scanf("%d", &K[i]);
    K[i]--;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  scanf("%d %d", &s, &t);
  s--;
  t--;

  int l = 0, r = n + 2;
  while (l < r) {
    int m = (l + r) / 2;
    if (f(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }

  printf("%d\n", l > n ? -1 : l);

  return 0;
}
