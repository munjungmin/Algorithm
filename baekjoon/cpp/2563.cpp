#include <bits/stdc++.h>
using namespace std;

bool mat[101][101]{};

int main() {
    int n, p, q; 
    int res = 0;
    cin >> n;

    while(n--) {
        cin >> p >> q;
        for (int i = p; i < p + 10; i++){
            for (int j = q; j < q + 10; j++) {
                if (!mat[i][j]) {
                    res++;
                    mat[i][j] = true;
                }
            }
        }
    }

    cout << res;
}