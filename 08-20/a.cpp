#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector <int> S((n % 2 == 0 ? n/2+1 : (n+1)/2), 2147483647);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    pop_heap(S.begin(), S.end());
    if (a < S[S.size()-1]) {
      S[S.size()-1] = a;
    }
    push_heap(S.begin(), S.end());
  }
  sort_heap(S.begin(), S.end());
  if (n % 2 == 1) {
    printf("%d.0\n", S[S.size()-1]);
  } else {
    unsigned sum = 0;
    sum += S[S.size()-1];
    sum += S[S.size()-2];
    printf("%.1f\n", (double) sum / 2.0);
  }
  return 0;
}
