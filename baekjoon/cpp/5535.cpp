#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        double num;
        string op;

        cin >> num;
        getline(cin, op);

        for(int i = 0; i < op.length(); i++) {
            switch(op[i]) {
                case '@' : num *= 3; break;
                case '%' : num += 5; break;
                case '#' : num -= 7; break;
            }
        }
        
        cout << fixed;
        cout.precision(2);
        cout << num << '\n';
    }
}

