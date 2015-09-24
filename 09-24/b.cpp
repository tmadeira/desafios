#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
typedef unsigned long long llu;

#define DMAX 512

char A[DMAX][DMAX];
pair <int,int> M[DMAX][DMAX];

struct st {
  int i, j;
  int boot_dist, walk_dist;
  bool operator < (const st &s) const {
    return make_pair(boot_dist, walk_dist) > make_pair(s.boot_dist, s.walk_dist);
  }
};

int di[] = { -1, 1, 0, 0, -1, 1, -1, 1 };
int dj[] = { 0, 0, 1, -1, -1, 1, 1, -1 };

int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  int si, sj;
  scanf("%d %d", &si, &sj);
  si--; sj--;
  int ti, tj;
  scanf("%d %d", &ti, &tj);
  ti--; tj--;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf(" %c", &A[i][j]);
      M[i][j] = make_pair(-1, -1);
    }
  }
  priority_queue <st> Q;
  st s = { si, sj, 0, 0 };
  M[si][sj] = make_pair(0, 0);
  Q.push(s);
  while (!Q.empty()) {
    st u = Q.top();
    Q.pop();
    if (u.i == ti && u.j == tj) {
      printf("%d %d\n", u.walk_dist+1, u.boot_dist);
      return 0;
    }
    for (int d = 0; d < 8; d++) {
      int ni = u.i + di[d];
      int nj = u.j + dj[d];
      if (0 <= ni && ni < m && 0 <= nj && nj < n && A[ni][nj] != '0') {
        int change = (A[u.i][u.j] != A[ni][nj] ? 1 : 0);
        pair <int,int> np = make_pair(u.boot_dist+change, u.walk_dist+1);
        if (M[ni][nj].first == -1 || np < M[ni][nj]) {
          M[ni][nj] = np;
          st v = { ni, nj, np.first, np.second };
          Q.push(v);
        }
      }
    }
  }
  printf("0 0\n");
  return 0;
}
