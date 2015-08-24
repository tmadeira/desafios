#include <bits/stdc++.h>

#define N 10

using namespace std;

int main() {
  int a;

  int M[16384];
  memset(M, 0, sizeof(M));
  int P[16384];
  int p = 0;

  for (int i = 2; i <= 10000; i++) {
    if (!M[i]) {
      for (int j = 2*i; j <= 10000; j+= i) {
        M[j] = 1;
      }
      P[p++] = i;
    }
  }

  map <int,int> pr;

  for (int i = 0; i < N; i++) {
    scanf("%d", &a);
    int c = a;
    for (int j = 0; j < p && P[j] <= c; j++) {
      while (c % P[j] == 0) {
        c/= P[j];
        pr[P[j]]++;
      }
    }
  }

  int x = 1;
  for (map<int,int>::iterator it = pr.begin(); it != pr.end(); it++) {
    x *= (it->second+1);
    x %= 10;
  }

  printf("%d\n", x);

  return 0;
}
