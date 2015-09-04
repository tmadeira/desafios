#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
typedef unsigned long long llu;

#define NMAX 256
#define SMAX 128

map <string,int> A, B;

bool cmp(string a, string b) {
  return B[a] > B[b];
}

int main() {
  int tests;
  scanf("%d", &tests);
  for (int test = 0; test < tests; test++) {
    int n;
    scanf("%d\n", &n);
    A.clear();
    B.clear();
    vector <string> a, b;
    for (int i = 0; i < n; i++) {
      char s[SMAX];
      fgets(s, SMAX, stdin);
      s[strlen(s)-1] = '\0';
      A[s] = i;
      a.push_back(s);
    }
    for (int i = 0; i < n; i++) {
      char s[SMAX];
      fgets(s, SMAX, stdin);
      s[strlen(s)-1] = '\0';
      B[s] = i;
      b.push_back(s);
    }

    vector <string> o;
    for (int i = n-1; i >= 0; i--) {
      int done = 0;
      for (int j = i-1; j >= 0; j--) {
        if (B[a[j]] > B[a[i]]) {
          done = 1;
          o.push_back(a[i]);
          break;
        }
      }
      if (!done) {
        for (int j = 0; j < o.size(); j++) {
          if (B[o[j]] > B[a[i]]) {
            o.push_back(a[i]);
            break;
          }
        }
      }
    }

    sort(o.begin(), o.end(), cmp);
    for (int i = 0; i < o.size(); i++) {
      printf("%s\n", o[i].c_str());
    }
    printf("\n");
  }
  return 0;
}
