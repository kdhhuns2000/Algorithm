#include <bits/stdc++.h>
using namespace std;

int N, K, input, lev = 0;
vector<pair<int, bool>> v;

void rotation() {
  vector<pair<int, bool>>::iterator it = v.begin();
  v.insert(it, v.back());
  v.pop_back();
  if (v[N - 1].second) {
    v[N - 1].second = false;
  }
}

void allRobotMove() {
  for (int i = N - 2; i >= 0; --i) {
    if (v[i].second && !v[i + 1].second && v[i + 1].first > 0) {
      v[i].second = false;
      v[i + 1].second = true;
      v[i + 1].first--;
      if (v[i + 1].first == 0) {
        K--;
      }
      if (v[N - 1].second) {
        v[N - 1].second = false;
      }
    }
  }
}

void setRobot() {
  if (v[0].first > 0) {
    v[0].second = true;
    v[0].first--;
    if (v[0].first == 0) {
      K--;
    }
  }
}

bool canExit() {
  if (K <= 0) {
    return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> K;

  for (int i = 0; i < N * 2; i++) {
    cin >> input;
    v.push_back(make_pair(input, false));
  }

  while (true) {
    lev++;
    rotation();
    allRobotMove();
    setRobot();
    if (canExit()) {
      break;
    }
  }

  cout << lev << '\n';
}
