#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
typedef unsigned long long llu;

int main() {
  int k, n;
  scanf("%d %d", &k, &n);
  int a[n];
  int r = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    r = max(0, a[i]+r-k);
  }
  printf("%d\n", r);
  return 0;
}
