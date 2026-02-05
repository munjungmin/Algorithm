
k = int(input())

weights = []

# 16

for i in range(2, int(k ** 0.5) + 1):  # 2 ~ 4
    while k % i == 0:
        weights.append(i)
        k //= i

    if k == 1 : break  

if k != 1 : weights.append(k)

print(len(weights))
print(*weights)
