#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[8]{};
int seq[8]{};
bool visit[8]{};

void dfs(int level, int start) {
    
    if(level == M) {
        for(int i = 0; i < M; i++) {
            cout << seq[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    int compare = 0;
    for(int i = start; i < N; i++) {
        if(visit[i] == true) continue;
        if(compare == arr[i]) continue;
        
        compare = arr[i];

        visit[i] = true;
        seq[level] = arr[i];
        dfs(level+1, i);
        visit[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    
    dfs(0, 0);
    return 0;
}


