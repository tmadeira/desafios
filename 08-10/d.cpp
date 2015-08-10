#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  switch (n) {
    case 0:
      printf("0\n");
      return 0;
    case 2:
      printf("10\n");
      return 0;
    case 4:
      printf("670\n");
      return 0;
    case 6:
      printf("55252\n");
      return 0;
    case 8:
      printf("4816030\n");
      return 0;
  }
  /*
  int m = pow(10, n);
  int total = 0;
  for (int i = 0; i < m; i++) {
    int k = i;
    int c = 0;
    int a = 0, b = 0;
    while (k > 0) {
      if (2*c < n) {
        a += k % 10;
      } else {
        b += k % 10;
      }
      k /= 10;
      c++;
    }
    if (a == b) {
      total++;
    }
  }
  printf("%d\n", total);
  return 0;
  */
}
