#include <bits/stdc++.h>

using namespace std;

#define NMAX 100010
#define MOD ((long long) 1e9+7)

char A[NMAX];
char B[NMAX];

int L[NMAX], G[NMAX], E[NMAX];
long long ML[NMAX], MG[NMAX], ME[NMAX];

int pot(int b, int e) {
  if (e == 0) {
    return 1;
  }
  long long out = pot(b, e/2);
  out = (out * out) % MOD;
  if (e % 2 == 1) {
    out = (out * b) % MOD;
  }
  return out;
}

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", A);
  scanf("%s", B);
  int any = 0;
  for (int i = 0; i < n; i++) {
    if (A[i] == '?' && B[i] == '?') {
      L[i] = 45;
      G[i] = 45;
      E[i] = 10;
    } else if (A[i] == '?') {
      L[i] = B[i] - '0';
      G[i] = '9' - B[i];
      E[i] = 1;
    } else if (B[i] == '?') {
      L[i] = '9' - A[i];
      G[i] = A[i] - '0';
      E[i] = 1;
    } else {
      L[i] = A[i] < B[i];
      G[i] = A[i] > B[i];
      E[i] = A[i] == B[i];
    }
  }
  LE[0] = 1;
  for (int i = 0; i < n; i++) {
    long long k = L[i];
    LE[i+1] = LE[i] * L[i];
    ML[i] = k * pot(10, SI[n] - I[i]);
  }
  ML[0] = MG[0] = 0;
  ME[0] = 1;
  for (int i = 1; i <= n; i++) {
    ML[i] = (ML[i-1] + L[i-1]) % MOD;
    MG[i] = (MG[i-1] + G[i-1]) % MOD;
    ME[i] = (ME[i-1] * E[i-1]) % MOD;
    printf("M -> i = %d, L = %d, G = %d, E = %d\n", i, (int) ML[i], (int) MG[i], (int) ME[i]);
  }
  long long out = 0;

  for (int i = 0; i < n; i++) {
    long long t = G[i];
    t = (t * ML[n]) % MOD;
    t = (t * pot(L[i], MOD-1)) % MOD;
    t = (t * ME[n]) % MOD;
    t = (t * pot(E[i], MOD-1)) % MOD;
    out = (out + t) % MOD;
  }

  int o = out;
  printf("%d\n", o);
  return 0;
}
