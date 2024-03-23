#include <iostream>
#include <sstream>
#include <string>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int T; 
    cin >> T;
    
    while(T--) {
        int n;
        string p, tmp, arr;
        bool head = true, isErr = false;
        deque<int> dq;
        cin >> p >> n >> arr;
        arr = arr.substr(1, arr.length() - 2);
        stringstream ss(arr);
        
        while(getline(ss, tmp, ',')) {
            dq.push_back(stoi(tmp));
        }
        
        for(char ch : p) {
            if (ch == 'R') {
                head = !head;
            }
            else {
                if (dq.empty()) {
                    isErr = true;
                    break;
                }
                if (head == true) {
                    dq.pop_front();
                }
                else {
                    dq.pop_back();
                }
            }
        }
        
        if (isErr) {
            cout << "error\n";
        }
        else {
           cout << "[";
           while(!dq.empty()) {
                if (head == true) {
                    cout << dq.front();
                    dq.pop_front();
                }   
                else {
                    cout << dq.back();
                    dq.pop_back();
                }
                
                if (!dq.empty()) cout << ",";
           }
           cout << "]\n";
        }
    }
}

