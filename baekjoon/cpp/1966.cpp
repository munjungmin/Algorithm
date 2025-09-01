#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while(t--) {
        int n, m, ans = 0;
        cin >> n >> m;
        
        queue<pair<int, int>> q;  // 처음 위치, 중요도
        priority_queue<int> pq;  // 중요도를 높은 순으로 나열 
        
        for(int i = 0; i < n; i++){
            int imp;
            cin >> imp;
            q.push(make_pair(i, imp));
            pq.push(imp);
        }
        
        while(true) {
            if (q.front().second != pq.top()) {
                q.push(q.front());
                q.pop();
            }
            else {
                ans++;
                if (q.front().first == m) { break; }
                q.pop();
                pq.pop();
            }
        }
        cout << ans << "\n";
    }
}

