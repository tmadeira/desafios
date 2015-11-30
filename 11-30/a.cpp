#include <bits/stdc++.h>

using namespace std;

int main() {
  int p;
  scanf("%d", &p);
  int count = 0;
  for (int i = 1; i <= p; i++) {
    int po = 1;
    int ok = 1;
    for (int e = 1; e < p-1 && ok; e++) {
      po *= i;
      po %= p;
      if (po - 1 == 0) {
        ok = 0;
      }
    }
    po *= i;
    po %= p;
    if (ok && po - 1 == 0) {
      count++;
    }
  }
  printf("%d\n", count);
  return 0;
}
