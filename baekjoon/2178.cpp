// board를 string으로 입력받았기 때문에 비교 연산자 사용 시 주의해야함 
// board[a][b] // board[a][b]가 char이기 때문에 '0'이 int 0이 아니어서 true가 된다\

#include <iostream>
#include <queue>
#include <string>
using namespace std;

string board[105]{};
bool vis[105][105]{};
queue<pair<int, int>> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int N, M, lv = 0;
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        cin >> board[i];
    }

    q.push({0, 0});
    vis[0][0] = true;
    
    while(!q.empty()) {
        int qSize = q.size();
        lv++;
        
        for(int i = 0; i < qSize; i++) {
            auto cur = q.front();
            q.pop();
            if(cur.first == N-1 && cur.second == M-1){
                cout << lv;
                return 0;
            }
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx >= N || nx < 0 || ny >= M || ny < 0) 
                    continue;
                if (vis[nx][ny] || board[nx][ny] == '0')
                    continue;
                q.push({nx, ny});
                vis[nx][ny] = true;
                
            }
            
        }
    }
}



