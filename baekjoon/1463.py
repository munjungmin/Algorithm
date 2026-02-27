
n = int(input())
d = [-1] * 1000005
d[1] = 0

# D[i]  i를 1로 만들기 위해 필요한 연산 사용 횟수의 최소값 

for i in range(2, len(d)-1):
    d[i] = d[i-1] + 1

    if i % 3 == 0 : 
        d[i] = min(d[i], d[i//3] + 1)
        
    if i % 2 == 0:
        d[i] = min(d[i], d[i//2] + 1)


print(d[n])

# D[12] = D[4] + 1 
# D[6] + 1
#
 