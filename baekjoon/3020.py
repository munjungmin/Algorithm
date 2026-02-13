import sys
input = sys.stdin.readline

n, h = map(int, input().split())

up_arr = [0] * h
down_arr = [0] * h

for i in range(n):
    if i % 2 == 0 : down_arr[int(input()) -1] += 1
    else : up_arr[int(input()) -1] += 1

for i in range(len(up_arr) - 1, 0, -1) :
    up_arr[i-1] += up_arr[i]
    down_arr[i-1] += down_arr[i]


min_val = down_arr[0] + up_arr[h-1]
count = 0

for i in range(h):
    down_arr[i] += up_arr[h-1-i]
    
    if(down_arr[i] == min_val) :
        count += 1
    elif(down_arr[i] < min_val):
        min_val = down_arr[i]
        count = 1

print(min_val, count)
    
