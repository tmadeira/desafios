#include <bits/stdc++.h>

using namespace std;

#define NMAX 200100

int A[NMAX], B[NMAX], P[NMAX];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    B[i] = x;
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    P[x] = i;
  }
  for (int i = 0; i < n; i++) {
    A[i] = P[B[i]];
  }
  for (int i = 1; i < n; i++) {
    if (A[i] < A[i-1]) {
      printf("%d\n", n-i);
      return 0;
    }
  }
  printf("0\n");
  return 0;
}
