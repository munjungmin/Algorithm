#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    int len = str.length();
    bool isPelindrome = true;
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len-i-1]) {
            isPelindrome = false;
            break;
        } 
    }
    cout << isPelindrome;
}