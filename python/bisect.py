import bisect

def ex1():
    result = []
    for score in [33, 99, 77, 70, 89, 90, 100]:
        pos = bisect.bisect([60, 70, 80, 90], score) # 이상
        grade = 'FDCBA'[pos] 
        result.append(grade)
    return result

def ex2():
    result = []
    for score in [33, 99, 77, 70, 89, 90, 100]:
        pos = bisect.bisect_left([60, 70, 80, 90], score) # 초과
        grade = 'FDCBA'[pos]
        result.append(grade)
    return result

# 삽입도 가능.
def ex3():
    v1 = [60, 70, 80, 90]
    bisect.insort(v1, 85)
    # v1 = [60, 70, 80, 85, 90]