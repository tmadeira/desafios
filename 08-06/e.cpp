#include <bits/stdc++.h>
int main() {
  unsigned long long a, start, delta = 10000000000000000000ull - 1;
  scanf("%I64u", &a);
  start = a - (19 * (45 * (1000000000000000000ull % a) % a)) % a;
  printf("%I64u %I64u\n", start, start+delta);
  return 0;
}
