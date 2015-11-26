#include <bits/stdc++.h>

using namespace std;

int n, m;
int A[10][10];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

char pd[1<<(5*5)][5*5][5*5];
// TODO: preencher PD

int play(int ax, int ay, int bx, int by);

int play2(int ax, int ay, int bx, int by) {
  int out = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!A[i][j] && (i != ax || j != ay) && (i != bx || j != by)) {
        A[i][j] = 1;
        if (!play(ax, ay, bx, by)) {
          out = 1;
        }
        A[i][j] = 0;
      }
    }
  }
  return out;
}

int play(int ax, int ay, int bx, int by) {
  if (ax == bx && ay == by) {
    return 1;
  }
  int out = 0;
  if (!A[ax][ay]) {
    for (int d = 0; d < 4; d++) {
      int cx = ax + dx[d];
      int cy = ay + dy[d];
      if (0 <= cx && cx < n && 0 <= cy && cy < m) {
        if (!play2(cx, cy, bx, by)) {
          out = 1;
        }
      }
    }
  }
  if (!A[bx][by]) {
    for (int d = 0; d < 4; d++) {
      int cx = bx + dx[d];
      int cy = by + dy[d];
      if (0 <= cx && cx < n && 0 <= cy && cy < m) {
        if (!play2(ax, ay, cx, cy)) {
          out = 1;
        }
      }
    }
  }
  return out;
}

int main() {
  int ax, ay, bx, by;
  scanf("%d %d %d %d %d %d", &n, &m, &ax, &ay, &bx, &by);
  if (abs(bx-ax) + abs(by-ay) >= 8) {
    printf("Second\n");
    return 0;
  }
  int mx = min(ax, bx);
  int my = min(ay, by);
  ax -= mx;
  bx -= mx;
  ay -= my;
  by -= my;
  n = max(ax, bx) + 1;
  m = max(ay, by) + 1;
  memset(A, 0, sizeof(A));
  memset(pd, 0, sizeof(pd));
  printf("%s\n", play(ax, ay, bx, by) ? "First" : "Second");
  return 0;
}
