#include <iostream>
using namespace std;

int N, M;
int arr[8]{};

void dfs(int level) {
    
    if(level == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i = 1; i <= N; i++) {
        arr[level] = i; 
        dfs(level + 1);
    }
    
    
}

int main()
{
    cin >> N >> M;
    dfs(0);
}

