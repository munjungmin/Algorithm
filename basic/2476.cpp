#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, a, b, c;
    int MAX = 0, sum = 0;
    cin >> N;
    while(N--) {
        cin >> a >> b >> c;
        if (a == b && b == c) {
            sum = a * 1000 + 10000;
        }
        else if (a == b || a == c) {
            sum = a * 100 + 1000;
        }
        else if (b == c) {
            sum = b * 100 + 1000;
        }
        else {
            sum = max({a, b, c}) * 100;  // algorithm header의 max()
        }

        if (sum > MAX) MAX = sum;
    }
    cout << MAX;
}