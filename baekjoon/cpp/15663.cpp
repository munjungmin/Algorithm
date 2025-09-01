#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int N, M;
bool visit[8]{}; 
int arr[8]{};
int seq[8]{};

void dfs(int level) {
    unordered_set<int> us;
    if(level == M) {
        for(int i = 0; i < M; i++) {
            cout << seq[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i = 0; i < N; i++) {
        if(visit[i] == true) continue;  // 다음 레벨에서 또 뽑지 않아야 하니까 
        
        auto ret = us.insert(arr[i]);
        if(ret.second == false) continue; // 해당 레벨에서이미 사용한 숫자라면 

        visit[i] = true;
        seq[level] = arr[i];
        dfs(level + 1);
        visit[i] = false;
    }
  
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr, arr + N);
    
    dfs(0);
    return 0;
}

