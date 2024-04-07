#include <iostream>
#include <queue>
using namespace std;

int N, M;
int board[1005][1005]{};
int vis[1005][1005][2]{};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct Node {
  int x;
  int y;
  int k;
};

int main()
{
    queue<Node> q;
    char ch;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++){
            cin >> ch;
            board[i][j] = ch - '0';
        }
    }

    q.push({0, 0, 1});
    vis[0][0][1] = 1;  // 1: 아직 안부순 상태
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        if(cur.x == N - 1 && cur.y == M - 1) {
            cout << vis[cur.x][cur.y][cur.k];
            return 0;
        }
        
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            int nk = cur.k;
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(vis[nx][ny][nk]) continue;
            if(!nk && board[nx][ny] == 1) continue;   // 부술 횟수가 없는데 벽이라면
            
            
            // 벽이라면 부숴서 가는 경우 
            if(board[nx][ny] == 1) {
                nk -= 1;
            }
            
            q.push({nx, ny, nk});
            vis[nx][ny][nk] = vis[cur.x][cur.y][cur.k] + 1;
        }
    }

    cout << -1;
}


/*
벽을 한개 부술 수 있음 그니까 현재 위치에서 벽을 마주했을 때 
그 벽을 부술 지 안부술 지 선택이 가능함 
부순 경우 vs 안 부순 경우 2개로 나뉘어서 visit 검사 
*/
