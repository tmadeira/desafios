#include <bits/stdc++.h>

using namespace std;

int main() {
  int w, d;
  int x0, y0;
  int xf, yf;

  scanf("%d %d", &w, &d);
  scanf("%d %d", &x0, &y0);
  scanf("%d %d", &xf, &yf);

  char c[1024];
  scanf("%s", c);
  int n = strlen(c);
  for (int i = 0; i < n; i++) {
    switch (c[i]) {
      case 'F':
        y0 = -y0;
        break;
      case 'L':
        x0 = -x0;
        break;
      case 'B':
        y0 = 2*d - y0;
        break;
      case 'R':
        x0 = 2*w - x0;
        break;
    }
  }

  double x = x0-xf;
  double y = y0-yf;
  printf("%.4f\n", sqrt(x*x+y*y));
  return 0;
}
