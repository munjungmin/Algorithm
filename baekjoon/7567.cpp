#include <bits/stdc++.h>
using namespace std;

int main() {
    int sum = 10;
    string str; 
    cin >> str;

    for (int i = 1; i < str.length(); i++) {
        if (str[i] == str[i - 1]) { sum += 5; }
        else { sum += 10; }
    }
   
    cout << sum;
}