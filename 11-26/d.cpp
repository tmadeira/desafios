#include <bits/stdc++.h>

using namespace std;

#define NMAX 1024
#define KMAX 131072

char str1[NMAX], str2[NMAX];
unsigned long long dpA[KMAX], dpB[KMAX];
int k;

int main() {
  scanf("%s", str1);
  scanf("%s", str2);
  scanf("%d", &k);
  int n = strlen(str1);
  unsigned long long A = 0, B = 0;
  for (int i = 0; i < n; i++) {
    string a = &str1[i];
    char tmp = str1[i];
    str1[i] = '\0';
    string b = str1;
    str1[i] = tmp;
    int good = (a + b == (string) str2);
    A+= good;
    B+= !good;
  }

  if ((string) str1 == (string) str2) {
    dpA[0] = 1;
    dpB[0] = 0;
  } else {
    dpA[0] = 0;
    dpB[0] = 1;
  }

  for (int n = 1; n <= k; n++) {
    dpA[n] = (dpA[n-1] * (A-1) + dpB[n-1] * A) % (unsigned long long) (1e9 + 7);
    dpB[n] = (dpA[n-1] * B + dpB[n-1] * (B-1)) % (unsigned long long) (1e9 + 7);
  }

  printf("%I64u\n", dpA[k]);

  return 0;
}
