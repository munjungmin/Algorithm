#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    vector<int> v;
    cin >> n;
    
    v.push_back(1);
    for(int i = 1; i <= n; i++) {        
        int vecSize = v.size();
        
        for(int k = 0; k < vecSize; k++) 
            v[k] *= i;
         
        for(int j = 0; j < vecSize; j++){  
            if(v[j] / 10 > 0) { 
                if(j == vecSize - 1) 
                    v.push_back(v[j] / 10);
                else 
                    v[j + 1] += v[j] / 10;
                
                v[j] = v[j] % 10;
            }
        }
    }
    
    int answer = 0;
    for(int i = 0; i < v.size() - 1; i++) {
        if(v[i] > 0) {
            cout << answer;
            return 0;
        }
        else answer++;
    }
    cout << answer;
}

