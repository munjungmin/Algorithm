#include <iostream>
using namespace std;

int N, M;
int arr[9]{};

void dfs(int level) {
    
    if(level == M) {
        for(int i = 1; i <= M; i++) 
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    
    for(int i = 1; i <= N; i++) {
        if(arr[level] > i) continue;
        
        arr[level + 1] = i;
        dfs(level + 1);
    }
}

int main()
{
    cin >> N >> M;
    dfs(0);
}

