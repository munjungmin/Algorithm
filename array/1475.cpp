#include <bits/stdc++.h>
using namespace std;

int num[10]{0,};

int main() {
    string s;
    cin >> s;

    for (char c : s) {
        num[c - '0']++;
    }

    int max = 0;
    for (int i = 0; i < 10; i++) {  // range-based loop는 인덱스가 아니라 값을 복사함 
        if (i == 6 || i == 9) continue;
        if (num[i] > max) max = num[i];
    }
    
    int sixnine = ceil(((float)num[6]+num[9]) / 2);
    max = max > sixnine ? max : sixnine;
    cout << max;
}