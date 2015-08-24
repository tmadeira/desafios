#include <bits/stdc++.h>

using namespace std;

#define NMAX 16384
#define XMAX 32768

int tree[XMAX], M[NMAX];

int read(int idx) {
  int sum = 0;
  while (idx > 0){
    sum += tree[idx];
    idx -= (idx & -idx);
  }
  return sum;
}

void update(int idx, int val) {
  while (idx < XMAX){
    tree[idx] += val;
    idx += (idx & -idx);
  }
}

int main() {
  memset(tree, 0, sizeof(tree));
  memset(M, 0, sizeof(M));

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x++;
    M[read(x)]++;;
    update(x, 1);
  }
  
  for (int i = 0; i < n; i++) {
    printf("%d\n", M[i]);
  }
  return 0;
}
