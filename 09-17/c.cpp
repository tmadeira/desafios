#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
typedef unsigned long long llu;

int main() {
  int m;
  scanf("%d", &m);
  map <string,int> shop;
  for (int i = 0; i < m; i++) {
    int c;
    char item[32];
    scanf("%d of %s", &c, item);
    shop[item] = c;
  }
  int n;
  scanf("%d", &n);
  deque < pair<string,int> > Q;
  for (int i = 0; i < n; i++) {
    int c;
    char item[32];
    scanf("%d of %s", &c, item);
    Q.push_back(make_pair((string) item, c));
  }
  int it = 0;
  while (!Q.empty()) {
    pair<string,int> u = Q.front();
    Q.pop_front();
    if (shop.find(u.first) != shop.end() && shop[u.first] > 0 && shop[u.first] < u.second) {
      int yes = 0;
      pair <string,int> v;
      if (!Q.empty()) {
        yes = 1;
        v = Q.front();
        Q.pop_front();
      }
      u.second = shop[u.first];
      Q.push_front(u);
      if (yes) {
        Q.push_front(v);
      } else {
        it--;
      }
    } else if (shop.find(u.first) != shop.end() && shop[u.first] > 0) {
      shop[u.first] -= u.second;
    }
    it++;
  }
  printf("%d\n", it);
  return 0;
}
