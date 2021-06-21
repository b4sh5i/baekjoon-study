from collections import deque
import sys
sys.setrecursionlimit(1000000)

def dfs(ret):
    check[ret] = True
    print(str(ret), end=" ")
    for i in range(1, n+1):
        if MAP[ret][i] == 1 and check[i] == False:
            dfs(ret)

def bfs(ret):
    q = deque([ret])
    check[ret] = False
    while q:
        v = q.popleft()
        print(str(ret), end=' ')
        for i in range(1, n+1):
            if MAP[i][ret] == 1 and check[i] == True:
                q.append(i)
                check[i] = False
            
            
n,m,v = map(int, input().split())
MAP = [[0 for i in range(n+1)] for j in range(n+1)]
check = [False] * (n+1)

for i in range(m):
    x, y = map(int, input().split())
    MAP[x][y] = 1 # dfs
    MAP[y][x] = 1 # bfs

dfs(v)
print()
