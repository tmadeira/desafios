#include <bits/stdc++.h>
using namespace std;
#define NMAX 128
#define MMAX 1024
int A[NMAX], B[NMAX];
int main() {
  int n, x0;
  scanf("%d %d", &n, &x0);
  int left = 0, right = MMAX;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", A+i, B+i);
    if (A[i] > B[i]) {
      swap(A[i], B[i]);
    }
    left = max(left, A[i]);
    right = min(right, B[i]);
  }
  if (left > right) {
    printf("-1\n");
    return 0;
  }
  if (left <= x0 && x0 <= right) {
    printf("0\n");
    return 0;
  }
  int out = min(abs(x0 - left), abs(x0 - right));
  printf("%d\n", out);
  return 0;
}
