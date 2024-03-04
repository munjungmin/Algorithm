#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    char op;
    cin >> a >> op >> b;

    if (op == '*') {
        int zerolen = a.length() + b.length() - 2;
        cout << "1";
        for (int i = 0; i < zerolen; i++) cout << "0";
    } 
    else {
        int len = a.length() - b.length();
        len = abs(len);
        if (a.length() >= b.length()) {
            a[len]++;
            cout << a;
        }
        else {
            b[len]++;
            cout << b;
        }
    }
}