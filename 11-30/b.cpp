#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int A = 0, F = 0, I = 0;
  for (int i = 0; i < n; i++) {
    char cmd;
    scanf(" %c", &cmd);
    if (cmd == 'A') {
      A++;
    } else if (cmd == 'F') {
      F++;
    } else {
      I++;
    }
  }
  if (!I) {
    printf("%d\n", A+I);
  } else {
    printf("%d\n", I == 1 ? 1 : 0);
  }
  return 0;
}
