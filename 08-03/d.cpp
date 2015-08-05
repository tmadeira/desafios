#include <stdio.h>
#include <algorithm>
#include <set>
#include <assert.h>

using namespace std;

#define NMAX 100100

pair <int,int> A[NMAX+1];
int n;

pair <int,int> try_it(pair <int,int> A[], int n, int t) {
	int a = 0, b = n, x;

	while (b-a > 2) {
		x = (a+b) / 2;
		if (A[x].first-A[0].first < t && A[x].second-A[0].second < t) {
			a = x+1;
		} else {
			b = x+1;
		}
	}
	
	int v = -1;
	for (x = a; x < b; x++) {
		if (A[x].first-A[0].first == t) {
			v = 1;
			break;
		} else if (A[x].second-A[0].second == t) {
			v = 0;
			break;
		}
	}

	if (v == -1) {
		return make_pair(0, 0);
	}

	assert(x != n-1 || v == 1);

	if (x == n-1) {
		return make_pair(1, 0);
	}

	pair<int,int> y = try_it(A+x, n-x, t);

	if (y.first) {
		return make_pair(y.first + (v ? 1 : 0), y.second + (v ? 0 : 1));
	} else {
		return make_pair(0, 0);
	}
}

int main() {
  int v;
  scanf("%d", &n);
  A[0] = make_pair(0, 0);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v);
    if (v == 1) {
      A[i+1] = make_pair(A[i].first+1, A[i].second);
    } else {
      A[i+1] = make_pair(A[i].first, A[i].second+1);
    }
  }
  if (v == 2) {
    for (int i = 0; i <= n; i++) {
      swap(A[i].first, A[i].second);
    }
  }

  v = A[n].first;

  set < pair<int,int> > output;
  for (int t = 1; t <= v; t++) {
	  pair <int,int> s = try_it(A, n+1, t);
		if (s.first > s.second) {
			output.insert(make_pair(s.first, t));
		}
  }

  printf("%d\n", output.size());
	for (set < pair<int,int> >::iterator it = output.begin(); it != output.end(); it++) {
  	printf("%d %d\n", it->first, it->second);
  }

  return 0;
}
