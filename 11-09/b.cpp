#include <bits/stdc++.h>

using namespace std;

#define NMAX 10100

void *vp;

struct point {
  long double x, y;
  int i;
  bool operator < (const point &o) const {
    point *p = (point *) vp;
    return (x - p->x) * (o.y - p->y) < (y - p->y) * (o.x - p->x);
  }
};

point P[NMAX];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    P[i] = (point) { x, y, i };
  }
  n--;
  for (int i = 0; i < n; i++) {
    if (P[i].y < P[n].y || (P[i].y == P[n].y && P[i].x < P[n].x)) {
      swap(P[i], P[n]);
    }
  }
  vp = P+n;
  sort(P, P+n);
  printf("%d %d\n", P[n].i+1, P[n/2].i+1);
  return 0;
}
