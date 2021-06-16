v1,v2 = map(int, input().split())
ret = 0
v2 = int(v2)
v1_l = []
for i in range(int(v1)):
    v1_l.append(int(input()))
v1_l.sort(reverse=True)
for i in v1_l:
    if v2 // i > 0:
        ret += v2 // i
        v2 -= i * (v2 // i)
        
print(ret)
