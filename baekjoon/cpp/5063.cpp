#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, r, e, c;
    cin >> N;

    while(N--) {
        cin >> r >> e >> c;
        if (r < e - c) cout << "advertise\n";
        else if (r == e - c) cout << "does not matter\n";
        else cout << "do not advertise\n";
    }
}