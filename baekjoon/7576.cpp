#include <iostream>
#include <queue>
using namespace std;

int N, M;
int board[1005][1005]{};
bool vis[1005][1005]{};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N;
    int ans = -1;
    queue<pair<int, int>> q;
    
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                q.push({i, j});  // 익은 토마토 좌표를 저장 
                vis[i][j] = true;
            }
        }
    }
    
    while(!q.empty()){
        int Qsize = q.size();
        for(int k = 0; k < Qsize; k++) {
            auto cur = q.front();
            q.pop();
            
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                
                if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if(board[nx][ny] == -1 || vis[nx][ny]) continue; 
                
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
        ans++;
    }
    
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!vis[i][j] && board[i][j] == 0) {
                ans = -1;
            }
        }
    }
    cout << ans;
}

