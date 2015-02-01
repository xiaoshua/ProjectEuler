digit_sum_less10 = [False] * (1024)


def init():
    for i in range(1000):
        s = sum(int(j) for j in str(i))
        if s < 10:
            digit_sum_less10[i] = True


init()
dp = [([0] * 1000) for _ in range(21)]
for i in range(1, 10):
    dp[1][i] = 1
for i in range(20):
    for j in range(1000):
        if dp[i][j] > 0:
            for k in range(10):
                next_j = (j % 100) * 10 + k
                if digit_sum_less10[next_j]:
                    dp[i + 1][next_j] += dp[i][j]

print(sum(dp[20][j] for j in range(1000)))