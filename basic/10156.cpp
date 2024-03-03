#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, n, m;
    cin >> k >> n >> m;
    cout << (k * n > m ? (k * n - m) : 0);
}