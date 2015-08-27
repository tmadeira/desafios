#include <bits/stdc++.h>

using namespace std;

#define NMAX 8192

char A[NMAX];
int n;
vector <string> V;

int lcp(string a, string b) {
  int m = min(a.size(), b.size());
  for (int i = 0; i < m; i++) {
    if (a[i] != b[i]) {
      return i;
    }
  }
  return m;
}

int main() {
  scanf("%s", A);
  n = strlen(A);
  for (int i = 0; i < n; i++) {
    V.push_back(A+i);
  }
  sort(V.begin(), V.end());
  int res = V[0].size();
  for (int i = 1; i < V.size(); i++) {
    res += V[i].size() - lcp(V[i-1], V[i]);
  }
  printf("%d\n", res);
  return 0;
}
