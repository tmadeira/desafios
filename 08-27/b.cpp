#include <bits/stdc++.h>

using namespace std;

typedef long long lld;

int k;

lld f(int n, int l) {
  return (n == 0 ? 1 : (k-1)*f(n-1, 0) + (l == 0 ? f(n-1, 1) : 0));
}

int main() {
  int n;
  scanf("%d %d", &n, &k);
  printf("%lld\n", (k-1)*f(n-1, 0));
  return 0;
}
