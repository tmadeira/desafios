#include <bits/stdc++.h>

using namespace std;

string p;
int *pi;

void compute_prefix_function(int n) {
  int k = pi[0] = -1;
  for (int i = 1; i < n; i++) {
    while (k >= 0 && p[i] != p[k+1]) {
      k = pi[k];
    }
    if (p[i] == p[k+1]) {
      k++;
    }
    pi[i] = k;
  }
}

int main() {
  string a, b;
  cin >> a;
  cin >> b;
  p = a + "|" + b;
  int k = a.size();
  int n = p.size();
  pi = (int *) malloc(sizeof(int)*n);
  compute_prefix_function(n);

  for (int i = k+1; i < n; i++) {
    if (pi[i] < 0) {
      printf("Yes\n");
      return 0;
    }
  }
  for (int i = n-1; i > k; i--) {
    if (pi[i] > 0 && pi[i-1] != pi[i]-1) {
      pi[i-1] = pi[i]-1;
    }
  }
  printf("No\n");
  for (int i = k+1; i < n; i++) {
    if (i != k+1 && pi[i] == 0) {
      printf(" ");
    }
    printf("%c", p[i]);
  }
  printf("\n");
  return 0;
}
