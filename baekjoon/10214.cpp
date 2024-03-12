#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, a, b;
    cin >> T;
    while(T--) {
        int y = 0, k = 0;

        for (int i = 0; i < 9; i++){
            cin >> a >> b;
            y += a;
            k += b;
        }
    
        cout << (y > k ? "Yonsei\n" : (y < k) ? "Korea\n" : "Draw\n");
    }
}