#include <iostream>
using namespace std;

int N, M, K;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool board[105][105]{};
bool vis[105][105]{};
int cnt = 0;

void dfs(int r, int c) {
    cnt++;
    vis[r][c] = true;
    
    for (int dir = 0; dir < 4; dir++) {
        int nx = r + dx[dir];
        int ny = c + dy[dir];
        
        if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
        if (!board[nx][ny] || vis[nx][ny]) continue;
        
        dfs(nx, ny);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    
    int r, c;
    for(int i = 0; i < K; i++) {
        cin >> r >> c;
        board[r][c] = true;
    }
    
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (board[i][j] && !vis[i][j]) {
                cnt = 0;
                dfs(i, j);
            }
            
            ans = max(ans, cnt);
        }
    }
    
    cout << ans;
}

