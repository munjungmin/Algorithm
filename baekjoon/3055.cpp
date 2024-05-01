#include <iostream>
#include <queue>
using namespace std;

int R, C;
char board[50][50]{};
queue<pair<int, int>> wq;  // water
queue<pair<int, int>> hq;  // hedgehog
int visW[50][50]{};
int visH[50][50]{};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    
    for(int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
            
            if(board[i][j] == '*') {
                wq.push({i, j});
                visW[i][j] = 1;
            }
            else if(board[i][j] == 'S') {
                hq.push({i, j});
                visH[i][j] = 1;
            }
        }
    }
    
    while(!wq.empty()) {
        int Qsize = wq.size();
        
        for(int i = 0; i < Qsize; i++) {
            auto cur = wq.front();
            wq.pop();
            
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                
                if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if(board[nx][ny] == 'X' || board[nx][ny] == 'D' || visW[nx][ny] > 0) continue;
                
                wq.push({nx, ny});
                visW[nx][ny] = visW[cur.first][cur.second] + 1;
            }
        }
    }
    
    while(!hq.empty()) {
        int Qsize = hq.size();
        
        for(int i = 0; i < Qsize; i++) {
            auto cur = hq.front();
            hq.pop();
           
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                
                if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if(board[nx][ny] == 'D') {
                    cout << visH[cur.first][cur.second];
                    return 0;
                }
                if(board[nx][ny] == 'X'  || visH[nx][ny] > 0) continue;
                if(visW[nx][ny] != 0 && visW[nx][ny] <= visH[cur.first][cur.second] + 1) continue;  // 물이 아예 갈 수 없는 곳을 고려해야함
                
                hq.push({nx, ny});
                visH[nx][ny] = visH[cur.first][cur.second] + 1;
            }
        }
    }
    cout << "KAKTUS";
}

