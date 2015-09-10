N = 10 ** 8
is_prime = [True] * N
prime_list = list()


def get_prime():
    for i in xrange(2, N):
        if is_prime[i]:
            prime_list.append(i)
        for prime in prime_list:
            if i * prime >= N:
                break
            is_prime[prime * i] = False
            if i % prime == 0:
                break


def power_mod(a, n, mod):
    ret = 1 % mod
    while n > 0:
        if n & 1 > 0:
            ret = (ret * a) % mod
        a = (a * a) % mod
        n >>= 1
    return ret


def get_s(p):
    if p == 5:
        # S(5) = (0! + 1! + 2! + 3! + 4!)%5
        return (1 + 1 + 2 + 6 + 24) % 5
    else:
        base = power_mod(24 * (p - 1), p - 2, p)
        ret = base
        for i in xrange(p - 4, p):
            base *= i
            ret += base
        return ret % p


# 5<=p<n
def gao(n):
    ret = 0
    for p in xrange(5, n):
        if not is_prime[p]:
            continue
        s = get_s(p)
        if p < 100:
            print(p, s)
        ret += s

    return ret


if __name__ == '__main__':
    get_prime()
    print(gao(10 ** 2))
    print(gao(N))
