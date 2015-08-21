#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 100000;
  printf("%d\n", n);
  int a = 0, b = 0, c = 0, d = 0;
  for (int i = 0; i < n; i++) {
    printf("-100 %02d.%02d %02d:%02d\n", a, b, c, d);
    a++;
    if (a == 100) {
      a = 0;
      b++;
      if (b == 100) {
        b = 0;
        c++;
        if (c == 100) {
          c = 0;
          d++;
        }
      }
    }
  }
  return 0;
}
