#include <iostream>
#include <queue>
using namespace std;

int board[200][200]{};
int vis[200][200][30]{};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ndx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int ndy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

struct Node{
    int x;
    int y;
    int k;
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int K, W, H; 
    cin >> K >> W >> H;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> board[i][j];
        }
    }

    queue<Node> q;
    q.push({0, 0, K});
    vis[0][0][0] = 1;  

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        if(cur.x == H-1 && cur.y == W-1) {
            cout << vis[H-1][W-1][cur.k];
            return 0;
        }
        
        // 나이트 이동 능력 사용 x 
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            int nk = cur.k;
            
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(board[nx][ny] || vis[nx][ny][nk]) continue;  
            
            q.push({nx, ny, nk});
            vis[nx][ny][nk] = vis[cur.x][cur.y][cur.k] + 1;
        }

        if(cur.k == 0) continue;
        
        // 능력 사용 
        for(int dir = 0; dir < 8; dir++) {
            int nx = cur.x + ndx[dir];
            int ny = cur.y + ndy[dir];
            int nk = cur.k - 1;

            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(board[nx][ny] || vis[nx][ny][nk]) continue;

            q.push({nx, ny, nk});
            vis[nx][ny][nk] = vis[cur.x][cur.y][cur.k] + 1;
        }
    }
    cout << -1;
}


