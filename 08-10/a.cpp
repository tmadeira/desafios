#include <bits/stdc++.h>

using namespace std;

int main() {
  int tests;
  scanf("%d", &tests);
  while (tests--) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      r+= a*c;
    }
    printf("%d\n", r);
  }
  return 0;
}
