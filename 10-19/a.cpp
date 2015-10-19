#include <bits/stdc++.h>

using namespace std;

#define NMAX 512
#define MMAX (NMAX*NMAX)

struct point {
  long long x, y;
};

point P[NMAX];

double d(point a, point b) {
  return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    P[i].x = x;
    P[i].y = y;
  }
  double tot = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      double di = d(P[i], P[j]);
      long long vx = P[j].x - P[i].x;
      long long vy = P[j].y - P[i].y;

      for (int k = 0; k < n && di; k++) {
        if (i != k && j != k) {
          long long ux = P[k].x - P[i].x;
          long long uy = P[k].y - P[i].y;

          if (ux*vy == uy*vx) {
            if (P[i].x < P[k].x && P[k].x < P[j].x) {
              di = 0;
            } else if (P[i].y < P[k].y && P[k].y < P[j].y) {
              di = 0;
            } else if (P[i].x > P[k].x && P[k].x > P[j].x) {
              di = 0;
            } else if (P[i].y > P[k].y && P[k].y > P[j].y) {
              di = 0;
            }
          }
        }
      }

      tot += sqrt(di);
    }
  }
  int x = (int) (tot+0.5);
  printf("%d\n", x);
  return 0;
}
