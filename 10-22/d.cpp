#include <bits/stdc++.h>

using namespace std;

#define NMAX 10050
#define MMAX 100050
#define DMAX 2048

int a[NMAX], q[NMAX];
int b[MMAX];
int D[DMAX], C[DMAX];

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int power(int b, int e, int p) {
  if (e == 0) {
    return 1;
  }
  long long out = power(b, e/2, p);
  out = (out * out) % (long long) p;
  if (e % 2 == 1) {
    out = (out * (long long) b) % (long long) p;
  }
  return out;
}

int main() {
  int n, m, p;
  scanf("%d %d %d", &n, &m, &p);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  for (int j = 0; j < m; j++) {
    scanf("%d", b+j);
  }

  int e = p - 1;
  for (int j = 0; j < m; j++) {
    e = gcd(e, b[j]);
  }

  int ds = 0;
  for (int div = 1; div * div <= p-1; div++) {
    if ((p - 1) % div == 0) {
      D[ds++] = div;
      if (div * div != p-1) {
        D[ds++] = (p - 1) / div;
      }
    }
  }
  sort(D, D + ds);

  for (int i = 0; i < n; i++) {
    for (int d = 0; d < ds; d++) {
      if (power(a[i], D[d], p) == 1) {
        q[i] = (p - 1) / D[d];
        q[i] = ((long long) q[i] * (long long) e) % (long long) (p - 1);
        q[i] = gcd(p - 1, q[i]);
        break;
      }
    }
  }

  int out = 0;
  for (int d = ds - 1; d >= 0; d--) {
    C[d] = (p - 1) / D[d];
    for (int f = d + 1; f < ds; f++) {
      if (D[f] % D[d] == 0) {
        C[d] -= C[f];
      }
    }
    for (int i = 0; i < n; i++) {
      if (D[d] % q[i] == 0) {
        out += C[d];
        break;
      }
    }
  }
  printf("%d\n", out);

  return 0;
}
