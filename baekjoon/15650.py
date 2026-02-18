n, m = map(int, input().split())
arr = [0] * m

def recur(val, level):
    if level == m:
        print(*arr)
        return 
                
    for i in range(val, n+1):
        arr[level] = i
        recur(i+1, level+1)

recur(1, 0)

