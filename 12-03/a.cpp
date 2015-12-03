#include <bits/stdc++.h>

using namespace std;

int A[128];

int main() {
  int n;
  scanf("%d", &n);
  map <int,int> C;
  for (int i = 0; i < n; i++) {
    scanf("%d", A+i);
    C[A[i]]++;
  }
  for (map<int,int>::iterator it = C.begin(); it != C.end(); it++) {
    if (it->second > (n+1)/2) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}
