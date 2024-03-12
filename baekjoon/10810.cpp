#include <bits/stdc++.h>
using namespace std;

int num[105]{};

int main() {
    int n, m, i, j, k;
    cin >> n >> m;

    while(m--) {
        cin >> i >> j >> k;
        for (int p = i; p <= j; p++) {
            num[p] = k;
        }
        
    }
    for (int p = 1; p <= n; p++) {
        cout << num[p] << " ";
    }
}