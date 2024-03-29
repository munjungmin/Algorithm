//2468
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N;
int board[105][105]{};
bool vis[105][105]{};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];   
        }
    }
   
    int ans = 1;  // 최대 안전 영역 개수 
    for (int rain = 1; rain <= 99; rain++) {
        
        memset(vis, false, sizeof(vis));
        queue<pair<int, int>> q;
        int cnt = 0;
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                
                if (vis[i][j] || board[i][j] <= rain) continue;
                
                q.push({i, j});
                vis[i][j] = true;
            
            
                while(!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        
                        if (nx < 0 || nx > N-1 || ny < 0 || ny > N-1) continue;
                        if (vis[nx][ny] || board[nx][ny] <= rain) continue;
                        
                        q.push({nx, ny});
                        vis[nx][ny] = true;
                    }
                }
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}


