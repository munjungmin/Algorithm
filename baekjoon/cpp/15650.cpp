#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool visit[9]{};
vector<int> v;  // arr[depth]

void dfs(int k, int level) {
    if(level == M) {
        for(int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i = 1; i <= N; i++) {
        
        if(visit[i]) continue;
        if(i <= k) continue;
        
        v.push_back(i);
        visit[i] = true;
        dfs(i, level + 1);
        v.pop_back();
        visit[i] = false;
    }
}

int main()
{
    cin >> N >> M;
    dfs(0, 0);
}


