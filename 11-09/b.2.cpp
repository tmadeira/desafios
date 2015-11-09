#include <bits/stdc++.h>

using namespace std;

#define NMAX 10100

int n;
void *p;

struct point {
  int x, y;
  int i;
  bool operator < (const point &o) const {
    point *pp = (point *) p;
    return (x-pp->x) * (o.y-pp->y) - (o.x-pp->x) * (y-pp->y) > 0;
  }
};

point P[NMAX];

pair <double,int> A[NMAX];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &P[i].x, &P[i].y);
    P[i].i = i;
  }
  n--;
  p = P;
  sort(P, P+n);
  printf("%d %d\n", P[n/2].i+1, n+1);
  return 0;
}
