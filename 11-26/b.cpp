#include <bits/stdc++.h>

using namespace std;

set < pair<int,int> > P;

int n;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    P.insert(make_pair(x, y));
  }
  int count = 0;
  for (set< pair<int,int> >::iterator it = P.begin(); it != P.end(); it++) {
    for (set< pair<int,int> >::iterator jt = P.begin(); jt != P.end(); jt++) {
      if (*it == *jt || abs(it->first + jt->first) % 2 == 1 || abs(it->second + jt->second) % 2 == 1) {
        continue;
      }
      pair <int,int> m = make_pair((it->first + jt->first) / 2, (it->second + jt->second) / 2);
      if (P.find(m) != P.end()) {
        count++;
      }
    }
  }
  printf("%d\n", count / 2);
  return 0;
}
