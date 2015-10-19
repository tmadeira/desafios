#include <bits/stdc++.h>

using namespace std;

#define NMAX 128
#define MMAX (NMAX*NMAX)

struct point {
  int x, y;
};

point P[NMAX];
vector < pair<int, pair<int,int> > > E;

int d(point a, point b) {
  return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

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
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    F[i] = i;
    scanf("%d %d", &P[i].x, &P[i].y);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      E.push_back(make_pair(d(P[i], P[j]), make_pair(i, j)));
    }
  }
  sort(E.begin(), E.end());
  double tot = 0;
  for (int i = 0; i < E.size(); i++) {
    int d = E[i].first, u = E[i].second.first, v = E[i].second.second;
    if (uf_find(u) != uf_find(v)) {
      tot += sqrt(d);
      uf_union(u, v);
    }
  }
  printf("%f\n", tot);
  return 0;
}
