#include <bits/stdc++.h>
using namespace std;

int num[105]{};

int main() {
    int n, m, i, j;
    cin >> n >> m;

    for (int k = 1; k <= n; k++) {
        num[k] = k;
    }

    while(m--) {
        cin >> i >> j;
        swap(num[i], num[j]);
    }

    for (int k = 1; k <= n; k++) {
        cout << num[k] << " ";
    }
}