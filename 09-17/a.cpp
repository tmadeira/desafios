#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
typedef unsigned long long llu;

int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  if (c < a) {
    c = a;
  }
  while (1) {
    if (a+b < c) {
      a += b;
    } else {
      printf("%d\n", c);
      return 0;
    }
    if (c-d > a) {
      c -= d;
    } else {
      printf("%d\n", a);
      return 0;
    }
  }
  return 0;
}
