#include <bits/stdc++.h>
using namespace std;

int n, m, res = 0;
int board[501][501];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
bool visited[501][501] = { false };

bool isValid(pair<int, int> p) {
  if (p.first >= 1 && p.first <= n && p.second >= 1 && p.second <= m) {
    return true;
  }
  return false;
}

void solve(pair<int, int> p, int depth, int sum) {
  if (depth == 0) {
    for (int i = 0; i < 4; i++) {
      sum += board[p.first + dy[i]][p.second + dx[i]];
    }
    for (int i = 0; i < 4; i++) {
      sum -= board[p.first + dy[i]][p.second + dx[i]];
      bool tmpValid = true;
      for (int j = 0; j < 4; j++) {
        if (i == j) continue;
        if (!isValid(make_pair(p.first + dy[j], p.second + dy[i]))) {
          tmpValid = false;
          break;
        }
      }
      if (tmpValid) {
        res = max(sum, res);
      }
      sum += board[p.first + dy[i]][p.second + dx[i]];
    }
    for (int i = 0; i < 4; i++) {
      sum -= board[p.first + dy[i]][p.second + dx[i]];
    }
  }

  if (depth == 3) {
    res = max(sum, res);
    return; 
  }
  for (int i = 0; i < 4; i++) {
    pair<int, int> nextLoc = make_pair(p.first + dy[i], p.second + dx[i]);
    if (isValid(nextLoc) && !visited[nextLoc.first][nextLoc.second]) {
      visited[nextLoc.first][nextLoc.second] = true;
      solve(nextLoc, depth + 1, sum + board[nextLoc.first][nextLoc.second]);
      visited[nextLoc.first][nextLoc.second] = false;
    }
  }
}

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
      visited[i][j] = true;
      solve(make_pair(i, j), 0, board[i][j]);
      visited[i][j] = false;
    }
  }

  cout << res << '\n';
}