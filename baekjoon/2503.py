
n = int(input()) # 4

hint = [list(map(int, input().split())) for _ in range(n)]

# [[123, 1, 1], [356, 1, 0], ...]

answer = 0

for a in range(1, 10): # 100의 자리수
    for b in range(10): # 10의 자리수
        for c in range(10): # 1의 자리수

            if a == b or b == c or c == a or a == 0 or b == 0 or c == 0:
                continue

            # 숫자가 정해졌다면 

            cnt = 0

            for arr in hint:
                number = arr[0]
                strike = arr[1]
                ball = arr[2]

                ball_count = 0
                strike_count = 0
                
                # a,b,c 라는 숫자를 number하고 비교하기
                list1 = [int(d) for d in str(number)]
                list2 = [a, b, c]

                for i in range(3):
                    if list1[i] == list2[i]:
                        strike_count += 1
                    elif list1[i] in list2:
                        ball_count += 1          

                if ball_count == ball and strike_count == strike:
                    cnt += 1

            if cnt == n:
                answer += 1

print(answer)
