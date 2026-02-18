n, m = map(int, input().split())
arr = [0] * m

def dfs(cur, level):
    if level == m:
        print(*arr)
        return 
    
    for i in range(cur, n+1):
        arr[level] = i
        dfs(i, level + 1)


dfs(1, 0)