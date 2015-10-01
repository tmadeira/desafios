#include <bits/stdc++.h>

using namespace std;

#define NMAX 32
#define MMAX 512

pair < int, pair<int,int> > E[MMAX];
int s[NMAX], always[NMAX], v[NMAX], inv[NMAX], ac[NMAX], parent[NMAX];

int F[NMAX];

int uf_find(int a) {
  if (F[a] == a) {
    return a;
  } else {
    return F[a] = uf_find(F[a]);
  }
}

void uf_union(int a, int b) {
  a = uf_find(a);
  b = uf_find(b);
  F[b] = a;
}


int main() {
  int n, m, t;
  for (int test = 1; scanf("%d", &n) && n != -1; test++) {
    printf("Case %d: ", test);
    memset(always, 0, sizeof(always));
    scanf("%d %d", &t, &m);
    always[--t] = 1;
    for (int i = 0; i < m; i++) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      E[i] = make_pair(c, make_pair(a-1, b-1));
    }
    sort(E, E+m);
    int sc;
    scanf("%d", &sc);
    for (int i = 0; i < sc; i++) {
      scanf("%d", &s[i]);
      always[--s[i]] = 1;
    }
    int vc = 0;
    for (int i = 0; i < n; i++) {
      if (!always[i]) {
        inv[i] = vc;
        v[vc++] = i;
      }
    }
    vector < pair < int,pair<int,int> > > solutions;
    for (int S = 0; S < (1<<vc); S++) {
      int nc = 0;
      for (int i = 0; i < n; i++) {
        F[i] = i;
        ac[i] = 0;
        if (always[i] || S & (1<<inv[i])) {
          ac[i] = 1;
          nc++;
        }
      }
      int cost = 0;
      for (int i = 0; i < m; i++) {
        int u = E[i].second.first;
        int v = E[i].second.second;
        int w = E[i].first;
        if (ac[u] && ac[v] && uf_find(u) != uf_find(v)) {
          cost += w;
          uf_union(u, v);
        }
      }
      int f = uf_find(t);
      int imp = 0;
      for (int i = 0; i < sc; i++) {
        if (uf_find(s[i]) != f) {
          imp = 1;
        }
      }
      if (!imp) {
        solutions.push_back(make_pair(cost, make_pair(nc, S)));
      }
    }
    sort(solutions.begin(), solutions.end());
    if (solutions.size()) {
      int cost = solutions[0].first;
      int S = solutions[0].second.second;
      
      printf("distance = %d\n", cost);

      vector <int> G[NMAX];
      int nc = 0;
      for (int i = 0; i < n; i++) {
        F[i] = i;
        ac[i] = 0;
        if (always[i] || S & (1<<inv[i])) {
          ac[i] = 1;
          nc++;
        }
      }
      for (int i = 0; i < m; i++) {
        int u = E[i].second.first;
        int v = E[i].second.second;
        if (ac[u] && ac[v] && uf_find(u) != uf_find(v)) {
          G[u].push_back(v);
          G[v].push_back(u);
          uf_union(u, v);
        }
      }
      queue <int> Q;
      Q.push(t);
      memset(parent, -1, sizeof(parent));
      while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < G[u].size(); i++) {
          int v = G[u][i];
          if (parent[u] != v) {
            parent[v] = u;
            Q.push(v);
          }
        }
      }
      for (int i = 0; i < sc; i++) {
        int x = s[i];
        printf("   %d", x+1);
        while (parent[x] != -1) {
          x = parent[x];
          printf("-%d", x+1);
        }
        printf("\n");
      }
      printf("\n");
    } else {
      assert(false);
    }
  }
  return 0;
}
