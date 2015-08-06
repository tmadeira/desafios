#include <bits/stdc++.h>
using namespace std;

int main() {
  int p, q, l, r;
  int M[4096], C[50], D[50];
  scanf("%d %d %d %d", &p, &q, &l, &r);
  memset(M, 0, sizeof(M));
  for (int i = 0; i < p; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    for (int j = a; j <= b; j++) {
      M[j] = 1;
    }
  }
  for (int i = 0; i < q; i++) {
    scanf("%d %d", C+i, D+i);
  }
  int count = 0;
  for (int t = l; t <= r; t++) {
    int ok = 0;
    for (int j = 0; j < q && !ok; j++) {
      for (int k = C[j]+t; k <= D[j]+t && !ok; k++) {
        if (M[k]) {
          ok = 1;
        }
      }
    }
    count += ok;
  }
  printf("%d\n", count);
  return 0;
}
