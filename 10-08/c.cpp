#include <bits/stdc++.h>

using namespace std;

char A[8][8];

int win(char c) {
  for (int i = 0; i < 3; i++) {
    if (A[0][i] == c && A[0][i] == A[1][i] && A[1][i] == A[2][i]) {
      return 1;
    }
    if (A[i][0] == c && A[i][0] == A[i][1] && A[i][1] == A[i][2]) {
      return 1;
    }
  }
  if (A[0][0] == c && A[0][0] == A[1][1] && A[1][1] == A[2][2]) {
    return 1;
  }
  if (A[2][0] == c && A[2][0] == A[1][1] && A[1][1] == A[0][2]) {
    return 1;
  }
  return 0;
}

int play(int left) {
  if (left == 0) {
    return 0;
  }

  char me = (left % 2 == 1 ? 'X' : 'O');

  int outcome = -10;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (A[i][j] == '#') {
        A[i][j] = me;
        if (win(me)) {
          outcome = 1;
        } else {
          int t_outcome = -play(left-1);
          if (t_outcome > outcome) {
            outcome = t_outcome;
          }
        }
        A[i][j] = '#';
      }
    }
  }

  return outcome;
}

int main() {
  for (int i = 0; i < 3; i++) {
    scanf("%s", A[i]);
  }
  int outcome = play(3);
  if (outcome > 0) {
    printf("Crosses win\n");
  } else if (outcome == 0) {
    printf("Draw\n");
  } else {
    printf("Ouths win\n");
  }
  return 0;
}
