#include <bits/stdc++.h>
using namespace std;
int A[4][4];
int main() {
  map < pair<int,int>, int > seg;
  map <int,int> x, y;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      scanf("%d", &A[i][j]);
    }
    if (A[i][0] != A[i][2] && A[i][1] != A[i][3]) {
      printf("NO\n");
      return 0;
    }
    if (A[i][0] == A[i][2] && A[i][1] == A[i][3]) {
      printf("NO\n");
      return 0;
    }
    seg[make_pair(A[i][0], A[i][1])]++;
    seg[make_pair(A[i][2], A[i][3])]++;
    x[A[i][0]]++;
    x[A[i][2]]++;
    y[A[i][0]]++;
    y[A[i][2]]++;
    if (A[i][2] < A[i][0] || (A[i][2] == A[i][0] && A[i][3] < A[i][1])) {
      swap(A[i][0], A[i][2]);
      swap(A[i][1], A[i][3]);
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = i+1; j < 4; j++) {
      int ok = 0;
      for (int k = 0; k < 4; k++) {
        if (A[i][k] != A[j][k]) {
          ok = 1;
        }
      }
      if (!ok) {
        printf("NO\n");
        return 0;
      }
    }
  }
  for (map <pair<int,int>,int>::iterator it = seg.begin(); it != seg.end(); it++) {
    if (it->second != 2) {
      printf("NO\n");
      return 0;
    }
  }
  if (x.size() != 2 || y.size() != 2) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  return 0;
}
