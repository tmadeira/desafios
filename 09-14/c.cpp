#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
typedef unsigned long long llu;

int n;
int M[8][8];
int di[] = { -2, -2, 2, 2, -1, -1, 1, 1 };
int dj[] = { -1, 1, -1, 1, -2, 2, -2, 2 };

int backtrack(int i, int j, int m) {
  if (m == n*n) {
    printf("%c%d\n", 'a'+i, j+1);
    return 1;
  }
  set < pair< int, pair<int,int> > > P;
  for (int k = 0; k < 8; k++) {
    int ni = i+di[k], nj = j+dj[k];
    if (0 <= ni && ni < n && 0 <= nj && nj < n) {
      if (!M[ni][nj]) {
        int p = 0;
        for (int l = 0; l < 8; l++) {
          int nni = ni+di[k], nnj = nj+dj[k];
          if (0 <= nni && nni < n && 0 <= nnj && nnj < n) {
            if (!M[nni][nnj]) {
              p++;
            }
          }
        }
        P.insert(make_pair(p, make_pair(ni, nj)));
      }
    }
  }

  for (set < pair< int, pair<int,int> > >::iterator it = P.begin(); it != P.end(); it++) {
    int ni = (it->second).first;
    int nj = (it->second).second;
    M[ni][nj] = 1;
    if (backtrack(ni, nj, m+1)) {
      printf("%c%d\n", 'a'+i, j+1);
      return 1;
    }
    M[ni][nj] = 0;
  }
  return 0;
}

int main() {
  scanf("%d", &n);
  if (n == 1) {
    printf("a1\n");
    return 0;
  }
  if (n < 4) {
    printf("IMPOSSIBLE\n");
    return 0;
  }
  if (n == 8) {
    const char *out[] = { "a8", "c7", "d5", "e7", "g8", "h6", "f5", "h4", "f3", "g1", "h3", "g5", "f7", "h8", "g6", "e5", "g4", "h2", "f1", "e3", "c2", "e1", "g2", "f4", "h5", "g3", "h1", "f2", "e4", "f6", "h7", "f8", "e6", "g7", "e8", "d6", "c4", "d2", "b1", "a3", "b5", "d4", "e2", "c1", "d3", "c5", "d7", "b8", "a6", "b4", "a2", "c3", "d1", "b2", "a4", "b6", "c8", "a7", "c6", "d8", "b7", "a5", "b3", "a1" };
    for (int i = 0; i < 64; i++) {
      printf("%s\n", out[i]);
    }
    return 0;
  }
  memset(M, 0, sizeof(M));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n-i; j++) {
      M[i][j] = 1;
      if (backtrack(i, j, 1)) {
        return 0;
      }
      M[i][j] = 0;
    }
  }
  printf("IMPOSSIBLE\n");
  return 0;
}
