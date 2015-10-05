#include <bits/stdc++.h>

using namespace std;

#define NMAX 128

vector <int> E[NMAX];
int M[NMAX];
int C[NMAX];
int imp = 0;
int pos;

void dfs(int u) {
  for (int i = 0; i < E[u].size(); i++) {
    int v = E[u][i];
    if (M[v] == -1) {
      M[v] = (M[u] % 2 == 1 ? pos : pos+1);
      dfs(v);
    }
    if (M[v] == M[u]) {
      imp = 1;
    }
  }
}

int PD[NMAX][NMAX];
int S[NMAX][NMAX];
int O[NMAX];
int n, m;

int f(int goal, int c) {
  if (c == 0) {
    if (goal == 0) {
      return 1;
    } else {
      return 0;
    }
  }

  if (PD[goal][c] != -1) {
    return PD[goal][c];
  }

  // uso c-1
  int a = goal >= C[c-1] ? f(goal-C[c-1], c-2) : 0;

  // uso c-2
  int b = goal >= C[c-2] ? f(goal-C[c-2], c-2) : 0;

  if (a) {
    S[goal][c] = -1;
    return PD[goal][c] = 1;
  }

  if (b) {
    S[goal][c] = -2;
    return PD[goal][c] = 1;
  }

  return PD[goal][c] = 0;
}

int reconstruct(int goal, int c) {
  if (S[goal][c] == -1) {
    for (int i = 0; i < n; i++) {
      if (M[i] == c-1) {
        O[i] = 1;
      }
    }
    reconstruct(goal-C[c-1], c-2);
  } else if (S[goal][c] == -2) {
    for (int i = 0; i < n; i++) {
      if (M[i] == c-2) {
        O[i] = 1;
      }
    }
    reconstruct(goal-C[c-2], c-2);
  }
}

int main() {
  scanf("%d %d", &n, &m);
  n *= 2;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  memset(M, -1, sizeof(M));
  pos = 0;
  for (int i = 0; i < n; i++) {
    if (M[i] == -1) {
      M[i] = pos;
      dfs(i);
      pos += 2;
    }
  }

  int mc = 0;
  if (!imp) {
    memset(PD, -1, sizeof(PD));
    memset(C, 0, sizeof(C));
    for (int i = 0; i < n; i++) {
      C[M[i]]++;
      mc = max(mc, M[i]+1);
    }

    if (mc % 2 == 1) {
      mc++;
    }

    if (!f(n/2, mc)) {
      imp = 1;
    }
  }

  if (imp) {
    printf("IMPOSSIBLE\n");
  } else {
    memset(O, 0, sizeof(O));
    reconstruct(n/2, mc);
    for (int i = 0; i < n; i++) {
      if (O[i]) {
        printf("%d ", i+1);
      }
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
      if (!O[i]) {
        printf("%d ", i+1);
      }
    }
    printf("\n");
  }
  return 0;
}
