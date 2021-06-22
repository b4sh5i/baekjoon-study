def power(m):
    W = 0
    B = 0
    
    print(W,B)

x, y = map(int, input().split())
m = [0 for i in range(x)]
for i in range(y):
    m[i] = list(input())

power(m)