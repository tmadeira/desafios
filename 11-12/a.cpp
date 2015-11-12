#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b, c;
  scanf("%d %d %d %d", &n, &a, &b, &c);
  int p = 0;
  for (int i = 0; a*i <= n; i++) {
    for (int j = 0; a*i+b*j <= n; j++) {
      int miss = n-a*i-b*j;
      if (miss >= 0 && miss % c == 0) {
        p = max(p, i+j+miss/c);
      }
    }
  }
  printf("%d\n", p);
  return 0;
}
