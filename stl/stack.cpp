#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> stk;

    // size 0일 때 top, pop 하면 에러
    cout << stk.size() << "\n";
    //cout << stk.top() << " ";
    //stk.pop();

    if (stk.empty()) 
        cout << "stack is empty" << "\n";

    stk.push(10);
    stk.push(20);
    stk.push(30);

    cout << stk.top() << "\n";
    stk.pop();
    cout << stk.top() << "\n";





}