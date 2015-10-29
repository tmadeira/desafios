#include <bits/stdc++.h>

using namespace std;

#define NMAX 150

int n;
int G[NMAX][NMAX];
int Ma[NMAX], Mb[NMAX];
int ma, mb;
int y[NMAX], z[NMAX];
int d[NMAX];

void init() {
  memset(Ma, -1, sizeof(Ma));
  memset(Mb, -1, sizeof(Mb));
  ma = mb = 0;
  for (int i = 0; i < n; i++) {
    y[i] = z[i] = 0;
    for (int j = 0; j < n; j++) {
      y[i] = max(y[i], G[i][j]);
    }
  }
}

void atualiza_d(int i) {
}

void hungarian() {
  init();
  for (int i = 0; i < n; i++) {
    set <int> S, T;
    S.insert(i);

    for (int j = 0; j < n; j++) {
      d[j] = y[i] + z[j] - G[i][j];
    }

    while (1) {
      // TODO
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &G[i][j]);
    }
  }

  hungarian();
  return 0;
}
