#include <bits/stdc++.h>
using namespace std;

int mat[105][105]{};
int mat2[105][105]{};

int main() {
    int n, m, k;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++){
            cin >> mat[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++){
            cin >> mat2[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++){
            cout << mat[i][j] + mat2[i][j] << " ";
        }
        cout << "\n";
    }
}