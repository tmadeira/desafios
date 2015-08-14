#include <bits/stdc++.h>
using namespace std;

#define NMAX 16384

int B[NMAX];
int E[NMAX];
char C[NMAX];

int A[NMAX];

int main() {
  int n;
  scanf("%d", &n);
  set <int> positions;
  for (int i = 0; i < n; i++) {
    scanf("%d %d %c", B+i, E+i, C+i);
    positions.insert(B[i]);
    positions.insert(E[i]);
  }
  positions.insert(0);
  positions.insert(1e9);
  int m = 0;
  map <int,int> inv;
  for (set<int>::iterator it = positions.begin(); it != positions.end(); it++) {
    inv[*it] = m;
    A[m++] = *it;
  }
  char X[m];
  memset(X, 'w', m);
  X[m-1] = 'b';
  for (int i = 0; i < n; i++) {
    int b = inv[B[i]];
    int e = inv[E[i]];
    memset(X+b, C[i], e-b);
  }
  int o1 = 0, o2 = 0;
  for (int i = 0; i < m; i++) {
    if (X[i] == 'w') {
      int j;
      for (j = i+1; j < m && X[j] == 'w'; j++);
      if (A[j]-A[i] > o2-o1) {
        o1 = A[i];
        o2 = A[j];
      }
      i = j;
    }
  }
  printf("%d %d\n", o1, o2);
  return 0;
}
