#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001

int N, K;
queue<int> q;
int sec[MAX]{}; // x위치에 가장 빠르게 도달하는 시간 sec[x] 


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i = 0; i < MAX; i++) sec[i] = -1;
    
    q.push(N);
    sec[N] = 0;
    int dx[3] = {0, 1, 1};
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        int nextx[3] = {cur * 2, cur + 1, cur - 1};
        for(int i = 0; i < 3; i++) {
            int nx = nextx[i];
            if(nx < 0 || nx >= MAX) continue;
            
            if(sec[nx] == -1 || sec[nx] > sec[cur] + dx[i]) {
                sec[nx] = sec[cur] + dx[i];
                q.push(nx);
            } 
        }
    }
    cout << sec[K];
    return 0;
}
