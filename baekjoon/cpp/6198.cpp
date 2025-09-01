#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    stack<int> st;
    int n;
    long long ans = 0;
    cin >> n;
    
    int h;
    for (int i = 0; i < n; i++) {
        cin >> h;
        
        if (st.empty()){
            st.push(h);
            continue;
        }
            
        while (!st.empty() && st.top() <= h) {
            st.pop();
        }    
        
        if (!st.empty()) {
            ans += st.size();
        }
        
        st.push(h);
    }
    
    cout << ans;
}

// 높이가 내림차순이 되도록 80000개의 빌딩이 서 있으면 ans 값이 79999 + 79998 + ... + 1 = 약 32억 
// int 자료형은 오버플로우가 발생함 

