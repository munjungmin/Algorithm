#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K, num, cnt;
bool paper[100][100]{};
bool vis[100][100]{};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int i, int j) {
    num++;
    vis[i][j] = true;
    
    for(int dir = 0; dir < 4; dir++) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        
        if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
        if (paper[nx][ny] || vis[nx][ny]) continue;
        
        dfs(nx, ny);
    }
}

int main()
{
    cin >> M >> N >> K;
    
    vector<int> area;   
    int lx, ly, rx, ry;
    for(int i = 0; i < K; i++) {
        cin >> lx >> ly >> rx >> ry;
        
        for(int p = lx; p < rx; p++) {
            for (int q = ly; q < ry; q++) {
                paper[q][p] = true;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!paper[i][j] && !vis[i][j]) {
                num = 0;
                cnt++;
                dfs(i, j);
                area.push_back(num);
            }
        }
    }
    
    cout << cnt << "\n";
    sort(area.begin(), area.end());
    for(int i : area) {
        cout << i << " ";
    }
    
}


// 배열에서 x, y는 arr[y][x]가 됨 
// 주어진 정보와 똑같은 위치에 표시해야하기 때문에 x, y 위치가 중요함 
