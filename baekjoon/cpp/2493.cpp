#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    stack<pair<int, int>> st;
    int n, h;
    
    st.push({0, 1e9+1});   // empty인 경우가 없게 최대값을 넣어둠
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> h;
        
        while(st.top().second < h) {
            st.pop();
        }
        cout << st.top().first << " ";
        st.push({i, h});
    }
}

// 이게 왜 O(n)이지? => 모든 원소를 한번씩 push(O(1) * N), 모든 원소를 한번씩 pop( N * O(1) )   
// O(2N) = O(N) 이런 느낌인가?

// 브루트포스 방법으로 풀면 각 원소에 대해 자신의 왼쪽에 있는 모든 원소를 탐색해야 하므로 시간 복잡도가 O(N^2)
// 하지만 이 방법은 "단조 감소 스택"을 사용해 시간 복잡도가 O(N)이 된다. 
// 2중 루프라 해서 무조건 O(N^2)은 아니다
