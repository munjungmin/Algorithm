#include <iostream>
#include <queue>
using namespace std;

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int main()
{
    int T;
    cin >> T;
    
    while(T--) {
        int I, x, y, destX, destY;
        
        cin >> I;
        cin >> x >> y >> destX >> destY;
        int vis[305][305]{};
        
        queue<pair<int, int>> q;
        q.push({x, y});
        vis[x][y] += 1;
        
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            if (cur.first == destX && cur.second == destY) {
                cout << vis[cur.first][cur.second] - 1 << "\n";
                break;
            }
            
            int nx, ny;
            for(int dir = 0; dir < 8; dir++) {
                nx = cur.first + dx[dir];
                ny = cur.second + dy[dir];
                
                if(nx < 0 || ny < 0 || nx >= I || ny >= I) continue;
                if (vis[nx][ny]) continue;
                
                q.push({nx, ny});
                vis[nx][ny] = vis[cur.first][cur.second] + 1;
            }
        }
    }
}

