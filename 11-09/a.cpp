#include <bits/stdc++.h>

using namespace std;

#define NMAX 128

int n;
int G[NMAX][NMAX];
int Ma[NMAX], Mb[NMAX];
int Pa[NMAX], Pb[NMAX];
int ma, mb;
int y[NMAX], z[NMAX];
int d[NMAX];
int S[NMAX], T[NMAX];

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
  for (int j = 0; j < n; j++) {
    d[j] = min(d[j], y[i] + z[j] - G[i][j]);
  }
}

void atualiza_dual() {
  int delta = 1<<30;
  for (int j = 0; j < n; j++) {
    if (!T[j]) {
      delta = min(delta, d[j]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (S[i]) {
      y[i] -= delta;
    }
  }
  for (int j = 0; j < n; j++) {
    if (T[j]) {
      z[j] += delta;
    } else {
      d[j] -= delta;
    }
  }
}

void hungarian() {
  init();

  while (ma < n) {
    int i = -1;
    for (int k = 0; i == -1; k++) {
      if (Ma[k] == -1) {
        i = k;
      }
    }

    memset(S, 0, sizeof(S));
    memset(T, 0, sizeof(T));
    S[i] = 1;
    Pa[i] = -1;
    queue <int> sq;
    sq.push(i);

    for (int j = 0; j < n; j++) {
      d[j] = 1<<30;
    }
    atualiza_d(i);

    while (1) {
      int j = -1;
      while (!sq.empty() && j == -1) {
        int u = sq.front();
        sq.pop();
        for (int v = 0; v < n; v++) {
          if (!T[v] && G[u][v] == y[u] + z[v]) {
            j = v;
            Pb[j] = u;
            break;
          }
        }
      }
      if (j == -1) {
        atualiza_dual();
        while (!sq.empty()) {
          sq.pop();
        }
        for (int u = 0; u < n; u++) {
          if (S[u]) {
            sq.push(u);
          }
        }
      } else {
        if (Mb[j] == -1) {
          while (j != -1) {
            Mb[j] = Pb[j];
            Ma[Pb[j]] = j;
            j = Pa[Pb[j]];
          }
          ma++;
          break;
        } else {
          T[j] = 1;
          if (!S[Mb[j]]) {
            Pa[Mb[j]] = j;
            S[Mb[j]] = 1;
            sq.push(Mb[j]);
            atualiza_d(Mb[j]);
          }
        }
      }
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

  int A[NMAX], B[NMAX];
  memset(B, 0, sizeof(B));
  for (int i = 0; i < n; i++) {
    A[i] = G[i][Ma[i]];
  }

  int some = 1;
  while (some) {
    some = 0;
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < n; i++) {
        if (B[j] < G[i][j]-A[i]) {
          some = 1;
          B[j] = (G[i][j]-A[i]);
          A[Mb[j]] = G[Mb[j]][j] - B[j];
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", B[i]);
  }
  printf("\n");

  return 0;
}
