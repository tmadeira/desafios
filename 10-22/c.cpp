#include <bits/stdc++.h>

using namespace std;

#define NMAX 2048
#define MOD 1000000007ll

long long dp[NMAX][NMAX], sum[NMAX][NMAX];
char S[NMAX];

int main() {
  int N, K;
  scanf("%d %d", &N, &K);
  scanf("%s", S);
  memset(dp, 0, sizeof(dp));
  memset(sum, 0, sizeof(sum));
  dp[N+1][0] = 1;
  for (int n = N; n >= 1; n--) {
    for (int k = 0; k <= K; k++) {
      sum[n][k] = (((long long) (S[n-1] - 'a')) * dp[n+1][k]);
      sum[n][k]%= MOD;
      sum[n][k]+= sum[n+1][k];
      sum[n][k]%= MOD;
      dp[n][k] = sum[n][k];
      int lx = n;
      for (int x = n; x <= N && k-(x-n+1)*(N-x+1) >= 0; x++) {
        dp[n][k]+= (((long long) ('z' - S[x-1])) * dp[x+1][k-(x-n+1)*(N-x+1)]) % MOD;
        dp[n][k]%= MOD;
        lx = x;
      }
      for (int x = N; x > lx && k-(x-n+1)*(N-x+1) >= 0; x--) {
        dp[n][k]+= (((long long) ('z' - S[x-1])) * dp[x+1][k-(x-n+1)*(N-x+1)]) % MOD;
        dp[n][k]%= MOD;
      }
      if (k == 0) {
        dp[n][k]+= 1;
        dp[n][k]%= MOD;
      }
    }
  }
  printf("%d\n", (int) dp[1][K]);
  return 0;
}
