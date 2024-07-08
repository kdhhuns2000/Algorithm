#include <bits/stdc++.h>
using namespace std;

int N, Q, p, q, r, k, v;
int value[5001][5001];
vector<int> usado[5001];
bool isVisited[5001];
queue<int> que;

int bfs(int K, int V) {
  int cnt = 0;
  isVisited[v] = true;
  while(!que.empty()) {
    int now = que.front();
    que.pop();
    for (int i = 0; i < usado[now].size(); i++) {
      int next = usado[now][i];
      if (!isVisited[next] && value[now][next] >= K) {
        que.push(next);
        cnt++;
        isVisited[next] = true;
      }
    }
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> Q;

  for (int i = 1; i <= N - 1; i++) {
    cin >> p >> q >> r;
    usado[p].push_back(q);
    usado[q].push_back(p);
    value[p][q] = r;
    value[q][p] = r;
  }

  for (int i = 0; i < Q; i++) {
    cin >> k >> v;
    que.push(v);
    fill(isVisited, isVisited + 5001, false);
    cout << bfs(k, v) << '\n';
  }
}
