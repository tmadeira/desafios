#include <bits/stdc++.h>

using namespace std;

#define NMAX 128

int n, m;
char A[NMAX][NMAX];

int main() {
  scanf("%d %d", &n, &m);
  map <int,int> I, J;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf(" %c", &A[i][j]);
      if (A[i][j] == '*') {
        I[i]++;
        J[j]++;
      }
    }
  }
  int i, j;
  for (map<int,int>::iterator it = I.begin(); it != I.end(); it++) {
    if (it->second == 1) {
      i = it->first;
    }
  }
  for (map<int,int>::iterator it = J.begin(); it != J.end(); it++) {
    if (it->second == 1) {
      j = it->first;
    }
  }
  printf("%d %d\n", i+1, j+1);
  return 0;
}
