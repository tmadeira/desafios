#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int A[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  int r = 1<<30;
  for (int i = 1; i < n-1; i++) {
    int m = 0;
    for (int j = 0; j < n-1; j++) {
      int d;
      if (j == i-1) {
        d = A[j+2] - A[j];
      } else if (j == i) {
        continue;
      } else {
        d = A[j+1] - A[j];
      }
      if (d > m) {
        m = d;
      }
    }
    if (m < r) {
      r = m;
    }
  }
  printf("%d\n", r);
  return 0;
}
