#include <bits/stdc++.h>
using namespace std;

int main() {
    string s[5];
    int maxLen = 0;

    for (int i = 0; i < 5; i++) {
        cin >> s[i];

        if (s[i].length() > maxLen)
            maxLen = s[i].length();
    }

    for (int j = 0; j < maxLen; j++) {
        for (int i = 0; i < 5; i++) {
            if (s[i].length() <= j) continue;
            cout << s[i][j];
        }
    }
}