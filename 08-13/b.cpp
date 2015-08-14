#include <bits/stdc++.h>
using namespace std;
#define NMAX 200000
int main() {
  int M[NMAX];
  vector <int> A;
  memset(M, 0, sizeof(M));
  for (int i = 2; i < NMAX; i++) {
    if (!M[i]) {
      A.push_back(i);
      for (int j = 2*i; j < NMAX; j+= i) {
        M[j] = 1;
      }
    }
  }
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    printf("%d\n", A[k-1]);
  }
  return 0;
}
