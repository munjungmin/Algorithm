#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b && a && b) {
        if(a % b == 0) cout << "multiple\n";
        else if (b % a == 0) cout << "factor\n";
        else cout << "neither\n";
    }
}