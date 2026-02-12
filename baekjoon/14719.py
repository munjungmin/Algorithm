h, w = list(map(int, input().split()))
arr = list(map(int, input().split()))

max_idx = 0
for i in range(w):
    if arr[i] > arr[max_idx]:
        max_idx = i

answer = 0

#앞 
max_val = arr[0]
for i in range(max_idx):
    max_val = max(max_val, arr[i])
    answer += max_val - arr[i]

#뒤 
max_val = arr[w-1]
for i in range(w-1, max_idx-1, -1):
    max_val = max(max_val, arr[i])
    answer += max_val - arr[i]

print(answer)