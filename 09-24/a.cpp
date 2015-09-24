#include <bits/stdc++.h>

using namespace std;

#define VMAX 10100

queue <int> E[VMAX], I[VMAX];

struct ll {
  int v;
  ll *prev, *next;
};

ll poll[262144];
int pc = 0;

ll *gstart, *gend;

void solve(int s) {
  gstart = &poll[pc++];
  gend = &poll[pc++];

  gstart->v = s;
  gstart->prev = NULL;
  gstart->next = gend;

  gend->v = s;
  gend->prev = gstart;
  gend->next = NULL;

  ll *start = gstart, *end = gend, *act = gstart;

  int u = s;
  while (1) {
    int v = E[u].front();
    E[u].pop();
    if (v == s && !E[v].size()) {
      for (act = gstart; act != NULL; act = act->next) {
        if (E[act->v].size()) {
          start = act;
          end = &poll[pc++];
          end->v = act->v;
          end->prev = start;
          end->next = start->next;
          start->next = end;
          s = u = act->v;
          break;
        }
      }
      if (!E[u].size()) {
        for (act = gstart; act != NULL; act = act->next) {
          printf(" %d", act->v+1);
        }
        printf("\n");
        return;
      }
    } else {
      act->next = &poll[pc++];
      act->next->prev = act;
      act = act->next;
      act->next = end;
      act->v = v;
      u = v;
    }
  }
}

int main() {
  int p, n = 0;
  scanf("%d", &p);
  int tot = 0;
  for (int i = 0; i < p; i++) {
    int m;
    scanf("%d", &m);
    tot += m;
    int last = -1;
    for (int j = 0; j <= m; j++) {
      int act;
      scanf("%d", &act);
      n = max(n, act);
      act--;
      if (last != -1) {
        E[last].push(act);
        I[act].push(last);
      }
      last = act;
    }
  }
  for (int i = 0; i < n; i++) {
    if (E[i].size() != I[i].size()) {
      printf("0\n");
      return 0;
    }
  }

  printf("%d", tot);
  solve(n-1);
  return 0;
}
