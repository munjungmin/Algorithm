#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int T, A, B;
bool visit[10005]{};
queue<pair<int, string>> q;

string str = "DSLR";

void initializeAndInput() {
    memset(visit, 0, sizeof(visit));
    while(!q.empty()) q.pop();
    
    cin >> A >> B;
    q.push({A, ""});
    visit[A] = true;
}

int D(int val) {
    return (val * 2) % 10000;
}

int S(int val) {
    return (val - 1 >= 0) ? val - 1 : 9999;
}

int L(int val) {
    int tmp = val / 1000;
    
    val %= 1000;
    val *= 10;
    val += tmp;
    
    return val;
}

int R(int val) {
    int tmp = val % 10;
    
    val /= 10;
    val += (tmp * 1000);
    
    return val;
}


void bfs() {
    while(!q.empty()) {
        
        int n = q.front().first;
        string inst = q.front().second;
        q.pop();
        
        int dslr[4]{};
        dslr[0] = D(n);
        dslr[1] = S(n);
        dslr[2] = L(n);
        dslr[3] = R(n);
        
        for(int i = 0; i < 4; i++) {
            if(dslr[i] == B) {
                cout << inst + str[i] << "\n";
                return;
            }
            if(!visit[dslr[i]]) {
                q.push({dslr[i], inst + str[i]});
                visit[dslr[i]] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    
    while(T--) {
        initializeAndInput();  
        bfs();
    }

    return 0;
}

