#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-11

struct point {
  long double x, y;
};

point a, b, c;
double p;

long double d(point a, point b) {
  return sqrtl(powl(a.x-b.x, 2) + powl(a.y-b.y, 2));
}

long double get_p() {
  return d(a, b) + d(a, c) + d(b, c);
}

point walk(point base, long double dist, point goal) {
  point v = {goal.x-base.x, goal.y-base.y};
  double ang = v.y / v.x;

  point d;
  d.x = sqrtl(dist*dist / (1 + ang*ang));
  d.y = sqrtl(dist*dist - d.x*d.x);

  if (v.x < 0) {
    d.x = -d.x;
  }
  if (v.y < 0) {
    d.y = -d.y;
  }

  return (point) {base.x+d.x, base.y+d.y};
}

void test(point e, point f, point g, long double x, long double y) {
  if (d(e, f) < d(e, g) && x > y) {
    swap(x, y);
  }
  if (x > -EPS && y > -EPS && x < d(e, f) + EPS && y < d(e, g) + EPS) {
    point r = walk(e, x, f);
    point s = walk(e, y, g);
    printf("YES\n");
    printf("%.15Lf %.15Lf\n", r.x, r.y);
    printf("%.15Lf %.15Lf\n", s.x, s.y);
    exit(0);
  }
}

void get_s(point e, point f, point g) {
  long double delta = p*p - 8*d(e, f)*d(e, g);
  if (delta >= 0) {
    long double x1 = (p + sqrtl(delta)) / 4.0;
    long double x2 = (p - sqrtl(delta)) / 4.0;
    long double y1 = p/2 - x1;
    long double y2 = p/2 - x2;
    test(e, f, g, x1, y1);
    test(e, f, g, x2, y2);
  }
}

int main() {
  int x, y;
  scanf("%d %d", &x, &y);
  a = (point) {x, y};
  scanf("%d %d", &x, &y);
  b = (point) {x, y};
  scanf("%d %d", &x, &y);
  c = (point) {x, y};

  p = get_p();

  get_s(a, b, c);
  get_s(b, a, c);
  get_s(c, a, b);

  printf("NO\n");

  return 0;
}
