#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, i; 
    cin >> N;

    for (i = 2; i * i<= N; i++) {
        while(N % i == 0) {
            N /= i;
            cout << i << '\n';
        }
    }
    if (N > 1) cout << N << '\n';   // 자기 자신은 무조건 인수로 가지니까

}