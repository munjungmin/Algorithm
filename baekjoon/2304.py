n = int(input())
arr = [0] * 1001

max_idx = 0
for i in range(n):
    l, h = list(map(int, input().split()))
    arr[l] = h

    if arr[l] > arr[max_idx]:
        max_idx = l


#앞
prefix = 0
pre_sum = 0
for i in range(1, max_idx):
    prefix = max(prefix, arr[i])
    pre_sum += prefix


#뒤 
suffix = 0
suf_sum = 0
for i in range(1000, max_idx -1, -1):
    suffix = max(suffix, arr[i])
    suf_sum += suffix

print(pre_sum + suf_sum)


