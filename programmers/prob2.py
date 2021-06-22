def gcd(x,y):
    while y:
        x,y = y, x % y
    return x

def solution(arr):
    answer = arr[0]
    for i in arr:
        answer = answer*i // gcd(answer,i)
    return answer

import bisect

def solution(info, query):
    ret = []

    language = ['cpp', 'java', 'python', '-']
    position = ['backend', 'frontend', '-']
    career = ['junior', 'senior', '-']
    food = ['chicken', 'pizza', '-']

    tables = {}
    for lang in language:
        for posi in position:
            for ca in career:
                for fo in food:
                    string = lang + posi + ca + fo
                    tables[string] = []

    for info_q in info:
        string = info_q.split(' ')
        language = [string[0], '-']
        position = [string[1], '-']
        career = [string[2], '-']
        food = [string[3], '-']

        for lang in language:
            for posi in position:
                for ca in career:
                    for fo in food:
                        key = lang + posi + ca + fo
                        tables[key].append(int(string[4]))

    for key, value in tables.items():
        tables[key] = sorted(value)

    for info_q in query:
        member = 0
        v1, v2 = info_q.replace(' and ', '').split(' ')
        v2 = int(v2)
        size = len(tables[v1])
        num = size - bisect.bisect_left(tables[v1], v2, lo=0, hi=size)

        ret.append(num)

    return ret