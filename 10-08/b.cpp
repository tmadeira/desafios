#include <bits/stdc++.h>

using namespace std;

#define NMAX 100100

set <int> E[NMAX];
int M[NMAX];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    E[a].insert(b);
    E[b].insert(a);
  }
  queue <int> Q;
  for (int i = 0; i < n; i++) {
    if (E[i].size() == 1) {
      Q.push(i);
    }
  }
  memset(M, 0, sizeof(M));
  vector < pair<int,int> > O;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();

    if (M[u]) {
      continue;
    }

    int v = *(E[u].begin());
    if (M[v]) {
      continue;
    }

    O.push_back(make_pair(u+1, v+1));
    M[u] = M[v] = 1;

    for (set<int>::iterator it = E[v].begin(); it != E[v].end(); it++) {
      set<int>::iterator jit = E[*it].find(v);
      if (jit != E[*it].end()) {
        E[*it].erase(jit);
        if (E[*it].size() == 1) {
          Q.push(*it);
        }
      }
    }
  }
  for (int i = 0; i < O.size(); i++) {
    if (O[i].first > O[i].second) {
      swap(O[i].first, O[i].second);
    }
  }
  sort(O.begin(), O.end());
  printf("%d\n", O.size());
  for (int i = 0; i < O.size(); i++) {
    printf("%d %d\n", O[i].first, O[i].second);
  }
  return 0;
}
