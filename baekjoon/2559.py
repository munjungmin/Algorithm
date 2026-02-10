n, k = list(map(int, input().split()))
nums = list(map(int, input().split()))


answer = 0
for i in range(k):
    answer += nums[i]
    


cur = answer
for i in range(k, n):
    # 만약 현재 최대값보다, 이제 더하려는 값이 더 크다면 
    cur = cur - nums[i-k] + nums[i]
    if answer < cur :
        answer =  cur

print(answer)

    