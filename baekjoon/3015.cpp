#include <iostream>
#include <stack>
using namespace std;

stack<pair<long long , long long>> st;   // number, count
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    
    long long height;
    long long res = 0;
    for(int i=0; i<n; i++) {
        cin >> height;
        
        long long  cnt = 1;
        if (st.empty()) {
            st.push({height, 1});
            continue;
        }
            
        while(!st.empty() && height >= st.top().first) {
            if (st.top().first == height) 
                cnt = st.top().second + 1;
                
            res += st.top().second;
            st.pop();
        }
        
        if (!st.empty()) {
            res++;
        }
        st.push({height, cnt});
    }

    cout << res;
}

// 자료형 주의 
// 
/**
스택에서 내림차순을 유지 

3a 2a 2b 3b

(3a, 2a) (3a, 2b) (3a, 3b)
(2a, 2b) (2a, 3b)
(2b, 3b)

3a | 2a    -> 3이 2a 이후로 들어오는 사람을 볼 가능성이 있으므로 2a push   (3a, 2a)
^

3a 2a | 2b  -> 내림차순이기 때문에 2a pop (2a, 2b), 2b push (3a, 2b)
   ^
  
3a 2b | 3b -> 이때 사실은 (3a 2a 2b)로 있기 때문에 2b(중복:2) 
                2b를 pop하는데 2a가 숨어있기 때문에 2의 개수인 2를 더함  (2a, 3b) (2b, 3b)
                
3a | 3b  -> 3a pop (3a, 3b)
  
* 
push할때는 1을 더하지만 pop할 때 더하는 수는 중복된 수의 개수에 따라 달라진다 

