#include <bits/stdc++.h>
using namespace std;

int R, C, N;
char input;
int board[201][201];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

void addTime() {
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      if (board[i][j] >= 0) {
        board[i][j]++;
      }
    }
  }
}

bool isInside(int row, int col) {
  return (row >= 1 && row <= R && col >= 1 && col <= C);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> R >> C >> N;

  fill(board[0], board[0] + 201 * 201, -1);

  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      cin >> input;
      if (input == 'O') {
        board[i][j] = 1;
      }
    }
  }

  if (N != 1) {
    for (int time = 2; time <= N; time++) {
      addTime();

      if (time % 2 == 0) {
        for (int i = 1; i <= R; i++) {
          for (int j = 1; j <= C; j++) {
            if (board[i][j] == -1) {
              board[i][j] = 0;
            }
          }
        }
      } else {
        for (int i = 1; i <= R; i++) {
          for (int j = 1; j <= C; j++) {
            if (board[i][j] == 3) {
              for (int k = 0; k < 4; k++) {
                int ny = i - dy[k];
                int nx = j - dx[k];
                if (isInside(ny, nx) && board[ny][nx] != 3) {
                  board[ny][nx] = -1;
                }
              }
              board[i][j] = -1;
            }
          }
        }
        for (int i = 1; i <= R; i++) {
          for (int j = 1; j <= C; j++) {
            if (board[i][j] == 3) {
              board[i][j] = -1;
            }
          }
        }
      }
    }
  }

  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      if (board[i][j] == -1) {
        cout << '.';
      } else {
        cout << 'O';
      }
    }
    cout << '\n';
  }
}
