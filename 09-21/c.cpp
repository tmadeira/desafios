#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
typedef unsigned long long llu;

vector <int> E[1024], F[1024];
int M1[1024], M2[1024];

int main() {
  int n;
  scanf("%d\n", &n);
  char line[128];
  while (fgets(line, 128, stdin) && strcmp(line, "BLOOD\n") != 0) {
    int u, v;
    sscanf(line, "%d %d", &u, &v);
    u--;
    v--;
    E[u].push_back(v);
    F[v].push_back(u);
  }

  memset(M1, 0, sizeof(M1));
  memset(M2, 0, sizeof(M2));

  queue <int> Q1, Q2;
  int victim;
  while (scanf("%d", &victim) != EOF) {
    victim--;
    Q1.push(victim);
    Q2.push(victim);
    M1[victim] = 1;
    M2[victim] = 1;
  }

  while (!Q1.empty()) {
    int u = Q1.front();
    Q1.pop();
    for (int i = 0; i < E[u].size(); i++) {
      int v = E[u][i];
      if (!M1[v]) {
        M1[v] = 1;
        Q1.push(v);
      }
    }
  }
  while (!Q2.empty()) {
    int u = Q2.front();
    Q2.pop();
    for (int i = 0; i < F[u].size(); i++) {
      int v = F[u][i];
      if (!M2[v]) {
        M2[v] = 1;
        Q2.push(v);
      }
    }
  }
  
  int first = 1;
  for (int i = 0; i < n; i++) {
    if (!M1[i] && !M2[i]) {
      if (!first) {
        printf(" ");
      }
      first = 0;
      printf("%d", i+1);
    }
  }
  if (first) {
    printf("0");
  }
  printf("\n");

  return 0;
}
