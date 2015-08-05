#include <bits/stdc++.h>
using namespace std;

struct event {
  int key;
  int start, end;
  int t;
  bool operator < (const event &o) const {
    if (end != o.end) {
      return end < o.end;
    }
    return key < o.key;
  }
};

bool by_start(event a, event b) {
  return make_pair(a.start, -a.key) < make_pair(b.start, -b.key);
}

int main() {
  vector<event> E;
  set<event> O;
  int n, m;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    E.push_back((event) {i, a, b, -1});
  }
  scanf("%d", &m);
  int C[m];
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d %d", &a, &b, &C[i]);
    if (C[i] > 0) {
      E.push_back((event) {n+i, a, b, 1});
    }
  }
  sort(E.begin(), E.end(), by_start);
  int out[n];
  for (int i = 0; i < E.size(); i++) {
    event e = E[i];
    if (e.t > 0) {
      O.insert(e);
    } else if (e.t < 0) {
      set<event>::iterator actor = O.lower_bound(e);
      if (actor == O.end()) {
        printf("NO\n");
        return 0;
      }
      out[e.key] = actor->key - n + 1;
      if (--C[actor->key - n] == 0) {
        O.erase(actor);
      }
    }
  }

  printf("YES\n");
  for (int i = 0; i < n; i++) {
    if (i != 0) {
      printf(" ");
    }
    printf("%d", out[i]);
  }
  printf("\n");
  return 0;
}
