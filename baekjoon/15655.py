
n, m = map(int, input().split())
nums = sorted(list(map(int, input().split())))

arr = [0] * m

def dfs(st, level):
    if level == m : 
        print(*arr)
        return 
    
    for i in range(st, n):
        arr[level] = nums[i]
        dfs(i+1, level+1)

dfs(0, 0)

