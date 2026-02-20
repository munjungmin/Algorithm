import sys
# 입력 속도 향상
input = sys.stdin.readline

n = int(input())
mp, mf, ms, mv = map(int, input().split())  #단백질, 지방, 탄수, 비타민 
foods = [list(map(int, input().split())) for _ in range(n)] # 재료 영양표 

mcost = float('inf')
answer_list = []


def dfs(level, used, p, f, s, v, cost):
    global mcost, answer_list 

    #이미 현재 비용이 최저가보다 크면 재귀 종료 
    if cost > mcost :
        return 

    if level == n:
        if p < mp or f < mf or s < ms or v < mv:
            return 

        if cost < mcost:
            mcost = cost
            answer_list = used
        elif cost == mcost:
            if answer_list == [] or used < answer_list:   # not 배열은 배열이 비어있으면 True, 들어있으면 False, 배열 간 비교는 원소끼리 사전순 비교 
                answer_list = used 
        return 

    # 재료 포함 X
    dfs(level + 1, used, p, f, s, v, cost)

    # 재료 포함 O
    dfs(level + 1, used + [level+1], p + foods[level][0], f + foods[level][1], s + foods[level][2], v + foods[level][3], cost + foods[level][4])



dfs(0, [], 0, 0, 0, 0, 0)

if mcost == float('inf'):
    print(-1)
else :
    print(mcost)
    print(*answer_list)


