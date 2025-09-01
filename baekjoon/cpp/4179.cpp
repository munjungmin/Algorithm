#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define X first
#define Y second

int R, C;
char board[1005][1005]{};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int,int>> fq;
queue<pair<int,int>> jq;

int visF[1005][1005]{};
int visJ[1005][1005]{};


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    memset(visF, -1, sizeof(visF)); // fill(visF[i], visF[i] + C, -1);
    memset(visJ, -1, sizeof(visJ)); // fill(visJ[i], visJ[i] + C, -1);
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'F') {
                fq.push({i, j});
                visF[i][j]++;
            }
            else if(board[i][j] == 'J'){
                jq.push({i, j});
                visJ[i][j]++;
            }
        }
    }
    
    // 불 먼저 이동시킴
    while(!fq.empty()) {
        auto cur = fq.front();
        fq.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if (board[nx][ny] == '#' || visF[nx][ny] >= 0) continue;
            
            fq.push({nx, ny});
            visF[nx][ny] = visF[cur.X][cur.Y] + 1;
        }
    }
    
    while(!jq.empty()) {
        auto cur = jq.front();
        jq.pop();
        
        //탈출
        if (cur.X == 0 || cur.Y == 0 || cur.X == R - 1 || cur.Y == C - 1) {
            cout << visJ[cur.X][cur.Y] + 1;
            return 0;
        }
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if (board[nx][ny] == '#' || visJ[nx][ny] >= 0) continue;
            if(visF[nx][ny] != -1 && visJ[cur.X][cur.Y] + 1 >= visF[nx][ny]) continue;    // -1인 경우 불이 아직 안붙은 것이므로
            
            jq.push({nx, ny});
            visJ[nx][ny] = visJ[cur.X][cur.Y] + 1;
        }
    }
    
    cout << "IMPOSSIBLE";
}

