#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int A[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", A+i);
  }
  sort(A, A+n);
  int count = 0;
  for (int i = 0; 2*i <= n; i++) {
    count+= (A[i]+1)/2;
  }
  printf("%d\n", count);
  return 0;
}
