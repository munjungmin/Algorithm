#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int k, num, ans = 0;
    stack<int> st;
    
    cin >> k;
    
    while(k--) {
        cin >> num;
        
        if (num) {
            st.push(num);
            ans += num;
        }
        else {
            ans -= st.top();
            st.pop();
        }
    }
    cout << ans;
}

