dig_num = 10
max_bin = 1 << dig_num
n = 40
dp = [[[0] * dig_num for _ in range(max_bin)] for __ in range(n + 1)]

for _ in range(1, dig_num):
    dp[1][1 << _][_] = 1

for ni in xrange(1, n):
    for bi in xrange(max_bin):
        for lst_num in xrange(dig_num):
            for new_num in [lst_num - 1, lst_num + 1]:
                if 0 <= new_num < dig_num:
                    dp[ni + 1][bi | (1 << new_num)][new_num] += dp[ni][bi][lst_num]

print(sum(dp[i][max_bin - 1][j] for i in range(n + 1) for j in range(dig_num)))

