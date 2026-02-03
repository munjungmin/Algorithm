
n = int(input())

x_arr = []
y_arr = []

for i in range(n):
    x, y = map(int,input().split())
    x_arr.append(x)
    y_arr.append(y)


answer = [float("inf")] * n 
for x in x_arr :
    for y in y_arr :
        # x, y 정해짐
        d_arr = []

        # 거리 계산 
        for i in range(n):
            d = abs(x - x_arr[i]) + abs(y - y_arr[i])
            d_arr.append(d)
        d_arr.sort()

        # k개 구하기 
        for k in range(n) :
            if k != 0 :
                d_arr[k] += d_arr[k-1]
            answer[k] = min(answer[k], d_arr[k])

print(*answer)


# 틀린 이유 
# 1. 메모리 초과, 시간 초과 (시간초과는 알았지만 다른 방법이 안떠올라 그냥 해봄)
# 2. 거리합의 최대값 계산 잘못해서 틀림 좌표 범위가 최대 백만, x,y각각이므로 한 좌표에서 최대 2백만가능, k개 누적합이므로 k x 2백만 k의 최대값은 50이라서 1억이 최대값이 된다. 
# 3. 그냥 틀린 가설을 세워서 풂.,,.,
