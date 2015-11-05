#include <bits/stdc++.h>

using namespace std;

#define NMAX 512

int A[NMAX], B[NMAX];
int a, b;

vector <int> Ea[NMAX];
int Ma[NMAX], Mb[NMAX];
int V[NMAX];

int tem_aumento(int u) {
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
  int tests;
  scanf("%d", &tests);
  for (int test = 1; test <= tests; test++) {
    scanf("%d", &a);
    for (int i = 0; i < a; i++) {
      scanf("%d", A+i);
      Ea[i].clear();
    }
    scanf("%d", &b);
    for (int i = 0; i < b; i++) {
      scanf("%d", B+i);
    }
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        if (A[i] == 0) {
          if (B[j] == 0) {
            Ea[i].push_back(j);
          }
        } else {
          if (B[j] % A[i] == 0) {
            Ea[i].push_back(j);
          }
        }
      }
    }
    printf("Case %d: %d\n", test, emp_max());
  }
  return 0;
}
