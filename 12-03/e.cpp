#include <bits/stdc++.h>

using namespace std;

#define MOD ((int) 1e9+7)
#define NMAX 64
#define BMAX 2

int k, n1, n2;
int D[NMAX][NMAX][BMAX];
long long T[NMAX][NMAX][BMAX];
long long C[NMAX][NMAX];

#define make_triple(a,b,c) make_pair(make_pair((a),(b)),(c))
#define i0 first.first
#define i1 first.second
#define i2 second
typedef pair<pair<int,int>,int> triple;

long long comb(int n, int k) {
  if (C[n][k] != -1) {
    return C[n][k];
  }
  if (k == 0) {
    return C[n][k] = 1;
  }
  if (k > n) {
    return C[n][k] = 0;
  }
  return C[n][k] = (comb(n-1, k-1) + comb(n-1, k)) % MOD;
}

void bfs() {
  queue <triple> Q;
  memset(D, -1, sizeof(D));
  memset(T, 0, sizeof(T));

  D[n1][n2][0] = 0;
  T[n1][n2][0] = 1;
  Q.push(make_triple(n1, n2, 0));

  while (!Q.empty()) {
    triple u = Q.front();
    Q.pop();
    for (int t0 = 0; t0 <= u.i0; t0++) {
      for (int t1 = 0; t1 <= u.i1; t1++) {
        if (t0 + t1 < 1 || t0 + 2*t1 > k) {
          continue;
        }
        triple v = make_triple(n1 - u.i0 + t0, n2 - u.i1 + t1, !u.i2);
        if (D[v.i0][v.i1][v.i2] == -1) {
          D[v.i0][v.i1][v.i2] = D[u.i0][u.i1][u.i2] + 1;
          Q.push(v);
        }
        if (D[v.i0][v.i1][v.i2] == D[u.i0][u.i1][u.i2] + 1) {
          long long sum = T[u.i0][u.i1][u.i2];
          sum = (sum * comb(u.i0, t0)) % MOD;
          sum = (sum * comb(u.i1, t1)) % MOD;
          T[v.i0][v.i1][v.i2] += sum;
          T[v.i0][v.i1][v.i2] %= MOD;
        }
      }
    }
  }
}

int main() {
  int n;

  n1 = n2 = 0;
  scanf("%d %d", &n, &k);
  k /= 50;
  for (int i = 0; i < n; i++) {
    int w;
    scanf("%d", &w);
    if (w == 50) {
      n1++;
    } else {
      n2++;
    }
  }

  memset(C, -1, sizeof(C));
  bfs();

  printf("%d\n", D[n1][n2][1]);
  if (D[n1][n2][1] == -1) {
    printf("0\n");
    return 0;
  }

  int t = T[n1][n2][1];
  printf("%d\n", t);

  return 0;
}
