#include <bits/stdc++.h>

using namespace std;

#define NMAX 1024

vector < pair <int, pair<int,int> > > E;
int F[NMAX];
int M[NMAX];

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
  int n, m, p;
  while (scanf("%d %d %d", &n, &m, &p) != EOF) {
    E.clear();
    memset(M, -1, sizeof(M));
    for (int i = 0; i < p; i++) {
      int k;
      scanf("%d", &k);
      M[k-1] = 1;
    }
    for (int i = 0; i < n; i++) {
      F[i] = i;
    }
    for (int i = 0; i < m; i++) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      E.push_back(make_pair(c, make_pair(a-1, b-1)));
    }
    int sum = 0;
    sort(E.begin(), E.end());
    for (int e = 0; e < E.size(); e++) {
      int u = E[e].second.first, v = E[e].second.second;
      if (uf_find(u) != uf_find(v)) {
        if (n == 2 && (M[u] < 0 || M[u] > 0) && (M[v] < 0 || M[v] > 0)) {
          sum += E[e].first;
          uf_union(u, v);
          M[u]--;
          M[v]--;
        } else if (n > 2 && ((M[u] < 0 && M[v] < 0) || (M[u] < 0 && M[v] > 0) || (M[u] > 0 && M[v] < 0))) {
          sum += E[e].first;
          uf_union(u, v);
          M[u]--;
          M[v]--;
        }
      }
    }
    int f = uf_find(0);
    int imp = 0;
    for (int i = 0; i < n; i++) {
      if (uf_find(i) != f) {
        imp = 1;
      } 
    }
    if (imp) {
      printf("impossible\n");
    } else {
      printf("%d\n", sum);
    }
  }
  return 0;
}
