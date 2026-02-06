
a, b = list(map(int, input().split()))


a -= 1
answer = b - a

count = 0
while b > 0 :
    b //= 2
    answer += b * 2**count
    count += 1

count = 0
while a > 0 :
    a //= 2
    answer -= a * 2**count
    count += 1

print(answer)


# 1~N까지 각 자연수에서 나오는 가장 큰 2의 거듭제곱의 합을 구하는 방법 
# 혹은 N!에서 곱해진 2의 개수를 구하는 방법

# N = 10일때 
# val += 10            # 2의 0제곱일때를 다 더함 
# val += 10 // 2 * 1   # 2의 1제곱일때를 다 더함 (위에서 1을 미리 더해놨으므로 나머지 1만 더하면 됨)
# val += 5 // 2  * 2   # 2의 2제곱일때를 다 더함 (위에서 1+1을 더해놨으므로 2만 더함)
# val += 2 // 1  * 4   # 2의 3제곱일때를 더함 (위에서 1+1+2를 더해놨으므로 4만 더함)

