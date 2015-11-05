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
  int n, k;
  while (scanf("%d %d", &n, &k) && (n || k)) {
    a = b = 0;
    for (int i = 0; i < n; i++) {
      int l;
      scanf("%d", &l);
      if (l % 2 == 0) {
        Ea[a].clear();
        A[a++] = l;
      } else {
        B[b++] = l;
      }
    }
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        if (abs(A[i] - B[j]) <= k) {
          Ea[i].push_back(j);
        }
      }
    }
    printf("%d\n", emp_max());
  }
  return 0;
}
