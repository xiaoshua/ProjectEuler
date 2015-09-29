from collections import OrderedDict


N = 10 ** 25


def add(d, k, v):
    if not d.has_key(k):
        d[k] = v
    else:
        d[k] += v


dp = [OrderedDict(), OrderedDict()]
(pre, cur) = (1, 0)
dp[cur][0] = 1
bit = 1
while bit < N:
    (pre, cur) = (cur, pre)
    dp[cur] = OrderedDict()
    for (k, v) in dp[pre].items():
        for bit_count in range(3):
            cur_key = k + bit * bit_count
            if cur_key <= N and (N - cur_key) & bit == 0:
                add(dp[cur], cur_key, v)
    bit <<= 1
    print(len(dp[cur]))

print(dp[cur])
