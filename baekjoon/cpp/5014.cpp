#include <iostream>
#include <queue>
using namespace std;

int N, S, G, U, D;
bool vis[1000005]{};

int main()
{
    cin >> N >> S >> G >> U >> D;
    D *= -1;
    
    int dx[2] = {U, D};
    queue<pair<int, int>> q;  // floor, level
    
    q.push({S, 0});
    vis[S] = true;
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.first == G) {
            cout << cur.second;
            return 0;
        }
        for (int dir = 0; dir < 2; dir++) {
             int next = cur.first + dx[dir];
             
            if (next <= 0 || next > N || vis[next]) continue;
            q.push({next, cur.second + 1});
            vis[next] = true;
        }
    }
    
    cout << "use the stairs";
    return 0;
}

