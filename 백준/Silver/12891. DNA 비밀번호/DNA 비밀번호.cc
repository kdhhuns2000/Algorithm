#include <bits/stdc++.h>
using namespace std;

int s, p, l = 0, r, res = 0;
int cond[4] = { 0 }, val[4] = { 0 };
string dna;

bool isValid(int* inputVal) {
  bool ret = true;
  for (int i = 0; i < 4; i++) {
    if (cond[i] > inputVal[i]) {
      ret = false;
      break;
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> s >> p;
  cin >> dna;
  for (int i = 0; i < 4; i++) {
    cin >> cond[i];
  }

  for (int i = 0; i < p; i++) {
    if (dna[i] == 'A') {
      val[0]++;
    } else if (dna[i] == 'C') {
      val[1]++;
    } else if (dna[i] == 'G') {
      val[2]++;
    } else if (dna[i] == 'T') {
      val[3]++;
    }
  }
  res += isValid(val);


  for (r = p; r < s; r++) {
    if (dna[l] == 'A') {
      val[0]--;
    } else if (dna[l] == 'C') {
      val[1]--;
    } else if (dna[l] == 'G') {
      val[2]--;
    } else if (dna[l] == 'T') {
      val[3]--;
    }
    l++;

    if (dna[r] == 'A') {
      val[0]++;
    } else if (dna[r] == 'C') {
      val[1]++;
    } else if (dna[r] == 'G') {
      val[2]++;
    } else if (dna[r] == 'T') {
      val[3]++;
    }
    res += isValid(val);
  }

  cout << res << '\n';
}