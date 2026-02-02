
# 수열 list(map(int, input().split()))

a, b, c, d, e, f = map(int, input().split())

for X in range (-999, 1000):
    for Y in range (-999, 1000):
        if a * X + b * Y == c and d * X + e * Y == f:
            print(X, Y)
            break

