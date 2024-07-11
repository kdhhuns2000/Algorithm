#include <bits/stdc++.h>
using namespace std;

int N, K, board[13][13], turnCount = 0;
tuple<int, int, int> horse[10];
deque<int> deq[13][13];
int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};
bool canRepeat = false;

bool isInside(int row, int col) {
  return row >= 1 && row <= N && col >= 1 && col <= N;
}

void solve() {
  for (int i = 0; i < K; i++) {
    int row = get<0>(horse[i]);
    int col = get<1>(horse[i]);
    if (deq[row][col].front() == i) { // 현재 i번째 소가 보드판에서 가장 아래 있는 소일 경우,
      int dir = get<2>(horse[i]);
      int ny = row + dy[dir];
      int nx = col + dx[dir];

      if (board[ny][nx] == 2 || !isInside(ny, nx)) {
        if (dir == 1 || dir == 2) {
          dir = dir % 2 + 1;
        } else if (dir == 3 || dir == 4) {
          dir = (dir - 2) % 2 + 3;
        }
        get<2>(horse[i]) = dir;
        ny = row + dy[dir];
        nx = col + dx[dir];
        if (board[ny][nx] == 2 || !isInside(ny, nx)) continue;
      }

      if (board[ny][nx] == 0 && isInside(ny, nx)) {
        while (!deq[row][col].empty()) {

          deq[ny][nx].push_back(deq[row][col].front());
          get<0>(horse[deq[row][col].front()]) = ny;
          get<1>(horse[deq[row][col].front()]) = nx;
          deq[row][col].pop_front();

        }
      } else if (board[ny][nx] == 1 && isInside(ny, nx)) {
        while (!deq[row][col].empty()) {
          deq[ny][nx].push_back(deq[row][col].back());
          get<0>(horse[deq[row][col].back()]) = ny;
          get<1>(horse[deq[row][col].back()]) = nx;
          deq[row][col].pop_back();
        }
      }

      if (deq[ny][nx].size() >= 4) {
        canRepeat = true;
        break;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> board[i][j];
    }
  }

  int a, b, c;

  for (int i = 0; i < K; i++) {
    cin >> a >> b >> c;
    horse[i] = make_tuple(a, b, c);
    deq[a][b].push_back(i);
  }

  while (turnCount <= 1000 && !canRepeat) {
    solve();
    turnCount++;
  }

  (turnCount > 1000) ? cout << -1 << '\n' : cout << turnCount << '\n';

}
