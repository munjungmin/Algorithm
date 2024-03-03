#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, a, b;
    int c = 100, s = 100;
    cin >> N;

    while(N--) {
        cin >> a >> b;
        if (a > b) s -= a;
        else if (a < b) c -= b;
    }
    cout << c << "\n" << s;
}