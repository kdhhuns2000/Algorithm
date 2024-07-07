#include <bits/stdc++.h>
using namespace std;

int n, m, res = 2147483647;
int board[1001][1001];
int dp[1001][1001][3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> board[i][j];
    }
  }
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        if (j == 1) {
          dp[i][j][0] = 1000000000;
          dp[i][j][1] = board[i][j] + dp[i - 1][j + 1][0];
          dp[i][j][2] = board[i][j] + min(dp[i - 1][j][1], dp[i - 1][j + 1][0]);
        } else if (j == m) {
          dp[i][j][0] = board[i][j] + min(dp[i - 1][j - 1][2], dp[i - 1][j][1]);
          dp[i][j][1] = board[i][j] + dp[i - 1][j - 1][2];
          dp[i][j][2] = 1000000000;
        } else {
          dp[i][j][0] = board[i][j] + min(dp[i - 1][j - 1][2], dp[i - 1][j][1]);
          dp[i][j][1] = board[i][j] + min(dp[i - 1][j - 1][2], dp[i - 1][j + 1][0]);
          dp[i][j][2] = board[i][j] + min(dp[i - 1][j][1], dp[i - 1][j + 1][0]);
        }
    }
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < 3; j++) {
      res = min(res, dp[n][i][j]);
    }
  }
  cout << res << '\n';
}