#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    
    while(n--){
        stack<int> st;
        string str;
        
        cin >> str;
        for (char ch : str) {
            if (st.empty()) { 
                st.push(ch); 
            }
            else {
                if (st.top() == ch) st.pop();
                else st.push(ch);
            }
        }
        if (st.empty()) ans++;
    }
    cout << ans;
}

