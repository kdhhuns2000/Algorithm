#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

string binary = "";

bool Dnc(int l, int r, int prevMidValue) {
    int mid = (l + r) / 2;
    if (prevMidValue == '0' && binary[mid] == '1') {
        return false;
    }
    
    if (l == r) {
        return true;
    }

    return Dnc(l, mid - 1, binary[mid]) && Dnc(mid + 1, r, binary[mid]);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for (int i = 0; i < numbers.size(); i++) {
        binary = "";
        while (numbers[i] >= 1) {
            if (numbers[i] % 2 == 1) {
                binary = '1' + binary;
            } else {
                binary = '0' + binary;
            }
            numbers[i] /= 2;
        }
        int n = 1;
        while (binary.size() > pow(2, n) - 1) {
            n++;
        }
        while (binary.size() != pow(2, n) - 1) {
            binary = '0' + binary;
        }
        if (binary == "0") {
            answer.push_back(0);
        } else {
            answer.push_back(Dnc(0, binary.size() - 1, 1));
        }
    }
    return answer;
}