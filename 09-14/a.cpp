#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
typedef unsigned long long llu;

int main() {
  int n;
  scanf("%d", &n);
  int A[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", A+i);
  }
  int mi = 1000000000;
  for (int j = 0; j < (1<<n); j++) {
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      if ((1<<i) & j) {
        a+= A[i];
      } else {
        b+= A[i];
      }
    }
    mi = min(mi, max(a-b, b-a));
  }
  printf("%d\n", mi);
  return 0;
}
