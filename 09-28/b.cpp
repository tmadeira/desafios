#include <bits/stdc++.h>

using namespace std;

#define NMAX 128

int D[NMAX], P[NMAX];
vector <int> sol[NMAX];
int G[NMAX][NMAX];
int FP[NMAX];
int C[NMAX];

struct st {
  int v, c;
  bool operator < (const st &s) const {
    return c > s.c;
  }
};

int main() {
  int n;
  while (scanf("%d", &n) && n != -1) {
    memset(G, -1, sizeof(G));
    int m;
    vector <int> E[NMAX], W[NMAX];
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      a--;
      b--;
      E[a].push_back(b);
      W[a].push_back(c);
      E[b].push_back(a);
      W[b].push_back(c);
      if (G[a][b] == -1 || G[a][b] > c) {
        G[a][b] = G[b][a] = c;
      }
    }
    int minc = -1;
    for (int s = 0; s < n; s++) {
      sol[s].clear();
      memset(D, -1, sizeof(D));
      priority_queue <st> Q;
      st first = { s, 0 };
      D[s] = 0;
      Q.push(first);
      while (!Q.empty()) {
        int u = (Q.top()).v;
        Q.pop();
        for (int i = 0; i < E[u].size(); i++) {
          int v = E[u][i], w = W[u][i];
          if (D[v] == -1 || D[v] > D[u] + w) {
            D[v] = D[u] + w;
            P[v] = u;
            if (u == s) {
              FP[v] = v;
            } else {
              FP[v] = FP[u];
            }
            st act = { v, D[v] };
            Q.push(act);
          }
        }
      }
      int mmin = -1, mi, mj;
      for (int i = 0; i < n; i++) {
        if (i == s) {
          continue;
        }
        for (int j = i+1; j < n; j++) {
          if (j == s) {
            continue;
          }
          if (D[i] != -1 && D[j] != -1 && FP[i] != FP[j] && G[i][j] != -1) {
            int c = D[i]+D[j]+G[i][j];
            if (mmin == -1 || c < mmin) {
              mi = i;
              mj = j;
              mmin = c;
            }
          }
        }
      }
      if (mmin != -1) {
        for (int i = mi; i != s; i = P[i]) {
          sol[s].push_back(i+1);
        }
        sol[s].push_back(s+1);
        reverse(sol[s].begin(), sol[s].end());
        for (int j = mj; j != s; j = P[j]) {
          sol[s].push_back(j+1);
        }
        C[s] = mmin;
        if (minc == -1 || C[s] < C[minc]) {
          minc = s;
        }
      }
    }
    if (minc == -1) {
      printf("No solution.\n");
    } else {
      for (int i = 0; i < sol[minc].size(); i++) {
        printf("%d ", sol[minc][i]);
      }
      printf("\n");
    }
  }
  return 0;
}
