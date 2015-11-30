#include <bits/stdc++.h>

using namespace std;

#define NMAX 200010

int A[NMAX];
long long Y2[NMAX], Y3[NMAX];
int n;

long long y2(int x);

long long y3(int x) {
  if (x <= 0 || x > n) {
    return 0;
  }
  if (x == 1) {
    return -1;
  }
  if (Y3[x] != -2) {
    return Y3[x];
  }
  Y3[x] = -1;
  long long rec = y2(x - A[x]);
  if (rec == -1) {
    return Y3[x] = rec;
  }
  return Y3[x] = A[x] + rec;
}

long long y2(int x) {
  if (x <= 0 || x > n) {
    return 0;
  }
  if (x == 1) {
    return -1;
  }
  if (Y2[x] != -2) {
    return Y2[x];
  }
  Y2[x] = -1;
  long long rec = y3(x + A[x]);
  if (rec == -1) {
    return Y2[x] = rec;
  }
  return Y2[x] = A[x] + rec;
}

int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    scanf("%d", &A[i]);
  }
  for (int i = 0; i <= n; i++) {
    Y2[i] = Y3[i] = -2;
  }
  for (int a1 = 1; a1 < n; a1++) {
    long long out = y3(1 + a1);
    printf("%I64d\n", out == -1 ? -1 : out + a1);
  }
  return 0;
}
