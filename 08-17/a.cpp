#include <bits/stdc++.h>

using namespace std;

#define NMAX 262144

long long S[NMAX], M[NMAX];
int n;

void st_update(int a, int b, int value, int node, int l, int r) {
  if (a <= l && r <= b) {
    S[node] += value;
    M[node] += value;
  } else {
    int lnode = 2*node;
    int rnode = 2*node+1;
    if (S[node]) {
      S[lnode] += S[node];
      S[rnode] += S[node];
      M[lnode] += S[node];
      M[rnode] += S[node];
      S[node] = 0;
    }
    int m = (l+r)/2;
    if (a <= m) {
      st_update(a, b, value, lnode, l, m);
    }
    if (b >= m+1) {
      st_update(a, b, value, rnode, m+1, r);
    }
    M[node] = min(M[lnode], M[rnode]);
  }
}

int main() {
	scanf("%d", &n);
	map < int, pair<int,int> > dates;
	int V[n], D[n];
	for (int i = 0; i < n; i++) {
		int val, day, month, hour, min;
		scanf("%d %d.%d %d:%d", &val, &day, &month, &hour, &min);
    dates[month*1000000+day*10000+hour*100+min] = make_pair(i, val);
		V[i] = val;
	}
	int cur = 0;
	for (map<int,pair<int,int> >::iterator it = dates.begin(); it != dates.end(); it++) {
		D[it->second.first] = ++cur;
	}

  memset(S, 0, sizeof(S));
  memset(M, 0, sizeof(M));
	for (int i = 0; i < n; i++) {
    st_update(D[i], n, V[i], 1, 1, n);
		printf("%lld\n", min(M[1], 0ll));
	}
	return 0;
}
