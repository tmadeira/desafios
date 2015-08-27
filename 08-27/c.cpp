#include <bits/stdc++.h>

using namespace std;

#define NMAX 512

struct interval {
  int a, b;
};

interval I[NMAX];
vector <int> E[NMAX];
int G[NMAX], D[NMAX], P[NMAX];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &I[i].a, &I[i].b);
  }

  memset(G, 0, sizeof(G));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (I[i].a < I[j].a && I[j].b < I[i].b) {
        E[i].push_back(j);
        G[j]++;
      }
    }
  }

  memset(D, -1, sizeof(D));
  memset(P, -1, sizeof(P));
  queue <int> Q;
  for (int i = 0; i < n; i++) {
    if (G[i] == 0) {
      Q.push(i);
      D[i] = 1;
    }
  }

  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int i = 0; i < E[u].size(); i++) {
      int v = E[u][i];
      if (D[u]+1 > D[v]) {
        D[v] = D[u]+1;
        P[v] = u;
      }
      G[v]--;
      if (G[v] == 0) {
        Q.push(v);
      }
    }
  }

  int m = 0;
  for (int i = 0; i < n; i++) {
    if (D[i] > D[m]) {
      m = i;
    }
  }

  vector <int> output;
  while (m != -1) {
    output.push_back(m+1);
    m = P[m];
  }

  printf("%d\n", output.size());
  for (int i = 0; i < output.size(); i++) {
    printf("%d%c", output[i], (i == output.size()-1 ? '\n' : ' '));
  }

  return 0;
}
