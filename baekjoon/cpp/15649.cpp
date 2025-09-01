#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool visit[9]{};
vector<int> v;

void print() {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void dfs(int num, int level) {
    
    if(level == M) {
        print();
        return;
    }
    
    for(int i = 1; i <= N; i++){
        if(visit[i]) continue;
        v.push_back(i);
        visit[i] = true;
        dfs(i, level + 1);
        v.pop_back();
        visit[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    dfs(0, 0);
    return 0;
}


