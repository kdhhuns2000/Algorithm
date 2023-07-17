#include <bits/stdc++.h>
using namespace std;

int n, board[10][10], res = 0;
bool slashLine[19], backSlashLine[19]; // 슬래쉬라인은 row + col 라인, 역슬래쉬라인은 row - col + 9

void Dfs(int row, int col, int cnt) {
  if (col >= n) {
    row++;
    col = (col + 1) % 2;
  }
  if (row >= n) {
    res = max(res, cnt);
    return;
  }
  if (board[row][col] && !slashLine[row + col] && !backSlashLine[row - col + 9]) {
    slashLine[row + col] = true;
    backSlashLine[row - col + 9] = true;
    Dfs(row, col + 2, cnt + 1);
    slashLine[row + col] = false;
    backSlashLine[row - col + 9] = false;
  }
  Dfs(row, col + 2, cnt);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }
  Dfs(0, 0, 0);
  int tmp = res;
  res = 0;
  Dfs(0, 1, 0);
  cout << tmp + res;
}