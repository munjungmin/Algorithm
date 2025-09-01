#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    char ch;
    string str = "";
    unordered_set<string> vis;
    queue<pair<string, int>> q;
    
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> ch;
            str += ch;
        }
    }
    
    q.push({str, 0});
    vis.insert(str);
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        string curStr = cur.first;
        if(curStr == "123456780") {
            cout << cur.second;
            return 0;
        }
        
        zero = curStr.find('0');
        x = zero / 3;
        y = zero % 3;
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (nx < 0 || ny < 0 || nx > 2 || ny > 2) continue;
            
            int cIdx = x * 3 + y;
            int nIdx = nx * 3 + ny;
            
            swap(curStr[cIdx], curStr[nIdx]);
            if (vis.find(curStr) == vis.end()) {
                q.push({curStr, cur.second + 1});
                vis.insert(curStr);
            }
            swap(curStr[cIdx], curStr[nIdx]);
        }
    }
    cout << -1;
}

/*
 set은 원소를 정렬함 
 unordered_set은 원소를 정렬하지 않음 
 set을 쓸 때는 248ms, unordered_set을 쓸 때는 104ms 
*/

