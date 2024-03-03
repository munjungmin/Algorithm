#include <bits/stdc++.h>
using namespace std;

int x[4];
int y[4];

int main() {
    for (int i = 1; i <= 3; i++) {
            cin >> x[i] >> y[i];
    }

    if (x[1] == x[2]) cout << x[3]<< ' ';
    else if (x[1] == x[3]) cout << x[2]<< ' ';
    else cout << x[1] << ' ';

    if (y[1] == y[2]) cout << y[3];
    else if (y[1] == y[3]) cout << y[2];
    else cout << y[1];

}