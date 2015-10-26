#include <bits/stdc++.h>

using namespace std;

#define NMAX 128
#define EPS 1e-8

#define vect point

struct point {
  long double x, y;
};

long double d(point a, point b) {
  return sqrtl((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

point P[NMAX];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%llf %llf", &P[i].x, &P[i].y);
  }
  long double R, r;
  scanf("%llf %llf", &R, &r);
  R -= r;
  int out = 0;
  if (R >= 0) {
    out = 1;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        long double dist = d(P[i], P[j]);
        if (2.0*R >= dist) {
          //printf("R = %.3f\n", (double) R);
          //printf("d = %.3f\n", dist);
          long double k = sqrt(((long double) R*R) - (dist*dist)/4.0);
          //printf("k = %.3f\n", k);
          vect v = {P[j].y-P[i].y, P[j].x-P[i].x};
          long double sz = sqrtl(v.x*v.x + v.y*v.y);
          v.x *= k/sz;
          v.y *= k/sz;
          point mid;
          mid.x = (P[i].x + P[j].x) / 2.0;
          mid.y = (P[i].y + P[j].y) / 2.0;
          //printf("mid = %.3f %.3f\n", mid.x, mid.y);
          //printf("v = %.3f %.3f\n", v.x, v.y);
          {
            point c = {mid.x, mid.y};
            int cnt = 0;
            for (int k = 0; k < n; k++) {
              if (d(c, P[k]) <= R) {
                cnt++;
              }
            }
            out = max(out, cnt);
          }
          {
            point c = {mid.x+v.x, mid.y+v.y};
            int cnt = 0;
            for (int k = 0; k < n; k++) {
              if (d(c, P[k]) <= R) {
                cnt++;
              }
            }
            out = max(out, cnt);
          }
          {
            point c = {mid.x-v.x, mid.y-v.y};
            int cnt = 0;
            for (int k = 0; k < n; k++) {
              if (d(c, P[k]) <= R) {
                cnt++;
              }
            }
            out = max(out, cnt);
          }
        }
      }
    }
  }
  printf("%d\n", out);
  return 0;
}
