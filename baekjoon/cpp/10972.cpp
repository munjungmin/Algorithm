#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[10005];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int tmp = -1;
    for(int i = N - 1; i > 0; i--) {
        if(arr[i] > arr[i-1]) {
            tmp = i - 1;
            break;
        }
    }
    
    if(tmp < 0) {
        cout << -1;
        return 0;
    }

    for(int i = N-1; i > tmp; i--) {
        
        if(arr[i] > arr[tmp]) {
            swap(arr[i], arr[tmp]);
            sort(arr + tmp + 1, arr + N);
            break;
        }
    }
    
    for(int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
}

/* 사전식 정렬
 *
 * 1 3 4 2
 * 1) 끝에서부터 오름차순이 깨지는 숫자를 찾는다 "3"
 * 2) 끝에서부터 해당 숫자보다 큰 숫자를 찾는다 "4"
 * 3) 두 수의 위치를 바꾼다 1 4 3 2
 * 4) (1)에서 찾은 위치 아래 수를 오름차순 정렬한다 1 4 2 3
 *
 */
