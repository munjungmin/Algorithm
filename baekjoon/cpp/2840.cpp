#include <iostream>
#include <list>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, s;
    char ch; 
    int arr[26]{};
    list<int> lst;
    list<int>::iterator it;
    
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        lst.push_back(0);
    }
    fill(arr, arr + 26, 1);
    
    it = lst.begin();
    while (k--) {
        cin >> s >> ch;
        while(s--) {
            it++;
            if (it == lst.end()) { it = lst.begin(); }
        }
        if ((*it == 0 && arr[ch-'A'] != 1) || (*it != 0 && *it != ch)) {
            cout << "!";
            return 0;
        }
        
        *it = ch;
        arr[ch-'A']--;
    }
    
    for (int i = 0; i < lst.size(); i++) {
        if (*it == 0) cout << "?";
        else cout << (char)*it;
        if (it == lst.begin()) it = lst.end();
        it--;
    }

}

