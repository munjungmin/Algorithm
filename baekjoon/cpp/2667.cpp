#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, cnt;
char town[25][25]{};
bool vis[25][25]{};

void dfs(int i, int j) {
    cnt++;
    vis[i][j] = true;
    
    for(int dir = 0; dir < 4; dir++) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        
        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if (town[nx][ny] == '0' || vis[nx][ny]) continue;
        
        dfs(nx, ny);
    }
}

int main()
{
    vector<int> v;
    int ans = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> town[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (town[i][j] == '1' && !vis[i][j]) {
                ans++;
                cnt = 0;
                dfs(i, j);
                v.push_back(cnt);
            }
        }
    }
    
    cout << ans << "\n";
    sort(v.begin(), v.end());
    for(int i : v) {
        cout << i << "\n";
    }
}

