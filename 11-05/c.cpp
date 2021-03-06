#include <bits/stdc++.h>

using namespace std;

#define NMAX 128

int a, b;

vector <int> Ea[NMAX];
int Ma[NMAX], Mb[NMAX];
int U[NMAX], V[NMAX];

int tem_aumento(int u) {
  U[u] = 1;
  for (int i = 0; i < Ea[u].size(); i++) {
    int v = Ea[u][i];
    if (!V[v]) {
      V[v] = 1;
      if (Mb[v] == -1 || tem_aumento(Mb[v])) {
        Ma[u] = v;
        Mb[v] = u;
        return 1;
      }
    }
  }
  return 0;
}

int emp_max() {
  memset(Ma, -1, sizeof(Ma));
  memset(Mb, -1, sizeof(Mb));
  for (int i = 0; i < a; i++) {
    memset(V, 0, sizeof(V));
    tem_aumento(i);
  }
  int out = 0;
  for (int i = 0; i < a; i++) {
    if (Ma[i] != -1) {
      out++;
    }
  }
  return out;
}

int main() {
  int n;
  scanf("%d", &n);
  int G[NMAX][NMAX];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &G[i][j]);
    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (G[i][k] && G[k][j]) {
          G[i][j] = 1;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (G[i][j]) {
        Ea[i].push_back(j);
      }
    }
  }
  a = b = n;
  emp_max();
  memset(U, 0, sizeof(U));
  memset(V, 0, sizeof(V));
  for (int i = 0; i < n; i++) {
    if (Ma[i] == -1) {
      tem_aumento(i);
    }
  }
  vector <int> out;
  for (int i = 0; i < n; i++) {
    if (U[i] && !V[i]) {
      out.push_back(i+1);
    }
  }
  printf("%d\n", out.size());
  for (int i = 0; i < out.size(); i++) {
    printf("%d ", out[i]);
  }
  printf("\n");
  return 0;
}
