#include <bits/stdc++.h>
using namespace std;

int n, m, res = 0;
char arr[1001][1001];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
int isVisited[1001][1001];

void Dfs(int y, int x) {
  isVisited[y][x] = 1;
  int ny, nx;
  switch (arr[y][x])
  {
  case 'U':
    ny = y + dy[0];
    nx = x + dx[0];
    break;
  case 'L':
    ny = y + dy[1];
    nx = x + dx[1];
    break;
  case 'D':
    ny = y + dy[2];
    nx = x + dx[2];
    break;
  case 'R':
    ny = y + dy[3];
    nx = x + dx[3];
    break;
  default:
    break;
  }

  if (!isVisited[ny][nx]) {
    Dfs(ny, nx);
  } else if (isVisited[ny][nx] == 1) {
    res++;
  }
  isVisited[y][x] = 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!isVisited[i][j]) {
        Dfs(i, j);
      }
    }
  }
  cout << res << '\n';
}