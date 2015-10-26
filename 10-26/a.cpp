#include <bits/stdc++.h>

using namespace std;

#define NMAX 128

struct point {
  double x, y;
};

double d(point a, point b) {
  return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

point P[NMAX];

int main() {
  int n;
  double r;
  scanf("%d %lf", &n, &r);
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf", &P[i].x, &P[i].y);
  }
  double out = 2 * M_PI * r;
  for (int i = 0; i < n; i++) {
    out += d(P[i], P[(i+1)%n]);
  }
  printf("%.2f\n", out);
  return 0;
}
