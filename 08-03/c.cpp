#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n, m;
  string A[128];
  int D[128];

  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  int o = 0;
  while (1) {
    memset(D, 0, sizeof(D));
    bool good = 1;
    for (int i = 0; i < n-1; i++) {
      if (A[i] <= A[i+1]) {
        D[i] = 1;
      } else {
        good = 0;
      }
    }

    if (good) {
      printf("%d\n", o);
      return 0;
    }

    for (int k = 0; k < A[0].size(); k++) {
      for (int i = 0; i < n-1; i++) {
        if (!D[i] && A[i][k] > A[i+1][k]) {
          for (int j = 0; j < n; j++) {
            A[j].erase(A[j].begin()+k);
          }
          i = n;
          k = A[0].size();
        }
      }
    }
    o++;
  }
}
