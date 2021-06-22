import sys
sys.setrecursionlimit(1000000)

def dfs(ret):
    check[ret] = True
    print(str(ret), end=" ")
    for i in range(1, n+1):
        if MAP[ret][i] == 1 and check[i] == False:
            dfs(i)

def bfs(v):
    q = [v]
    check[v] = False
    while(q):
        v = q[0]
        print(v, end=' ')
        del q[0]
        for i in range(1, n + 1):
            if check[i] == True and MAP[v][i] == 1:
                q.append(i)
                check[i] = 0
            
n,m,v = map(int, input().split())
MAP = [[0 for i in range(n+1)] for j in range(n+1)]
check = [False] * (n+1)

for i in range(m):
    x, y = map(int, input().split())
    MAP[x][y] = 1 # dfs
    MAP[y][x] = 1 # bfs

dfs(v)
print()
bfs(v)
