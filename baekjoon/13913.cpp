#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 100001

int N, K;
queue<int> q;
int parent[MAX], sec[MAX];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    
    for(int i = 0; i < MAX; i++) sec[i] = -1;
    
    sec[N] = 0;
    parent[N] = N;
    q.push(N);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int nx : {cur + 1, cur - 1, 2 * cur}) {
            if(nx < 0 || nx >= MAX) continue;
            if(sec[nx] == -1 || sec[nx] > sec[cur] + 1) {  // 아직 방문 안했거나, 방문 했는데 이미 저장된 시간보다 짧은 시간에 도달했다면 
                parent[nx] = cur;
                sec[nx] = sec[cur] + 1;
                q.push(nx);
            }
        }
    }
    
    cout << sec[K] << "\n";
    
    vector<int> v;
    
    int tmp = K;
    for(int i = 0; i <= sec[K]; i++) {
        v.push_back(tmp);
        tmp = parent[tmp];
    }

    for(int i = sec[K]; i >= 0; i--) {
        cout << v[i] << " ";
    }
}

