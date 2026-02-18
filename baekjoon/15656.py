n, m = map(int, input().split())
nums = sorted(list(map(int, input().split())))

arr = [0] * m

def dfs(level):
    if level == m:
        print(*arr)
        return  
    
    for i in range(n):
        arr[level] = nums[i]
        dfs(level + 1)

dfs(0)