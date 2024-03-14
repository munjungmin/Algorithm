#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int n, p;
    deque<pair<int, int>> dq;  // 위치, 종이에 쓰인 숫자
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> p;
        dq.push_back(make_pair(i, p));
    }
    
    while(!dq.empty()) {
        cout << dq.front().first << " ";
        int num = dq.front().second;
        dq.pop_front();
        
        if (num > 0) {
           while(--num) {
               dq.push_back(dq.front());
               dq.pop_front();
           }
        }
        else {
            num = -(num);
            while(num--) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
}

