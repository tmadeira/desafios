#include <bits/stdc++.h>

using namespace std;

#define NMAX 512

int G[NMAX][NMAX];
int O[NMAX], M[NMAX];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &G[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &O[n-1-i]);
    O[n-1-i]--;
  }
  memset(M, 0, sizeof(M));
  vector <long long> V;
  for (int k = 0; k < n; k++) {
    long long out = 0;
    M[O[k]] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        G[i][j] = min(G[i][j], G[i][O[k]] + G[O[k]][j]);
        if (M[i] && M[j]) {
          out += G[i][j];
        }
      }
    }
    V.push_back(out);
  }
  for (int i = V.size() - 1; i >= 0; i--) {
    printf("%I64d ", V[i]);
  }
  printf("\n");
  return 0;
}
