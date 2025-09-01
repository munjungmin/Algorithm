#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
bool visited[100005]{};

bool valid(int y) {
    if (y < 0 || y > 100000 || visited[y])
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, K, lv = 0;
    cin >> N >> K;
    
    q.push(N);
    visited[N] = true;
    
    while(!q.empty()) {
        int qSize = q.size();
        
        for(int i = 0; i < qSize; i++) {
            int cur = q.front();
            if (cur == K) {
                cout << lv; 
                return 0;
            }
            q.pop();
            if (valid(cur + 1)) {
                q.push(cur + 1);
                visited[cur + 1] = true;
            }
            if (valid(cur - 1)) {
                q.push(cur - 1);
                visited[cur - 1] = true;
            }
            if (valid(cur * 2)) {
                q.push(cur * 2);
                visited[cur * 2] = true;
            }
        }
        
        lv++;
    }
}




