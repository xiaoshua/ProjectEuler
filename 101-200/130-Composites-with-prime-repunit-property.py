"""
1. pow(10, x) % 9n = 1
2. (n-1) % x = 0
"""


def is_prime(n):
    if n == 1:
        return False
    elif n == 2:
        return True
    elif n & 1 == 0:
        return False
    ni = 3
    while ni * ni < n:
        if n % ni == 0:
            return False
        ni += 1
    return True


def pow_mod(a, b, mod):
    ret = 1
    while b > 0:
        if b & 1:
            ret = (ret * a) % mod
        a = (a * a) % mod
        b >>= 1
    return ret


def check(n, a):
    return pow_mod(10, a, 9 * n) == 1


def find_x(n):
    k = 1
    while True:
        if check(n, k):
            return k
        k += 1


aim_count = 25

cur_cnt = 0
result_sum = 0
i = 2
while cur_cnt < aim_count:
    if i % 2 != 0 and i % 5 != 0 and (not is_prime(i)) and (i - 1) % find_x(i) == 0:
        result_sum += i
        cur_cnt += 1
    i += 1

print(result_sum)

