inf = 120000
rad = [0] * inf
p = []


def gcd(a, b):
    return a if b == 0  else gcd(b, a % b)


def init():
    rad[1] = 1
    for i in range(2, inf):
        if rad[i] == 0:
            p.append(i)
            rad[i] = i
        for pi in p:
            if pi * i >= inf:
                break
            if i % pi == 0:
                rad[i * pi] = rad[i]
                break
            else:
                rad[i * pi] = rad[i] * pi


def cmp(a, b):
    return rad[a] - rad[b]


init()
res = []
ids = range(1, inf)
ids.sort(cmp)
print(ids)
for i in range(2, inf):
    if i % 1000 == 0:
        print(i)
    for j in ids:
        if rad[i] * rad[j] >= i:
            break
        if j * 2 >= i:
            continue
        k = i - j
        if rad[i] * rad[j] * rad[k] < i and gcd(i, j) == 1:
            res.append(i)
print len(res), sum(res)
