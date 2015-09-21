#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
typedef unsigned long long llu;

#define N 50010
#define K 16

vector <int> E[N];
vector <int> W[N];
int M[N];

int pai[N][K], distancia[N][K], prof[N];

void monta(int v, int p, int pro, int d) {
  prof[v] = pro;
  pai[v][0] = p;
  distancia[v][0] = d;
  for(int i = 1; i < K; i++) {
    pai[v][i] = pai[ pai[v][i-1] ] [i-1];
    distancia[v][i] = distancia[v][i-1] + distancia[ pai[v][i-1] ][i-1];
  }
  for (int i = 0; i < E[v].size(); i++) {
    if (E[v][i] == p) continue;
    monta(E[v][i], v, pro+1, W[v][i]);
  }
}

void calc() {
  prof[0] = 0;
  for (int i = 0; i < K; i++) {
    pai[0][i] = 0;
    distancia[0][i] = 0;
  }
  for (int i = 0; i < E[0].size(); i++) {
    monta(E[0][i], 0, 1, W[0][i]);
  }
}

int dist(int a, int b) {
  int pa = a, pb = b, d = 0;
  if(prof[pb] > prof[pa]) swap(pa, pb);
  while(prof[pa] > prof[pb]) {
    int j = 0;
    for (int i = 0; i < K; i++) {
      if(prof[ pai[pa][i] ] < prof[pb]) break;
      j = i;
    }
    d += distancia[pa][j];
    pa = pai[pa][j];
  }
  while(pa != pb) {
    int j = 0;
    for (int i = 0; i < K; i++) {
      if(pai[pa][i] == pai[pb][i]) break;
      j = i;
    }
    d += distancia[pa][j];
    d += distancia[pb][j];
    pa = pai[pa][j];
    pb = pai[pb][j];
  }
  return d;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n-1; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    E[u].push_back(v);
    W[u].push_back(w);
    E[v].push_back(u);
    W[v].push_back(w);
  }
  srand(time(NULL));
  memset(M, -1, sizeof(M));
  queue <int> Q;
  Q.push(0);
  M[0] = 0;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    M[u] = 0;
    for (int i = 0; i < E[u].size(); i++) {
      int v = E[u][i];
      if (M[v] < 0) {
        M[v] = M[u] + W[u][i];
        Q.push(v);
      }
    }
  }
  calc();

  int m;
  scanf("%d", &m);
  for (int k = 0; k < m; k++) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", dist(a, b));
  }
  return 0;
}
