#include <bits/stdc++.h>
using namespace std;

int main() {
    int num, max = 0;
    int p = 1, q = 1;

    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            cin >> num;

            if (num > max) {
                max = num;
                p = i;
                q = j;
            }
        }
    }

    cout << max << "\n" << p << " " << q;
}