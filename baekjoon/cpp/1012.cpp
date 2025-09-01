#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int M, N, K;
        cin >> M >> N >> K; 
        queue<pair<int, int>> q;
        int land[50][50]{};
        bool vis[50][50]{};
        
        int x, y;
        for (int i = 0; i < K; i++) {
            cin >> x >> y;
            land[x][y] += 1;
        }
        
        int ans = 0;
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if (land[i][j] && !vis[i][j]) {
                    q.push({i, j});
                    vis[i][j] = true;
                    ans++;
                }
                
                while(!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        
                        if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
                        if (!land[nx][ny] || vis[nx][ny]) continue;
                        q.push({nx, ny});
                        vis[nx][ny] = true;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}

