#include <bits/stdc++.h>
using namespace std;

int N, K, R;
bool board[101][101];
bool road[101][101][4];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> Cow;
int r_, c_, _r, _c;
int cowR, cowC;
int res = 0;
bool isVisited[101][101];
queue< pair<int, int> > q;

bool isInside(int row, int col) {
  return (row >= 1 && row <= N && col >= 1 && col <= N);
}

void solve(int row, int col) {
  q.push(make_pair(row, col));
  isVisited[row][col] = true;
  while(!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      if (road[y][x][i]) continue;
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (isInside(ny, nx) && !isVisited[ny][nx]) {
        q.push(make_pair(ny, nx));
        isVisited[ny][nx] = true;
      }
    }
  }
}

int addRes() {
  int ret = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (board[i][j] && !isVisited[i][j])
        ret++;
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> N >> K >> R;

  for (int i = 0; i < R; i++) {
    cin >> r_ >> c_ >> _r >> _c;
    for (int j = 0; j < 4; j++) {
      if (r_ + dy[j] == _r && c_ + dx[j] == _c) {
        road[r_][c_][j] = true;
        road[_r][_c][(j + 2) % 4] = true;
      }
    }
  }

  for (int i = 1; i <= K; i++) {
      cin >> cowR >> cowC;
      Cow.push_back(make_pair(cowR, cowC));
      // board[cowR][cowC] = true;
  }

  // for (int i = 1; i <= K; i++) {
  //   for (int j = 1; j <= K; j++) {
  //     if (!board[i][j]) continue;
  //     solve(i, j);
  //     res += addRes();
  //     board[i][j] = false;
  //     fill(isVisited[0], isVisited[0] + 101 * 101, false);
  //   }
  // }
  for (int i = 0; i < Cow.size(); i++) {
    fill(isVisited[0], isVisited[0] + 101 * 101, false);
    solve(Cow[i].first, Cow[i].second);
    for (int j = i + 1; j < Cow.size(); j++) {
      if (!isVisited[Cow[j].first][Cow[j].second]) {
          res++;
      }
    }
  }

  cout << res << '\n';
}