#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    string s;
    list<char> l;
    list<char>::iterator cursor;

    cin >> s >> m;

    for (char c : s) { 
        l.push_back(c); 
    }
    cursor = l.end();

    char c;
    while(m--) {
        cin >> c;

        if (c == 'L') {
            if (cursor != l.begin()) 
                cursor--;
        }
        else if (c == 'D') {
            if (cursor != l.end()) 
                cursor++;
        }
        else if (c == 'B') {
            if (cursor != l.begin()) {
                cursor--;
                cursor = l.erase(cursor);
            } 
        }
        else {
            cin >> c;
            l.insert(cursor, c);
        }
    }

    for (auto c : l) {   // c의 자료형은 iterator임을 주의
        cout << c;
    }
}

/*
iterator(cursor)가 가리키는 문자 왼쪽에 커서가 있다고 가정 
iterator.begin() = 문장 맨 앞에 커서가 있는 것 
iterator.end() = 문장 맨 뒤에 커서가 있는 것 

erase()는 iterator가 가리키는 원소를 제거 후 다음 원소의 위치를 반환함
따라서 리턴값을 통해 위치를 다시 설정해주어야 함 
*/