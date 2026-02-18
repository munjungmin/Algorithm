n, m = map(int, input().split())
arr = [0] * m

def dfs(level):
    if level == m:
        print(*arr)
        return 

    for i in range(1, n+1):
        arr[level] = i
        dfs(level+1)


dfs(0)