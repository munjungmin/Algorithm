#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N, drink, max = 0;
    string str, result;

    cin >> T;  

    while(T--) {
        cin >> N;
        while(N--){
            cin >> str >> drink;
            if (drink >= max) {
                max = drink;
                result = str;  // deep copy, str이 바뀌어도 result에 영향 없음
            }
        }
        cout << result << "\n";
    }

}