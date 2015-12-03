#include <bits/stdc++.h>

using namespace std;

#define NMAX 100010
#define MOD ((long long) 1e9+7)

char A[NMAX];
char B[NMAX];

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

  long long o1 = 1;
  for (int i = 0; i < n; i++) {
    if (A[i] == '?' && B[i] == '?') {
      o1 *= 55;
    } else if (A[i] == '?') {
      o1 *= (B[i] - '0' + 1);
    } else if (B[i] == '?') {
      o1 *= ('9' - A[i] + 1);
    } else {
      o1 *= (A[i] <= B[i]);
    }
    o1 %= MOD;
  }
  long long o2 = 1;
  for (int i = 0; i < n; i++) {
    if (B[i] == '?' && A[i] == '?') {
      o2 *= 55;
    } else if (B[i] == '?') {
      o2 *= (A[i] - '0' + 1);
    } else if (A[i] == '?') {
      o2 *= ('9' - B[i] + 1);
    } else {
      o2 *= (B[i] <= A[i]);
    }
    o2 %= MOD;
  }
  long long o3 = 1;
  for (int i = 0; i < n; i++) {
    if (B[i] == '?' && A[i] == '?') {
      o3 *= 10;
    } else if (B[i] == '?') {
      o3 *= 1;
    } else if (A[i] == '?') {
      o3 *= 1;
    } else {
      o3 *= A[i] == B[i];
    }
    o3 %= MOD;
  }

  int inter = 0;
  for (int i = 0; i < n; i++) {
    if (A[i] == '?') {
      inter++;
    }
    if (B[i] == '?') {
      inter++;
    }
  }

  long long com = ((o1 + o2 - o3) % MOD + MOD) % MOD;
  long long out = ((pot(10, inter) - com) % MOD + MOD) % MOD;
  int o = out;
  printf("%d\n", o);
  return 0;
}
