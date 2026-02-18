n, m = map(int, input().split())
input_arr = list(map(int, input().split()))
input_arr.sort()

used = [False] * n
arr = [0] * m

def dfs(level):
    if level == m:
        print(*arr)
        return

    for i in range(n):
        if not used[i] :
            arr[level] = input_arr[i]
            used[i] = True
            dfs(level + 1)
            used[i] = False

dfs(0)