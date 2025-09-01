#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
bool visited[1001]{};
queue<int> q;

void dfs(int cur) {
    visited[cur] = true;
    cout << cur << " ";
    for (int next : adj[cur]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

void bfs(int V) {
    q.push(V);
    visited[V] = true;
    cout << V << " ";
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : adj[cur]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
                cout << next << " ";
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, M, V, x, y;
    cin >> N >> M >> V;
    
    adj.resize(N + 1);
    while(M--) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    
    dfs(V);
    
    //  초기화 
    cout << "\n";
    fill(visited, visited + 1001, false);
    
    bfs(V);
}




