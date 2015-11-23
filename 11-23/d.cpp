#include <bits/stdc++.h>
using namespace std;
#define NMAX 256
vector <int> E[NMAX], I[NMAX];
int n;
int D[NMAX], D2[NMAX];
int bfs(int block) {
  memset(D, -1, sizeof(D));
  memset(D2, -1, sizeof(D2));
  vector <int> out;
  for (int k = 0; k < n; k++) {
    if (D[k] == -1) {
      queue <int> Q;

      int last = 0;
      D[k] = 0;
      Q.push(k);
      while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        last = u;
        for (int i = 0; i < E[u].size(); i++) {
          int v = E[u][i];
          if (I[u][i] != block && D[v] == -1) {
            D[v] = D[u] + 1;
            Q.push(v);
          }
        }
      }

      int m = 0;
      D2[last] = 0;
      Q.push(last);
      while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        m = max(m, D2[u]);
        for (int i = 0; i < E[u].size(); i++) {
          int v = E[u][i];
          if (I[u][i] != block && D2[v] == -1) {
            D2[v] = D2[u] + 1;
            Q.push(v);
          }
        }
      }

      out.push_back(m);
    }
  }
  if (out.size() > 1) {
    sort(out.begin(), out.end());
    return out[out.size() - 1] * out[out.size() - 2];
  }
  return 0;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    E[u].push_back(v);
    I[u].push_back(i);
    E[v].push_back(u);
    I[v].push_back(i);
  }
  int out = 0;
  for (int i = 0; i < n-1; i++) {
    out = max(out, bfs(i));
  }
  printf("%d\n", out);
  return 0;
}
