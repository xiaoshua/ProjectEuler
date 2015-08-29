import math


def gcd(a, b):
    while a > 0 and b > 0:
        if a > b:
            a %= b
        else:
            b %= a
    return a + b


# integer is terminating_decimal 
def is_terminating_decimal(numerator, denominator):
    g = gcd(numerator, denominator)
    denominator /= g
    for num in [2, 5]:
        while denominator % num == 0:
            denominator /= num
    return denominator == 1


def get_power(n, k):
    return k * math.log10(1.0 * n / k)


def gao(n):
    k = 2
    ret = 0
    for i in xrange(5, n + 1):
        while get_power(i, k) < get_power(i, k + 1):
            k += 1
        print(i, k)
        if is_terminating_decimal(i, k):
            print(-i)
            ret -= i
        else:
            print(i)
            ret += i
    return ret


print(gao(100))
print(gao(10000))

