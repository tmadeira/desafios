#include <bits/stdc++.h>

using namespace std;

#define NMAX 128

int main() {
  double l, r;
  scanf("%lf %lf", &l, &r);
  double out = 0;
  if (2*r <= l) {
    out = M_PI * r * r;
  } else if (2*r > sqrt(2)*l) {
    out = l * l;
  } else {
    double theta = 2 * acos(l / (2.0*r));
    double segarea = (r * r * theta) / 2.0;
    double base = sqrt(4*r*r - l*l);
    double trigarea = (base * l) / 4;
    out = M_PI * r * r - 4 * (segarea - trigarea);
  }
  printf("%.3f\n", out);
  return 0;
}
