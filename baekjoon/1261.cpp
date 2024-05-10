#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 110

int N, M;
queue<pair<int, int>> q;
char map[MAX][MAX]{};
int visit[MAX][MAX]{}; 

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input(){
    memset(visit, -1, sizeof(visit));
    
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
}

void bfs() {
    q.push({0, 0});
    visit[0][0] = 0;
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            int wall = map[nx][ny] - '0';
            
            if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            
            if(visit[nx][ny] != -1 &&  visit[nx][ny] <= visit[cur.first][cur.second] + wall) {
                continue;
            }
            
            q.push({nx, ny});
            visit[nx][ny] =  visit[cur.first][cur.second] + wall;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    input();
    bfs();
    
    cout << visit[M-1][N-1];
    return 0;
}

