#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int N, L, num;
    deque<pair<int, int>> dq;
    
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> num;
        
        while(!dq.empty() && dq.back().second > num) {
            dq.pop_back();
        }
        
        dq.push_back({i, num});
        
        while( dq.front().first < i - L + 1) {
            dq.pop_front();
        }
        
        cout << dq.front().second << " ";
    }
}


