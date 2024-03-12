#include <bits/stdc++.h>
using namespace std;

int alphabet[26]{};

int main() {
    string str;
    cin >> str;

    for (char c : str) {
        alphabet[c - 'a']++;
    }

    for (int i=0; i < 26; i++) {
        cout << alphabet[i] << " ";
    }
}