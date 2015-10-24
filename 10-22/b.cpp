#include <bits/stdc++.h>

using namespace std;

#define NMAX 2048

int n, k;
int A[NMAX];
int PD[NMAX];

int f(int x) {
  for (int i = 0; i < n; i++) {
    PD[i] = i;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (abs(A[j] - A[i]) <= ((long long) (j - i)) * ((long long) x)) {
        PD[j] = min(PD[j], PD[i] + j - 1 - i);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (PD[i] + n - 1 - i <= k) {
      return 1;
    }
  }
  return 0;
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", A+i);
  }
  unsigned l = 0, r = 2000000001;
  while (l < r) {
    unsigned m = (l + r) / 2;
    if (f(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  printf("%u\n", l);
  return 0;
}
