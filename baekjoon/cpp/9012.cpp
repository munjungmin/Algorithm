#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; 
    cin >> t;
    
    while(t--) {
        int cnt = 0;
        string s;
        cin >> s;
        
        for(char c : s) {
            if (c == '(') 
                cnt++;
            else {
                cnt--;
                if (cnt < 0) {
                    break;
                }
            }
        }
        
        if (cnt == 0) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
}


