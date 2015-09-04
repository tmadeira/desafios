#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
typedef unsigned long long llu;

int PD[32][1024], X[32][1024];
int D[32], W[32], V[32];

int f(int n, int w) {
  if (n == 0) {
    return 0;
  }
  if (PD[n][w] != -1) {
    return PD[n][w];
  }
  PD[n][w] = f(n-1, w);
  if (w >= W[n-1]) {
    int t = V[n-1] + f(n-1, w-W[n-1]);
    if (t > PD[n][w]) {
      PD[n][w] = t;
      X[n][w] = 1;
    }
  }
  return PD[n][w];
}

vector <int> outs;

void output(int n, int w) {
  if (n == 0) {
    return;
  }
  if (X[n][w]) {
    output(n-1, w-W[n-1]);
    outs.push_back(n-1);
  } else {
    output(n-1, w);
  }
}

int main() {
  int w, k;
  int first = 1;
  while (scanf("%d %d", &w, &k) != EOF) {
    if (!first) {
      printf("\n");
    }
    first = 0;
    int n;
    memset(PD, -1, sizeof(PD));
    memset(X, 0, sizeof(X));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d", D+i, V+i);
      W[i] = k*D[i] + 2*k*D[i];
    }
    printf("%d\n", f(n, w));
    outs.clear();
    output(n, w);
    printf("%d\n", outs.size());
    for (int i = 0; i < outs.size(); i++) {
      printf("%d %d\n", D[outs[i]], V[outs[i]]);
    }
  }
  return 0;
}
