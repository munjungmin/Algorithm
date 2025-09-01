#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[8]{};
int seq[8]{};

void dfs(int level) {
    
    if(level == M) {
        for(int i = 0; i < M; i++) cout << seq[i] << " ";
        cout << "\n";
        return;
    }
    
    for(int i = 0; i < N; i++) {
        if(level != 0 && arr[i] <= seq[level-1]) continue;
        seq[level] = arr[i];
        dfs(level + 1);
    }
}

int main()
{
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr + N);
    
    dfs(0);
    return 0;
}

