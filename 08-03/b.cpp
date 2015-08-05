#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string smallest_shift(string s) {
  string r = s;
  for (int i = 0; i < s.size(); i++) {
    char c = s[0];
    s.erase(s.begin());
    s+= c;
    if (s < r) {
      r = s;
    }
  }
  return r;
}

int main() {
  int n;
  string s;
  scanf("%d", &n);
  cin >> s;
  string r = s;
  for (int i = 0; i < 10; i++) {
    string t = s;
    for (int j = 0; j < n; j++) {
      t[j]++;
      if (t[j] > '9') {
        t[j] = '0';
      }
    }
    s = t;

    string candidate = smallest_shift(s);
    if (candidate < r) {
      r = candidate;
    }
  }
  printf("%s\n", r.c_str());
  return 0;
}
