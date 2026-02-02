candy = int(input())

answer = 0

for A in range(2, candy, 2):
    for B in range(1, candy-A):
        C = candy - A - B
        if C >= B + 2 :
            answer += 1

print(answer)