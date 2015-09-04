#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
typedef unsigned long long llu;

#define LMAX 26
#define SMAX 5010
#define INF 1000000000

char a[SMAX], b[SMAX];
int PD[SMAX][SMAX];

// first, last
int af[LMAX], al[LMAX];
int bf[LMAX], bl[LMAX];

int main() {
  int tests;
  scanf("%d", &tests);
  for (int test = 0; test < tests; test++) {
    scanf("%s", a);
    scanf("%s", b);
    int n = strlen(a);
    int m = strlen(b);
    memset(af, -1, sizeof(af));
    memset(al, -1, sizeof(al));
    for (int i = 0; i < n; i++) {
      al[a[i]-'A'] = i;
      if (af[a[i]-'A'] == -1) {
        af[a[i]-'A'] = i;
      }
    }
    memset(bf, -1, sizeof(bf));
    memset(bl, -1, sizeof(bl));
    for (int i = 0; i < m; i++) {
      bl[b[i]-'A'] = i;
      if (bf[b[i]-'A'] == -1) {
        bf[b[i]-'A'] = i;
      }
    }
    PD[0][0] = 0;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (i != 0 || j != 0) {
          PD[i][j] = INF;
        }
        if (i > 0) {
          int x = PD[i-1][j];
          if (af[a[i-1]-'A'] == i-1 && (bf[a[i-1]-'A'] == -1 || bf[a[i-1]-'A'] > j-1)) {
            x -= (i-1 + j-1);
          }
          if (al[a[i-1]-'A'] == i-1 && (bl[a[i-1]-'A'] == -1 || bl[a[i-1]-'A'] <= j-1)) {
            x += (i-1 + j-1);
          }
          PD[i][j] = min(PD[i][j], x);
        }
        if (j > 0) {
          int x = PD[i][j-1];
          if (bf[b[j-1]-'A'] == j-1 && (af[b[j-1]-'A'] == -1 || af[b[j-1]-'A'] > i-1)) {
            x -= (i-1 + j-1);
          }
          if (bl[b[j-1]-'A'] == j-1 && (al[b[j-1]-'A'] == -1 || al[b[j-1]-'A'] <= i-1)) {
            x += (i-1 + j-1);
          }
          PD[i][j] = min(PD[i][j], x);
        }
      }
    }
    printf("%d\n", PD[n][m]);
  }
  return 0;
}
