#include <bits/stdc++.h>

using namespace std;

#define WHITE 0
#define BLUE_AFTER_WHITE 1
#define BLUE_AFTER_RED 2
#define RED 3

typedef long long lld;

lld PD[64][4];

lld f(int n, int l) {
  if (n == 0) {
    if (l == WHITE || l == RED) {
      return 1;
    } else {
      return 0;
    }
  }
  if (l != -1 && PD[n][l] != -1) {
    return PD[n][l];
  }
  lld r = 0;
  switch (l) {
    case WHITE:
      r += f(n-1, BLUE_AFTER_WHITE);
      r += f(n-1, RED);
      break;
    case RED:
      r += f(n-1, BLUE_AFTER_RED);
      r += f(n-1, WHITE);
      break;
    case BLUE_AFTER_WHITE:
      r += f(n-1, RED);
      break;
    case BLUE_AFTER_RED:
      r += f(n-1, WHITE);
      break;
    default:
      r += f(n-1, WHITE);
      r += f(n-1, RED);
      break;
  }
  return PD[n][l] = r;
}

int main() {
  int n;
  memset(PD, -1, sizeof(PD));
  scanf("%d", &n);
  printf("%lld\n", f(n, -1));
  return 0;
}
