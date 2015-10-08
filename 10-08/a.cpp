#include <bits/stdc++.h>

using namespace std;

#define NMAX 32768

int n = 0, m;
int A[NMAX];

int main() {
  scanf("%d", &m);
  int x;
  while (scanf("%d", &x) && x != -1) {
    A[n++] = x;
  }

  multiset <int> S;
  for (int i = 0; i < m; i++) {
    S.insert(A[i]);
  }

  for (int i = m; i <= n; i++) {
    printf("%d\n", *(S.rbegin()));
    S.erase(S.find(A[i-m]));
    if (i != n) {
      S.insert(A[i]);
    }
  }

  return 0;
}
