#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;
int r, c, mea, s, d;
pair<int, int> direction[8];
queue<tuple<int, int, int>> arr[51][51];
queue<tuple<int, int, int>> newArr[51][51];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  direction[0] = {-1, 0};
  direction[1] = {-1, 1};
  direction[2] = {0, 1};
  direction[3] = {1, 1};
  direction[4] = {1, 0};
  direction[5] = {1, -1};
  direction[6] = {0, -1};
  direction[7] = {-1, -1};
  
  cin >> n >> m >> cnt;
  for (int i = 0; i < m; i++) {
    cin >> r >> c >> mea >> s >> d;
    arr[r][c].push(make_tuple(mea, s, d));
  }

  for (int i = 0; i < cnt; i++) {

    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        while(!arr[j][k].empty()) {
          tuple<int, int, int> fireball = arr[j][k].front();
          arr[j][k].pop();
          int dy = (j + direction[get<2>(fireball)].first * get<1>(fireball)) % n;
          if (dy <= 0)
            dy += n;
          int dx = (k + direction[get<2>(fireball)].second * get<1>(fireball)) % n;
          if (dx <= 0)
            dx += n; 
          newArr[dy][dx].push(fireball);
        }
      }
    }
    
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        arr[j][k] = newArr[j][k];
        newArr[j][k] = queue<tuple<int, int, int>>();
      }
    }

    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (arr[j][k].size() < 2) {
          continue;
        }
        int sumM = 0, sumS = 0;
        bool dirFlag[2] = {true, true}; // 홀 / 짝
        int size = arr[j][k].size();
        while (!arr[j][k].empty()) {
          tuple<int, int, int> fireball = arr[j][k].front();
          arr[j][k].pop();
          sumM += get<0>(fireball);
          sumS += get<1>(fireball);
          if (get<2>(fireball) % 2) { // 홀수
            dirFlag[1] = false;
          } else { // 짝수
            dirFlag[0] = false;
          }
        }
        if (sumM / 5 == 0) {
          continue;
        } else {
          if (dirFlag[0] == true || dirFlag[1] == true) {
            for (int addFireball = 0; addFireball < 4; addFireball++) {
              arr[j][k].push(make_tuple(sumM / 5, sumS / size, addFireball * 2));
            }
          } else {
            for (int addFireball = 0; addFireball < 4; addFireball++) {
              arr[j][k].push(make_tuple(sumM / 5, sumS / size, addFireball * 2 + 1));
            }
          }
        }
      }
    }

  }
  

  int res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      while(!arr[i][j].empty()) {
        res += get<0>(arr[i][j].front());
        arr[i][j].pop();
      }
    }
  }
  
  cout << res << '\n';
}