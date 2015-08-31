#include <bits/stdc++.h>

using namespace std;

#define NMAX 4003

char s[NMAX];
int n;

int PD[NMAX];
int M[NMAX];

inline int is_pal(char *s, int n) {
  for (int i = 0; 2*i < n; i++) {
    if (s[i] != s[n-1-i]) {
      return 0;
    }
  }
  return 1;
}

int f(int n) {
  if (PD[n] != -1) {
    return PD[n];
  }
  if (n == 0) {
    return 0;
  }
  PD[n] = n;
  M[n] = n-1;
  for (int i = 0; i < n; i++) {
    if (is_pal(s+i, n-i)) {
      if (f(i)+1 < PD[n]) {
        PD[n] = f(i)+1;
        M[n] = i;
      }
    }
  }
  return PD[n];
}

int main() {
  scanf("%s", s);
  n = strlen(s);

  memset(PD, -1, sizeof(PD));
  int output = f(n);

  printf("%d\n", output);
  vector <string> sol;
  int c = 0;
  for (int o = 0; o < output; o++) {
    char str[NMAX];
    strcpy(str, s+M[n]);
    str[strlen(str)-c] = '\0';
    c += strlen(str);
    sol.push_back(str);
    n = M[n];
  }
  for (int i = sol.size()-1; i >= 0; i--) {
    printf("%s%c", sol[i].c_str(), i == 0 ? '\n' : ' ');
  }
  return 0;
}
