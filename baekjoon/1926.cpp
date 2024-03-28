#include <iostream>
#include <queue>
using namespace std;

int paper[501][501]{};
bool visited[501][501]{};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, M;
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> paper[i][j];
        }
    }
    
    int num = 0, area = 0, mxArea = 0;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            area = 0;
            if (!paper[i][j] || visited[i][j]) continue;
            
            q.push({i, j});
            visited[i][j] = true;
            num++;
            area++;
            
            while(!q.empty()) {
                auto cur = q.front();
                q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int x = cur.first + dx[dir];
                    int y = cur.second + dy[dir];
                    if(x > N || x < 1 || y > M || y < 1) {
                        continue;
                    }
                    if(visited[x][y] || paper[x][y] == 0) {
                        continue;
                    }
                    q.push({x, y});
                    visited[x][y] = true;
                    area++;
                }
            }
            mxArea = max(mxArea, area);
        }
    }
    
    cout << num << "\n";
    cout << mxArea << "\n";
}





