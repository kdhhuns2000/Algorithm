#include <bits/stdc++.h>
using namespace std;

int N, M;
double lamp[100000], maxDist = 0.0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> lamp[i];
  }

  sort(lamp, lamp + M);

  maxDist = max(maxDist, lamp[0]);
  for (int i = 0; i < M - 1; i++) {
    maxDist = max(maxDist, (lamp[i + 1] - lamp[i]) / 2);
  }
  maxDist = max(maxDist, N - lamp[M - 1]);

  cout << ceil(maxDist) << '\n';
}
