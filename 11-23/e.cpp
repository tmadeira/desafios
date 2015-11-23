#include <bits/stdc++.h>

using namespace std;

#define NMAX 32
#define TMAX 16
#define LMAX 8

int PD[NMAX][TMAX][TMAX][LMAX][LMAX];

int pd(int n, int t, int o, int p2, int p1) {
  if (n == 0) {
    return t == 0 && o == 0;
  }
  if (PD[n][t][o][p2][p1] != -1) {
    return PD[n][t][o][p2][p1];
  }
  int out = 0;
  for (int l = 1; l <= 4; l++) {
    if (l == p1) {
      continue;
    }

    int nt = t;
    if (p2 != 5 && p2 < p1 && p1 > l) {
      nt--;
    }

    int no = o;
    if (p2 != 5 && p2 > p1 && p1 < l) {
      no--;
    }

    if (nt < 0 || no < 0) {
      continue;
    }

    out += pd(n-1, nt, no, p1, l);
  }
  return PD[n][t][o][p2][p1] = out;
}

int main() {
  int n, t;
  scanf("%d %d\n", &n, &t);
  memset(PD, -1, sizeof(PD));
  printf("%d\n", pd(n, t, t-1, 5, 5));
  return 0;
}
