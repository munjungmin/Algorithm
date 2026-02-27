
n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
answer = 0

def dfs(level, profit):
    global answer 

    if level == n:
        answer = max(answer, profit)
        
    if level >= n:
        return 
    
    dfs(level+1, profit)

    dfs(level + arr[level][0], profit + arr[level][1])


dfs(0, 0)
print(answer)