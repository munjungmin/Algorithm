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
        reverse(num + i, num + j + 1);      // i번째 인덱스부터 j번째 인덱스 범위를 reverse
   }
    for (int k = 1; k <= n; k++) {
        cout << num[k] << " ";
    }

}