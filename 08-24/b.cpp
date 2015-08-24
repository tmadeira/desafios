#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
typedef unsigned long long llu;
typedef long double ldouble;

llu mul_mod(llu a, llu b, llu m) {
    llu y = (llu)((ldouble)a*(ldouble)b/m+(ldouble)1/2); y = y * m;
    llu x = a * b, r = x - y;
    if ((lld) r < 0) { r = r + m; y = y - 1; }
    return r;
}

llu exp_mod(llu a, llu e, llu mod) {
    if (e == 0) return 1;
    llu b = exp_mod(a, e/2, mod);
    return (e % 2 == 0) ? mul_mod(b, b, mod) : mul_mod(mul_mod(b, b, mod), a, mod);
}

llu llrand() { llu a = rand(); a<<= 32; a+= rand(); return a;}

int is_probably_prime(llu n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    llu s = 0, d = n - 1;
    while (d % 2 == 0) {
        d/= 2; s++;
    }
    for (int k = 0; k < 64; k++) {
        llu a = (llrand() % (n - 3)) + 2;
        llu x = exp_mod(a, d, n);
        if (x != 1 && x != n-1) {
            for (int r = 1; r < s; r++) {
                x = mul_mod(x, x, n);
                if (x == 1)
                    return 0;
                if (x == n-1)
                    break;
            }
            if (x != n-1)
                return 0;
        }
    }
    return 1;
}

int main() {
  int n;
  scanf("%d", &n);

  long long m;
  scanf("%lld", &m);

  if (n == 12) {
    printf("%lld\n", m);
    return 0;
  }

  srand(time(NULL));

  for (llu i = m * pow(10, 12-n); ; i++) {
    if (is_probably_prime(i)) {
      printf("%012llu\n", i);
      return 0;
    }
  }

  return 0;
}
