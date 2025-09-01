#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
using namespace std;

string n;
int k, m, lv = 0;
queue<string> q;   // num
   
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    m = n.length();
    
    q.push(n);
    while(!q.empty() && lv < k) {
        set<string> s;
        int qSize = q.size();
        lv++;
        
        while(qSize--) {
            string cur = q.front();
            q.pop();
            
            for(int i = 0; i < m-1; i++) {
                for(int j = i+1; j < m; j++) {
                    string str = cur;
                    swap(str[i], str[j]);
                    if(str[0] == '0') continue;
                        
                    auto ret = s.insert(str);
                    if(!ret.second) continue;
                    
                    q.push(str);
                }
            }
        }
    }
    
    int ans = -1;
    while(!q.empty()) {
        ans = max(stoi(q.front()), ans);
        q.pop();
    }
    
    cout << ans;
}

/*
1. 처음엔 dfs로 k level까지 도달했을때 max값을 비교해서 중복된 수까지 다시 dfs 반복 -> 시간초과
2. 착각해서 한 숫자에서 나올 수 있는 max값을 저장하고 k번만큼 max값을 따라감 -> 틀린 방법
   2133 -> 3132 -> 3312 
  근데 k = 2일때 3321이 최대값  
3. 다시 1번으로 돌아가는데 중복된 노드를 지우자 -> 같은 레벨에서만 중복 체크  -> 정답
*/

