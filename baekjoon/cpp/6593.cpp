#include <iostream>
#include <queue>
using namespace std;

struct Point3D{
    int x;
    int y;
    int z;
};


int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

int main()
{
    int L, R, C;
    while(1) {
        cin >> L >> R >> C;
        if (!L && !R && !C) break;
        
        char bd[30][30][30]{};
        int vis[30][30][30]{};
        queue<Point3D> q;
       
        for(int k = 0; k < L; k++) {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    cin >> bd[k][i][j];
                    if(bd[k][i][j] == 'S') {
                        q.push({k, i, j});
                        vis[k][i][j] += 1;
                    }
                }
            }
        }
        
        bool complete = false;
        while(!q.empty() && !complete) {
            auto cur = q.front();
            q.pop();
            if(bd[cur.x][cur.y][cur.z] == 'E') {
                cout << "Escaped in " << vis[cur.x][cur.y][cur.z] - 1 << " minute(s).\n";
                complete = true;
            }
            
            int nx, ny, nz;
            for (int dir = 0; dir < 6; dir++) {
                nx = cur.x + dx[dir];
                ny = cur.y + dy[dir];
                nz = cur.z + dz[dir];
                
                if (nx < 0 || ny < 0 || nz < 0 || nx >= L || ny >= R || nz >= C) continue;
                if (bd[nx][ny][nz] == '#' || vis[nx][ny][nz]) continue;
                
                q.push({nx, ny, nz});
                vis[nx][ny][nz] = vis[cur.x][cur.y][cur.z] + 1;
            }
             
        }
        
        if (!complete) cout << "Trapped!\n";
    }
}

