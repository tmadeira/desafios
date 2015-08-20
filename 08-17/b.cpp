#include <bits/stdc++.h>

using namespace std;

#define NMAX 1048576

int F[NMAX];

int uf_find(int x) {
  if (F[x] == x) {
    return x;
  }

  return F[x] = uf_find(F[x]);
}

int uf_union(int x, int y) {
  x = uf_find(x);
  y = uf_find(y);
  F[x] = y;
}

int main() {
  int k;
  scanf("%d", &k);

  map <int, vector<int> > sq, un;

  for (int n = 1; n < NMAX; n++) {
    F[n] = n;
    int sqx = ((long long)n*(long long)n)%k;
    int unx = n%k;

    set <int> M;

    int kunx = (k-unx)%k;
    if (sq.count(kunx)) {
      for (int i = 0; i < sq[kunx].size(); i++) {
        int v = sq[kunx][i];
        if (uf_find(n) == uf_find(v)) {
          printf("%d\n", n);
          return 0;
        }
        uf_union(n, v);
        M.insert(v);
      }
    }

    int ksqx = (k-sqx)%k;
    if (un.count(ksqx)) {
      for (int i = 0; i < un[ksqx].size(); i++) {
        int v = un[ksqx][i];
        if (M.find(v) != M.end()) {
          continue;
        }
        if (uf_find(n) == uf_find(v)) {
          printf("%d\n", n);
          return 0;
        }
        uf_union(n, v);
      }
    }

    sq[sqx].push_back(n);
    un[unx].push_back(n);
  }

  assert(2 == 3);
  return 0;
}
