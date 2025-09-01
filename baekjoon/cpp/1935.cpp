#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<double> stk;
    string s; 
    int n;
    int arr[26]{};
    
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            stk.push((double)arr[s[i] - 'A']);
        }
        else {
            double a, b;
            a = stk.top(); 
            stk.pop();
            b = stk.top();
            stk.pop();
            
            switch(s[i]) {
                case '+' :
                    stk.push(a + b);
                    break;
                case '-' : 
                    stk.push(b - a);
                    break;
                case '*':
                    stk.push(a * b);
                    break;
                case '/' :
                    stk.push((double)b / a);
                    break;
            }
        }
    }
    
    cout << fixed;  // 소수점 아래 숫자로 출력 범위 설정
    cout.precision(2);  // 정수부, 소수부 합친 전체 출력 범위
    cout << stk.top();
   
}
