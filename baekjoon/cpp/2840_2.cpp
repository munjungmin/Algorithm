#include <iostream>
#include <list>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, s, pointer = 0;
    char ch; 
    char arr[30]{};
    int num[26]{};
    fill(arr, arr + 30, '?');
    fill(num, num + 26, 1);
    cin >> n >> k;

    while (k--) {
        cin >> s >> ch;
        pointer = (pointer + s) % n;
        
        if (arr[pointer] == '?' && num[ch-'A'] == 1) {
            arr[pointer] = ch;
            num[ch-'A']--;
        }
        else if (arr[pointer] == ch) continue;
        else {
            cout << "!";
            return 0;
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[pointer];
        pointer--;
        if (pointer < 0) pointer = n - 1;
    }
}

