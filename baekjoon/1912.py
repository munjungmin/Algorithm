n = int(input())

arr = list(map(int, input().split()))

max_arr = [arr[0]] * n
for i in range(1, n):
    # 값을 더한것 보다 새로 시작하는게 나은지 판단 
    max_arr[i] = max(arr[i], max_arr[i-1] + arr[i])

print(max(max_arr))      

