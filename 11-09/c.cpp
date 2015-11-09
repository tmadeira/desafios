#include <bits/stdc++.h>

using namespace std;

#define NMAX 4096
typedef long long ll;

void *vp;

ll d(ll x, ll y) {
  return x*x + y*y;
}

struct point {
  ll x, y;
  int i;
  bool operator < (const point &o) const {
    point *p = (point *) vp;
    ll s = (x - p->x) * (o.y - p->y) - (y - p->y) * (o.x - p->x);
    return (s > 0 || (s == 0 && d(x-p->x, y-p->y) < d(o.x-p->x, o.y-p->y)));
  }
};

point F[NMAX], P[NMAX];
int M[NMAX];
int H[NMAX];
int n;

ll side(point a, point b, point c) {
  return (b.x-a.x) * (c.y-a.y) - (b.y-a.y) * (c.x-a.x);
}

int graham() {
  int m = 0;
  for (int i = 0; i < n; i++) {
    if (!M[i]) {
      P[m++] = F[i];
    }
  }

  if (m < 3) {
    return 0;
  }

  for (int i = 1; i < m; i++) {
    if (P[i].y < P[0].y || (P[i].y == P[0].y && P[i].x < P[0].x)) {
      swap(P[i], P[0]);
    }
  }
  vp = P;
  sort(P+1, P+m);

  int r = m-1;
  for (int i = m-2; i > 0 && side(P[0], P[i], P[m-1]) == 0; i--) {
    r = i;
  }
  reverse(P+r, P+m);

  H[0] = 0;
  H[1] = 1;
  H[2] = 2;
  int h = 3;

  for (int k = 3; k < m; k++) {
    while (h > 1 && side(P[H[h-2]], P[H[h-1]], P[k]) < 0) {
      h--;
    }
    H[h++] = k;
  }

  if (h < 3) {
    return 0;
  }

  int col = 1;
  for (int i = 0; i+2 < h; i++) {
    col = col && (side(P[H[i]], P[H[i+1]], P[H[i+2]]) == 0);
  }
  if (col) {
    return 0;
  }

  for (int i = 0; i < h; i++) {
    M[P[H[i]].i] = 1;
  }
  return 1;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    F[i] = (point) {x, y, i};
    M[i] = 0;
  }

  int output = 0;
  while (graham()) {
    output++;
  }
  printf("%d\n", output);
  return 0;
}
