import time

N = 20
max_mask = 1 << 20
dp = [[0] * max_mask for _ in range(N + 1)]


def get_bit(mask, location):
    return (mask & (3 << (2 * location))) >> (2 * location)


def get_new_mask(mask, location):
    old_bit = get_bit(mask, location)
    other_ones = ((max_mask - 1) ^ (3 << (2 * location)))
    return (mask & other_ones) | ((old_bit + 1) << (2 * location))


if __name__ == '__main__':
    begin = time.time()
    for i in range(1, 10):
        dp[1][get_new_mask(0, i)] = 1

    for mask in range(max_mask):
        for k in range(10):
            if get_bit(mask, k) != 3:
                for i in range(1, 18):
                    dp[i + 1][get_new_mask(mask, k)] += dp[i][mask]

    ans = 0
    for i in range(max_mask):
        ans += dp[18][i]
    print(ans, time.time() - begin)
