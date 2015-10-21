#include <bits/stdc++.h>

using namespace std;

#define NMAX 64
#define MMAX 1024

#define EPS 1e-9

struct point {
  double x, y;
};

struct vertex {
  int v;
  double d;
  int p;
  bool operator < (const vertex &o) const {
    return d > o.d;
  }
};

int side(point a, point b, point c) {
  double cross = (b.x-a.x) * (c.y-a.y) - (b.y-a.y) * (c.x-a.x);
  return (-EPS < cross && cross < EPS) ? 0 : (cross < 0 ? -1 : 1);
}

double dist(point a, point b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

point P[NMAX], H[MMAX];
vector <int> E[NMAX];
vector <double> D[NMAX];
double M[NMAX];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    P[i] = (point) { x, y };
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    H[i] = (point) { x, y };
  }
  double out = 1<<30;
  if (m == 0) {
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        for (int k = j+1; k < n; k++) {
          if (side(P[i], P[j], P[k]) != 0) {
            out = min(out, dist(P[i], P[j]) + dist(P[j], P[k]) + dist(P[k], P[i]));
          }
        }
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i != j) {
          int sameSide = 1;
          for (int k = 0; k < m && sameSide; k++) {
            if (side(P[i], P[j], H[k]) >= 0) {
              sameSide = 0;
            }
          }
          if (sameSide) {
            E[i].push_back(j);
            D[i].push_back(dist(P[i], P[j]));
          }
        }
      }
    }
    for (int s = 0; s < n; s++) {
      for (int i = 0; i < n; i++) {
        M[i] = -1;
      }
      double td = 1<<30;
      priority_queue <vertex> Q;
      Q.push((vertex) {s, 0, -1});
      M[s] = 0;
      while (!Q.empty()) {
        vertex u = Q.top();
        Q.pop();
        for (int i = 0; i < E[u.v].size(); i++) {
          vertex v = {E[u.v][i], u.d + D[u.v][i], u.v};
          if (u.p != v.v) {
            if (M[v.v] < 0 || v.d < M[v.v]) {
              M[v.v] = v.d;
              Q.push(v);
            } else if (v.v == s) {
              td = min(td, v.d);
            }
          }
        }
      }
      out = min(out, td);
    }
  }
  printf("%.2f\n", out);
  return 0;
}
