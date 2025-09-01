#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 1000
#define X first
#define Y second

int T, W, H;
char map[MAX][MAX]{};
int visF[MAX][MAX]{};
int visS[MAX][MAX]{};
bool isFound = false;
queue<pair<int, int>> fq, sq;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input() {
    isFound = false;
    memset(visF, -1, sizeof(visF));  // -1 : 방문 안함,  0: 시작 위치, 
    memset(visS, -1, sizeof(visS)); 
    while(!fq.empty()) fq.pop();
    while(!sq.empty()) sq.pop();
    
    cin >> W >> H;
    for(int i = 0; i < H; i++) {
        for(int j = 0 ; j < W; j++) {
            cin >> map[i][j];
            if(map[i][j] == '@') {
                sq.push({i, j});
                visS[i][j] = 0; 
            }
            else if (map[i][j] == '*') {
                fq.push({i, j});
                visF[i][j] = 0;
            }
        }
    }
}

void fireBFS() {
    while(!fq.empty()) {
        
        pair<int, int> cur = fq.front();
        fq.pop();
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(map[nx][ny] == '#' || visF[nx][ny] >= 0) continue;
            
            fq.push({nx, ny});
            visF[nx][ny] = visF[cur.X][cur.Y] + 1;
        }
    }
}

void sangBFS() {
    while(!sq.empty()) {
        
        pair<int, int> cur = sq.front();
        sq.pop();
        
        if(cur.X == 0 || cur.X == H - 1 || cur.Y == 0 || cur.Y == W - 1) {
            cout << visS[cur.X][cur.Y] + 1 << "\n";
            isFound = true;
            return;
        }
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(map[nx][ny] == '#' || map[nx][ny] == '*') continue;
            if(visS[nx][ny] >= 0) continue;
            if(visF[nx][ny] >= 0 && visS[cur.X][cur.Y] + 1 >= visF[nx][ny]) continue;
            
            sq.push({nx, ny});
            visS[nx][ny] = visS[cur.X][cur.Y] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    
    while(T--) {
        input();
        fireBFS();
        sangBFS();
        if(!isFound) 
            cout << "IMPOSSIBLE\n";
    }
}

