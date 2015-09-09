# http://blog.dreamshire.com/project-euler-225-solution/

def gao(n):
    count, num = (0, 27)
    while count < n:
        (t1, t2, t3) = (1, 1, 3)
        while t3 > 0 and t1 * t2 * t3 != 1:
            (t1, t2, t3) = (t2, t3, sum([t1, t2, t3]) % num)
        if t3 > 0:
            count += 1
        num += 2
    return num - 2


print(gao(124))
