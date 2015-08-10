#include <bits/stdc++.h>

using namespace std;

#define NMAX 100100

int F[NMAX];
int O[NMAX];
int P[NMAX];
map <int,int> inv;

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

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 0; i < n; i++) {
    F[i] = i;
    P[i] = 0;
    O[i] = 3;
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    inv[x] = i;
    if (inv.find(a-x) != inv.end()) {
      int o = inv[a-x];
      uf_union(i, o);
      P[i] |= 1;
      P[o] |= 1;
    }
    if (inv.find(b-x) != inv.end()) {
      int o = inv[b-x];
      uf_union(i, o);
      P[i] |= 2;
      P[o] |= 2;
    }
  }
  for (int i = 0; i < n; i++) {
    int r = uf_find(i);
    O[r] &= P[i];
  }
  for (int i = 0; i < n; i++) {
    int r = uf_find(i);
    if (!O[r]) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  for (int i = 0; i < n; i++) {
    if (i != 0) {
      printf(" ");
    }
    printf("%d", (O[uf_find(i)] & 1) ? 0 : 1);
  }
  printf("\n");
  return 0;
}
