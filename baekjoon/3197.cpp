#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
#define MAX 1500

int R, C;
bool isfound = false;
char board[MAX][MAX]{};
bool visited[MAX][MAX]{};
pair<int, int> swanPos;
queue<pair<int, int>> swanCurQ, swanNextQ, waterCurQ, waterNextQ;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input() {
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> board[i][j];
            
            if(board[i][j] != 'X') {
                waterCurQ.push({i, j});    
            };
            
            if(board[i][j] == 'L'){ 
                swanPos.X = i;
                swanPos.Y = j;
            }
        }
    }
}

// 백조 move - 물 / 빙하 / 백조
void swanBFS() {
     while(!swanNextQ.empty()){
        swanCurQ.push(swanNextQ.front());
        swanNextQ.pop();
    }

    while(!swanCurQ.empty()) {
        auto cur = swanCurQ.front();
        swanCurQ.pop();
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(visited[nx][ny]) continue;
            
            if(board[nx][ny] == 'L') {
                isfound = true;
                return;
            }
            
            visited[nx][ny] = true;
            if(board[nx][ny] == '.') swanCurQ.push({nx, ny});
            if(board[nx][ny] == 'X') swanNextQ.push({nx, ny});
        }
    }
}

// water move - 물 / 빙하 / 백조(백조도 물)
void waterBFS() {
    while(!waterCurQ.empty()) {
        auto cur = waterCurQ.front();
        waterCurQ.pop();
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(board[nx][ny] == 'X') {
                waterNextQ.push({nx, ny});
                board[nx][ny] = '.';
            }
        }
    }

    while(!waterNextQ.empty()){
        waterCurQ.push(waterNextQ.front());
        waterNextQ.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    int answer = -1;
   
    swanCurQ.push(swanPos);
    visited[swanPos.X][swanPos.Y] = true;
    while(!isfound) {
       
        swanBFS();
        waterBFS();
        answer++;
    }
    cout << answer;
}

