#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
typedef unsigned long long llu;

char C[3][3];
int M[1<<17];

int main() {
  int pi = 0;
  for (int i = 0; i < 4; i++) {
    char s[8];
    scanf("%s", s);
    for (int j = 0; j < 4; j++) {
      if (s[j] == 'B') {
        pi |= (1<<(i*4+j));
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    scanf("%s", C[i]);
  }
  memset(M, -1, sizeof(M));
  queue <int> Q;
  M[pi] = 0;
  Q.push(pi);

  while (!Q.empty()) {
    int pos = Q.front();
    Q.pop();
    if (pos == 0 || pos == (1<<16)-1) {
      printf("%d\n", M[pos]);
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        int newpos = pos;
        for (int k = 0; k <= 2; k++) {
          for (int l = 0; l <= 2; l++) {
            if (C[k][l] == '1') {
              if (0 <= i+k-1 && i+k-1 < 4 && 0 <= j+l-1 && j+l-1 < 4) {
                int p = 4*(i+k-1)+j+l-1;
                newpos^= 1<<p;
              }
            }
          }
        }
        if (M[newpos] == -1) {
          M[newpos] = M[pos]+1;
          Q.push(newpos);
        }
      }
    }
  }

  printf("Impossible\n");
  return 0;
}
