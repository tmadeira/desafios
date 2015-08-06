#include <bits/stdc++.h>
using namespace std;
int A[128];
int main() {
  int n, a;
  scanf("%d", &n);
  memset(A, 0, sizeof(A));
  for (int k = 0; k < 2; k++) {
    int a;
    scanf("%d", &a);
    for (int i = 0; i < a; i++) {
      int x;
      scanf("%d", &x);
      A[x] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (!A[i+1]) {
      printf("Oh, my keyboard!\n");
      return 0;
    }
  }
  printf("I become the guy.\n");
  return 0;
}
