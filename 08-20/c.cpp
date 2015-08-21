#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  while (scanf("%d %d", &n, &m) && n) {
    map < int, vector<int> > E;
    int D[n];
    memset(D, 0, sizeof(int)*n);
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--;
      v--;
      E[u].push_back(v);
      D[v]++;
    }
    queue <int> Q;
    for (int i = 0; i < n; i++) {
      if (D[i] == 0) {
        Q.push(i);
      }
    }
    vector <int> output;
    while (!Q.empty()) {
      int u = Q.front();
      output.push_back(u);
      Q.pop();
      for (int i = 0; i < E[u].size(); i++) {
        int v = E[u][i];
        D[v]--;
        if (D[v] == 0) {
          Q.push(v);
        }
      }
    }
    if (output.size() != n) {
      printf("IMPOSSIBLE\n");
    } else {
      for (int i = 0; i < n; i++) {
        printf("%d\n", output[i]+1);
      }
    }
  }
  return 0;
}
