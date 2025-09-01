#include <iostream>
#include <stack>
using namespace std;

const int mx = 7;
stack<int> stk[mx]{};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, p; 
    cin >> n >> p;
    
    for(int i = 0; i < mx ; i++) {
        stk[i].push(0);
    }
    
    int sn, pn;
    int res = 0;
    while(n--) {
        cin >> sn >> pn;
        
        while(stk[sn].top() > pn){
            stk[sn].pop();
            res++;
        }
        if (stk[sn].top() != pn) {
            stk[sn].push(pn);
            res++;
        }
    }
    cout << res;
}


