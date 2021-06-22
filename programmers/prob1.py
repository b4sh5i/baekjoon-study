from itertools import cycle

def solution(v0):
    vv = [
        cycle([1,2,3,4,5]),
        cycle([2,1,2,3,2,4,2,5]),
        cycle([3,3,1,1,2,2,4,4,5,5])
    ]
    ret = [0,0,0]
    for i in v0:
        for j in range(3):
            if next(vv[j]) == i:
                ret[j] += 1
    hh = max(ret)
    return [j + 1 for j, k in enumerate(ret) if k == hh]

solution([1,2,3,4,5])