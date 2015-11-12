#include <bits/stdc++.h>

using namespace std;

int main() {
  int w, h;
  scanf("%d %d", &w, &h);
  long long out = 0;
  for (int i = 0; i <= w; i++) {
    for (int j = 0; j <= h; j++) {
      long long ww = min(i, w-i);
      long long hh = min(j, h-j);
      out += ww*hh;
    }
  }
  cout << out << "\n";
  return 0;
}
