#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, a, b, c;
    cin >> T;

    a = T / 300;
    T %= 300;
    b = T / 60;
    T %= 60;
    c = T / 10;
    T %= 10;

    if (T != 0) cout << -1;
    else cout << a << " " << b << " " << c;
}