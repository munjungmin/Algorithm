#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
bool visit[8]{};

int arr[8]{};
vector<int> v;

void dfs(int level) {
    
    if(level == M) {
        for(int i = 0; i < M; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    
    for(int i = 0; i < N; i++) {
        if(visit[i] == true) continue; 
        visit[i] = true;
        arr[level] = v[i];
        dfs(level + 1);
        visit[i] = false;
    }
}

int main()
{
    cin >> N >> M;
    
    int tmp;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    
    dfs(0);
    return 0;
}

