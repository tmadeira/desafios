#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
typedef unsigned long long llu;

map <string,int> F;
vector <int> G[512];
int c;
int M[512];

int insert(string s) {
  if (F.find(s) == F.end()) {
    F[s] = c++;
  }
  return F[s];
}

int main() {
  int n;
  scanf("%d", &n);
  c = 0;
  for (int i = 0; i < n; i++) {
    char a[32], b[32], c[32];
    scanf("%s %s %s", a, b, c);
    int ax = insert(a);
    int bx = insert(b);
    int cx = insert(c);
    G[ax].push_back(bx);
    G[bx].push_back(ax);
    G[ax].push_back(cx);
    G[cx].push_back(ax);
    G[bx].push_back(cx);
    G[cx].push_back(bx);
  }
  queue <int> Q;
  memset(M, -1, sizeof(M));
  if (F.find("Isenbaev") != F.end()) {
    M[F["Isenbaev"]] = 0;
    Q.push(F["Isenbaev"]);
  }
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (M[v] == -1) {
        M[v] = M[u] + 1;
        Q.push(v);
      }
    }
  }
  for (map<string,int>::iterator it = F.begin(); it != F.end(); it++) {
    printf("%s", it->first.c_str());
    if (M[it->second] == -1) {
      printf(" undefined\n");
    } else {
      printf(" %d\n", M[it->second]);
    }
  }
  return 0;
}
