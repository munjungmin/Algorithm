

# a, b의 최대공약수 , 최소공배수가 주어졌을때 a, b의 합이 최소가 되는 a, b의 값을 구하라 

# 갭을 줄여도 된다. 
# 최대 공약수라는 말은 두 수 중 하나로 나누어서 나머지가 생기지 않는 


def _gcd(a, b):
    while a % b != 0: #나머지가 0이 되는 순간 멈춘다 
        tmp = a % b
        a = b
        b = tmp 
    
    return b

def _lcm(a, b):
    return a * b // _gcd(a, b)


# a * b = ?
# gcd = 6 

? // 6 = 180 
a * b = 540 


gcd, lcm = list(map(int, input().split()))

i = 2 

val = lcm * gcd

while i * i <= val:
    if val %= 