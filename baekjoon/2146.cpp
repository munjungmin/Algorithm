#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, num = 0;
int land[100][100]{};
int vis[100][100]{};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct Node {
    int x;
    int y;
};

void dfs(int x, int y) {
    land[x][y] = num;
    vis[x][y] = 1;
    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if(!land[nx][ny] || vis[nx][ny]) continue;
        
        dfs(nx, ny);
    }
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> land[i][j];
        }
    }
    
    // 섬에 번호 부여
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(land[i][j] && !vis[i][j]) {
                num++;
                dfs(i, j);
            }
        }
    }
    
    int ans = 10000; 
    queue<Node> q;
    
    memset(vis, -1, sizeof(vis));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(land[i][j]) {
                q.push({i, j});
                vis[i][j] = 0;
            }
        }
    }
            
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(land[nx][ny] == land[cur.x][cur.y]) continue;  // 같은 섬이면 패스 
            if(land[nx][ny] == 0) {
                land[nx][ny] = land[cur.x][cur.y];
                q.push({nx, ny});
                vis[nx][ny] = vis[cur.x][cur.y] + 1;
            }
            else { ans = min(ans, vis[nx][ny] + vis[cur.x][cur.y]); }
        }
    }
    cout << ans;
}


// 섬의 한 칸마다 bfs를 돌리지 않고 바다가 아닌 모든 섬 좌표에서 동시에 bfs를 돌림 
// 시간복잡도 O(n^4) -> O(n^2) ... 
