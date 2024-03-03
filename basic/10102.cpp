#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, a = 0, b = 0;
    string str;

    cin >> V >> str;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'A') a++;
        else b++;
    }

    if (a > b) cout << "A";
    else if (a == b) cout << "Tie";
    else cout << "B";
}