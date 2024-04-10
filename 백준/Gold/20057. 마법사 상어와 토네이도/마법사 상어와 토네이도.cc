#include <bits/stdc++.h>
using namespace std;

struct Position {
  int row;
  int col;
};

int board[500][500], n, res = 0;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };

Position spreadLoc[4][10] = {
    { {-1, 1}, {1, 1}, {-1, 0}, {1, 0}, {-2, 0}, {2, 0}, {-1, -1}, {1, -1}, {0, -2}, {0, -1} },
    { {-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {0, -2}, {0, 2}, {1, -1}, {1, 1}, {2, 0}, {1, 0} },
    { {-1, -1}, {1, -1}, {-1, 0}, {1, 0}, {-2, 0}, {2, 0}, {-1, 1}, {1, 1}, {0, 2}, {0, 1} },
    { {1, -1}, {1, 1}, {0, -1}, {0, 1}, {0, -2}, {0, 2}, {-1, -1}, {-1, 1}, {-2, 0}, {-1, 0} }
  }; 

int spreadRate[9] = { 1, 1, 7, 7, 2, 2, 10, 10, 5 };
Position currentLoc;

bool isInGrid(int row, int col) {
  if (row >= 1 && row <= n && col >= 1 && col <= n) {
    return true;
  }
  return false;
}

void spreadSand(int direction, int cnt) {
  for (int i = 0; i < cnt; i++) {
    currentLoc.row += dy[direction];
    currentLoc.col += dx[direction];
    int alpha = 0;
    for (int j = 0; j < 10; j++) {
      int ny = currentLoc.row + spreadLoc[direction][j].row;
      int nx = currentLoc.col + spreadLoc[direction][j].col;
      int movingSand;
      if (j == 9) {
        movingSand = board[currentLoc.row][currentLoc.col] - alpha;
      } else {
        movingSand = board[currentLoc.row][currentLoc.col] * spreadRate[j] / 100;
        alpha += movingSand;
      }

      if (isInGrid(ny, nx)) {
        board[ny][nx] += movingSand;
      }
    }
    board[currentLoc.row][currentLoc.col] = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> board[i][j];
      res += board[i][j];
    }
  }
  currentLoc = {n / 2 + 1, n / 2 + 1};
  int direction = 0, moveCnt = 1;
  while (true) {
    spreadSand(direction, moveCnt);
    direction = (direction + 1) % 4;
    if (!(direction % 2)) {
      moveCnt++;
    }
    if (moveCnt == n) {
      moveCnt--;
      spreadSand(direction, moveCnt);
      break;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      res -= board[i][j];
    }
  }

  cout << res << "\n";
}