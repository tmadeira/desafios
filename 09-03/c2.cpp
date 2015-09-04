#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
typedef unsigned long long llu;

#define LMAX 26
#define SMAX 5010
#define NMAX 128

int af[LMAX], al[LMAX];
int bf[LMAX], bl[LMAX];
char A[NMAX], B[NMAX];
int AW[NMAX], BW[NMAX];
int ac, bc;
int PD[NMAX][NMAX];

int f(int a, int b) {
  f(a-1, b) + custo de colocar o a-1 nesta posicao;
  f(a, b-1) + custo de colocar o b-1 nesta posicao;
  for (int i = 0; i < p; i++) {
    f(n-1, i);
  }
  devo colocar cara n-1, em posicoes de 0 a p
  posso usar posicoes de 0 a p
}

int main() {
  int tests;
  scanf("%d", &tests);
  for (int test = 0; test < tests; test++) {
    char a[SMAX], b[SMAX];
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
    ac = 0;
    for (int i = 0; i < n; i++) {
      if (af[a[i]-'A'] == i || al[a[i]-'A'] == i) {
        AW[ac] = 1;
        A[ac++] = a[i];
      } else {
        if (ac == 0 || A[ac-1] != 'x') {
          AW[ac] = 1;
          A[ac++] = 'x';
        } else {
          AW[ac-1]++;
        }
      }
    }
    bc = 0;
    for (int i = 0; i < m; i++) {
      if (bf[b[i]-'A'] == i || bl[b[i]-'A'] == i) {
        BW[bc] = 1;
        B[bc++] = b[i];
      } else {
        if (bc == 0 || B[bc-1] != 'x') {
          BW[bc] = 1;
          B[bc++] = 'x';
        } else {
          BW[bc-1]++;
        }
      }
    }

    memset(PD, -1, sizeof(PD));
    printf("%d\n", f(ac, bc));
  }
  return 0;
}
