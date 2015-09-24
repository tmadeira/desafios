#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
typedef unsigned long long llu;

#define NMAX 100100
#define MMAX 100100

pair<int,int> E[MMAX];
int Q[MMAX];
int P[MMAX];

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
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    F[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    E[i] = make_pair(a-1, b-1);
  }
  int q;
  scanf("%d", &q);
  memset(P, 0, sizeof(P));
  for (int i = 0; i < q; i++) {
    scanf("%d", Q+i);
    Q[i]--;
    P[Q[i]] = 1;
  }
  for (int i = 0; i < m; i++) {
    if (!P[i]) {
      uf_union(E[i].first, E[i].second);
    }
  }
  int out = 0;
  for (int i = 0; i < n; i++) {
    if (uf_find(i) == i) {
      out++;
    }
  }
  int O[MMAX];
  for (int i = q-1; i >= 0; i--) {
    int e = Q[i];
    O[i] = out;
    if (uf_find(E[e].first) != uf_find(E[e].second)) {
      out--;
      uf_union(E[e].first, E[e].second);
    }
  }
  for (int i = 0; i < q; i++) {
    printf("%d ", O[i]);
  }
  printf("\n");
  return 0;
}
