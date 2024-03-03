#include <bits/stdc++.h>
using namespace std;

int coor[10]{};

int main() {
    int N, x, y;
    cin >> N;
    while(N--){
        cin >> x >> y;
        if (x == 0 || y == 0) coor[5]++;
        else if (x > 0 && y > 0) coor[1]++;
        else if (x < 0 && y > 0) coor[2]++;
        else if (x < 0 && y < 0) coor[3]++;
        else coor[4]++;
    }

    cout << "Q1: " << coor[1] << "\n";
    cout << "Q2: " << coor[2] << "\n";
    cout << "Q3: " << coor[3] << "\n";
    cout << "Q4: " << coor[4] << "\n";
    cout << "AXIS: " << coor[5] << "\n";
}