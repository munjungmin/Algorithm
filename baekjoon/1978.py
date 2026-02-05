
n = int(input())
nums = list(map(int, input().split()))

answer = 0

for num in nums:
    if num == 1 : continue
    for i in range(2, int(num ** 0.5) + 1):     # num ** 0.5 는 num의 0.5제곱, 즉 루트를 씌운 것과 같다. 
        if num % i == 0:
            break
    else:                              # for의 else로 break없이 끝났을때 혹은 for문이 실행되지 않았을때 else 실행 
        answer += 1  

print(answer)


