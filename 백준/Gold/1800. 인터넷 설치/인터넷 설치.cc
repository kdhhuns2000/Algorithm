#include <bits/stdc++.h>
using namespace std;

int N, P, K, com1, com2, price, maxCost = 0;
int value[1001];
vector<pair<int, int>> v[1001];
priority_queue<pair<int,int>, vector<pair<int, int>>, greater<>> pq;

void dijkstra(int mid) {
  value[1] = 0;
  pq.emplace(0, 1);
  while(!pq.empty()) {
    int now = pq.top().second;
    int val = pq.top().first;
    pq.pop();
    if (value[now] < val) continue;
    for (int i = 0; i < v[now].size(); i++) {
      int next = v[now][i].first;
      int nextPath = val + (v[now][i].second > mid);

      if (value[next] > nextPath) {
        value[next] = nextPath;
        pq.emplace(nextPath, next);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> P >> K;

  for (int i = 0; i < P; i++) {
    cin >> com1 >> com2 >> price;
    v[com1].emplace_back(com2, price);
    v[com2].emplace_back(com1, price);
    maxCost = max(maxCost, price);
  }

  int l = 0, r = maxCost;

  int res = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    fill(value, value + 1001, 2147483647);
    dijkstra(mid);
    int k = value[N];
    if (k <= K) {
      res = mid;
      r = mid - 1;
    } else if (k > K) {
      l = mid + 1;
    }
  }

  cout << res << '\n';
}
