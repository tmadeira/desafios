#include <bits/stdc++.h>

using namespace std;

#define NMAX 200010

int P[NMAX];
int ps = 0;
int S[NMAX];

int main() {
  int n;
  scanf("%d", &n);
  P[ps++] = 0;
  double avg = 0;
  memset(S, 0, sizeof(S));
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);

    int a, x, k;
    switch (t) {
      case 1:
        scanf("%d %d", &a, &x);
        S[a-1] += x;
        avg += (a * x) / (double) ps;
        break;
      case 2:
        scanf("%d", &k);
        P[ps++] = k;
        avg = (avg * (ps - 1) + k) / (double) ps;
        break;
      case 3:
        k = P[ps - 1] + S[ps - 1];
        S[ps - 2] += S[ps - 1];
        S[ps - 1] = 0;
        ps--;
        avg = (avg * (ps + 1) - k) / (double) ps;
        break;
    }

    printf("%.6f\n", avg);
  }
  return 0;
}
