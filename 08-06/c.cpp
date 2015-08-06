#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  if (n < 4) {
    printf("NO\n");
    return 0;
  }
  if (n == 4) {
    printf("YES\n");
    printf("4 * 3 = 12\n");
    printf("2 * 1 = 2\n");
    printf("12 * 2 = 24\n");
    return 0;
  }
  if (n == 5) {
    printf("YES\n");
    printf("5 + 1 = 6\n");
    printf("6 * 4 = 24\n");
    printf("3 - 2 = 1\n");
    printf("24 * 1 = 24\n");
  }
  if (n > 5) {
    printf("YES\n");
    printf("6 * 4 = 24\n");
    printf("5 - 3 = 2\n");
    printf("2 - 2 = 0\n");
    printf("0 * 1 = 0\n");
    for (int i = 7; i <= n; i++) {
      printf("0 * %d = 0\n", i);
    }
    printf("24 - 0 = 24\n");
  }
  return 0;
}
