#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long llu;

llu tab_to_llu(int A[4][4]) {
  llu out = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      out *= 16;
      out += A[i][j];
    }
  }
  return out;
}

int heur(llu tab) {
  int total = 0;
  int row = 3;
  int col = 3;
  while (row >= 0) {
    int guy = tab % 16;
    tab/= 16;
    int goal_row = guy/4;
    int goal_col = guy%4;
    total += abs(row-goal_row) + abs(col-goal_col);
    if (col == 0) {
      col = 3;
      row--;
    } else {
      col--;
    }
  }
  return total/2;
}

int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };
char act[4] = { 'U', 'D', 'L', 'R' };

void llu_to_tab(llu tab, int A[4][4]) {
  // TODO
}

vector < pair<char,llu> > get_actions(llu tab) {
  llu tmp = tab;
  int row = 3;
  int col = 3;
  while (row >= 0) {
    int guy = tmp % 16;
    tmp/= 16;
    if (guy == 15) {
      break;
    }
    if (col == 0) {
      col = 3;
      row--;
    } else {
      col--;
    }
  }
  vector < pair <char,llu> > ret;
  for (int d = 0; d < 4; d++) {
    int ni = row+di[d];
    int nj = col+dj[d];
    if (0 <= ni && ni < 4 && 0 <= nj && nj < 4) {
      int B[4][4];
      llu_to_tab(tab, B);
      tmp = tab_to_llu(B);
      ret.push_back(make_pair(act[d], tmp));
    }
  }
  return ret;
}

struct state {
  llu tab;
  int g, h;
  char act[64];
  bool operator < (const state &o) const {
    return g+h > o.g+o.h;
  }
};

int main() {
  int tests;
  scanf("%d", &tests);

  int G[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      G[i][j] = i*4+j;
    }
  }

  llu goal = tab_to_llu(G);

  for (int test = 0; test < tests; test++) {
    int A[4][4];
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        scanf("%d", &A[i][j]);
        A[i][j]--;
        if (A[i][j] == -1) {
          A[i][j] = 15;
        }
      }
    }

    priority_queue <state> Q;

    state ss;
    ss.tab = tab_to_llu(A);
    ss.g = 0;
    ss.h = heur(ss.tab);
    Q.push(ss);

    int imp = 1;

    while (!Q.empty() && imp) {
      state u = Q.top();
      Q.pop();

      if (u.g < 50) {
        vector < pair<char,llu> > actions = get_actions(u.tab);
        for (int i = 0; i < actions.size(); i++) {
          char act = actions[i].first;
          llu new_tab = actions[i].second;
          state v;
          v.tab = new_tab;
          v.g = u.g+1;
          memcpy(v.act, u.act, u.g);
          v.act[u.g] = act;
          if (new_tab == goal) {
            imp = 0;

            for (int i = 0; i < v.g; i++) {
              printf("%c", v.act[i]);
            }
            printf("\n");

            break;
          }
          v.h = heur(new_tab);
          Q.push(v);
        }
      }
    }

    if (imp) {
      printf("This puzzle is not solvable.\n");
    }
  }
  return 0;
}
