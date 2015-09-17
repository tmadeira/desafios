#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
typedef unsigned long long llu;

map < int, vector<string> > dict;
vector <string> enc;
char letters[26];
char used[26];
string line;

int backtrack(int idx) {
  if (idx == enc.size()) {
    for (int i = 0; i < line.size(); i++) {
      if (line[i] != ' ') {
        line[i] = letters[line[i]-'a'];
      }
    }
    printf("%s\n", line.c_str());
    return 1;
  }
  int sz = enc[idx].size();
  if (dict.find(sz) == dict.end()) {
    return 0;
  }
  char delta[26];
  memset(delta, 0, sizeof(delta));
  for (int k = 0; k < dict[sz].size(); k++) {
    string dw = dict[sz][k];
    int ok = 1;
    for (int i = 0; i < sz && ok; i++) {
      char act = letters[enc[idx][i]-'a'];
      if (act != 0 && act != dw[i]) {
        ok = 0;
      } else if (act == 0) {
        if (used[dw[i]-'a']) {
          ok = 0;
        } else {
          letters[enc[idx][i]-'a'] = dw[i];
          delta[enc[idx][i]-'a'] = 1;
          used[dw[i]-'a'] = 1;
        }
      }
    }
    if (ok && backtrack(idx+1)) {
      return 1;
    }
    for (int i = 0; i < 26; i++) {
      if (delta[i]) {
        used[letters[i]-'a'] = 0;
        delta[i] = 0;
        letters[i] = 0;
      }
    }
  }
  return 0;
}

int main() {
  int n;
  cin >> n;
  getline(cin, line);
  for (int i = 0; i < n; i++) {
    string word;
    getline(cin, word);
    dict[word.size()].push_back(word);
  }
  while (getline(cin, line)) {
    enc.clear();
    istringstream iss(line);
    while (iss) {
      string word;
      iss >> word;
      if (word.size()) {
        enc.push_back(word);
      }
    }
    memset(letters, 0, sizeof(letters));
    memset(used, 0, sizeof(used));
    if (!backtrack(0)) {
      for (int i = 0; i < line.size(); i++) {
        if (line[i] != ' ') {
          line[i] = '*';
        }
      }
      printf("%s\n", line.c_str());
    }
  }
  return 0;
}
