#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int N, L, num;
    priority_queue<p, vector<p>, greater<p>> pq;
    
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> num;
        pq.push({num, i});
        
        while (pq.top().second < i-L+1) {
            pq.pop();
        }
        
        cout << pq.top().first << " ";
    }
}


