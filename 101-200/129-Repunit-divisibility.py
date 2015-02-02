inf = int(1e7)
phi = [0] * inf
p = []


def init():
    for i in range(2, inf):
        if phi[i] == 0:
            p.append(i)
            phi[i] = i - 1
        for pi in p:
            if pi * i >= inf:
                break
            if i % pi == 0:
                phi[i * pi] = phi[i] * pi
                break
            else:
                phi[i * pi] = phi[i] * (pi - 1)


limit = 10 ** 6


def pow_mod(a, n, mod):
    ret = 1
    while n > 0:
        if (n & 1) == 1:
            ret = (ret * a) % mod
        a = (a * a) % mod
        n >>= 1
    return ret


def get_a(n):
    mod = n * 9
    phi_mod = phi[mod]
    ret = mod
    if ret < mod:
        return ret
    i_limit = int(phi_mod ** 0.5 + 10)
    for i in range(1, i_limit):
        if phi_mod % i == 0:
            if pow_mod(10, i, mod) == 1:
                ret = min(ret, i)
            if pow_mod(10, phi_mod / i, mod) == 1:
                ret = min(ret, phi_mod / i)
        if ret < limit:
            return ret
    if ret == mod:
        ret = 1
    return ret


init()
print(get_a(7), get_a(41))
for i in range(3, inf, 2):
    if i % 5 == 0:
        continue
    t = get_a(i)
    if t > limit:
        print(i)
        break

