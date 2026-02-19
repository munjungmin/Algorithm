n = int(input())
foods = [list(map(int, input().split())) for _ in range(n)]

answer = float('inf')

def dfs(level, count, s, b):
    global answer

    if level == n:
        if count > 0:
            answer = min(answer, abs(s - b))
        return 

    # 재료를 사용하지 않는다.
    dfs(level + 1, count, s, b)

    # 재료를 사용한다.
    sour = foods[level][0]
    bitten = foods[level][1]
    dfs(level + 1, count + 1, s * sour, b + bitten)


dfs(0, 0, 1, 0) # level, count, s, b

print(answer)

