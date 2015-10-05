#include <bits/stdc++.h>

using namespace std;

#define SMAX 64

int main() {
  set <string> S;
  char s[SMAX];
  scanf("%s", s);
  S.insert(s);
  while (scanf("%s", s) && strcmp("#", s) != 0) {
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
      if (s[i] == '-') {
        s[i] = '\0';
        S.insert(&s[0]);
        S.insert(&s[i+1]);
        i = n;
      }
    }
  }
  printf("%d\n", S.size()-1);
  return 0;
}
