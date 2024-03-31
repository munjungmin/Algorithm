#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[105];
int vis[105]{};

void dfs(int k) {
    for (int next : adj[k]){
        if (vis[next] == -1) {
            vis[next] = vis[k] + 1;
            dfs(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, A, B, M, x, y;
    
    cin >> N >> A >> B >> M;
    fill(vis, vis + 105, -1);
    
    for(int i = 0; i < M; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= N; i++) {
        if(vis[i] == -1) {
            vis[i]++;
            dfs(i);
            
            if ((vis[A] == -1 && vis[B] != -1 )|| (vis[A] != -1 && vis[B] == -1)) {
                cout << -1;
                return 0;
            } 
        }
    }
    
    cout << vis[A] + vis[B];
}

