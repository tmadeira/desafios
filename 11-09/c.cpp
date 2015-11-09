#include <bits/stdc++.h>

using namespace std;

struct point {
  int x, y;
};

int P[NMAX];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &P[i].x, &P[i].y);
  }
  return 0;
}
