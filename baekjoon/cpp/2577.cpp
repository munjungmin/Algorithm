#include <bits/stdc++.h>
using namespace std;

int num[10];
int main() {
    int a, b, c;
    cin >> a >> b >> c;

    string s = to_string(a * b * c);

    for (char c : s) {
        num[c - '0']++;
    }

    for (int i = 0; i < 10; i++) {
        cout << num[i] << "\n";
    }
}