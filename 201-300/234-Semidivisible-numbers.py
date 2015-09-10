N = 10 ** 7
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


def get_sum(a1, an, d):
    if a1 % d != 0:
        a1 = (a1 / d + 1) * d
    if an % d != 0:
        an -= an % d
    if a1 > an:
        return 0
    n = (an - a1) / d + 1
    return ((a1 + an) * n) >> 1


# 5<=p<n
def gao(n):
    ret = 0
    pre_prime = 2
    high = pre_prime ** 2 - 1
    for cur_prime in prime_list[1:]:
        low = high + 2
        high = cur_prime ** 2 - 1
        if high > n:
            high = n
        ret += get_sum(low, high, pre_prime)
        ret += get_sum(low, high, cur_prime)
        ret -= 2 * get_sum(low, high, pre_prime * cur_prime)
        pre_prime = cur_prime
        if high == n:
            break

    return ret


if __name__ == '__main__':
    get_prime()
    print(gao(1000))
    print(gao(999966663333))
