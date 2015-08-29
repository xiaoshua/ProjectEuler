dp = [[0] * 2 for _ in range(31)]
dp[1][1] = 1
for i in range(1, 30):
    dp[i + 1][1] = dp[i][0]
    dp[i + 1][0] = dp[i][0] + dp[i][1]
print sum(sum(sub_dp) for sub_dp in dp) + 1 # include (1<<30)
