#include <bits/stdc++.h>
using namespace std;

long long i, j, res = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> i >> j;
  res += i - 1;
  if (j != 0) {
    if (i == 1) {
      res += j * 8;
    } else if (i == 2) {
      res += j / 2 * 8;
      if (j % 2) {
        res += 6;
      }
    } else if (i == 3) {
      res += j / 2 * 8;
      if (j % 2) {
        res += 4;
      }
    } else if (i == 4) {
      res += j / 2 * 8;
      if (j % 2) {
        res += 2;
      }
    } else if (i == 5) {
      res += j * 8;
    }
  }

  cout << res << '\n';
}