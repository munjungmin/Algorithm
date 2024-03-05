#include <bits/stdc++.h>
using namespace std;

int main() {
    string A, B, result = "";
    cin >> A >> B;

    int i = A.length() - 1;
    int j = B.length() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        if (i >= 0) {
            carry += A[i--] - '0';
        }
        if (j >= 0) {
            carry += B[j--] - '0';
        }

        result += to_string(carry % 10);
        carry /= 10;
    } 

    reverse(result.begin(), result.end());
    cout << result;

}