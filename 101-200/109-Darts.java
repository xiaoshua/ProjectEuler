import com.google.common.collect.Lists;

import java.util.List;

public class Main {
    public static void main(String[] args) {
        new Task().solve();
    }
}

class Task {
    public void solve() {
        final int n = 100;
        long[][] dp = new long[3][n];
        dp[0][0] = 1;
        List<Integer> scores = Lists.newArrayList();
        for (int i = 1; i < 21; i++) {
            scores.add(i);
            scores.add(i * 2);
            scores.add(i * 3);
        }
        scores.add(25);
        scores.add(50);

        List<Integer> doubleScore = Lists.newArrayList();
        for (int i = 1; i < 21; i++) {
            doubleScore.add(i * 2);
        }
        doubleScore.add(50);

        for (int score : scores) {
            for (int k = 2; k >= 0; k--) {
                for (int i = 0; i < n; i++) {
                    for (int j = 1; j + i < n && k + j < 3 && i + j * score < n; j++) {
                        dp[k + j][i + j * score] += dp[k][i];
                    }
                }
            }
        }

        long ans = 0, t = 0;
        for (int i = 0; i < n; i++) {
            dp[2][i] += dp[1][i] + dp[0][i];
            for (int ds : doubleScore) {
                if (i + ds < n) {
                    ans += dp[2][i];
                    if (i + ds == 6) {
                        t += dp[2][i];
                    }
                }
            }
        }
        System.out.println(ans);
        System.out.println(t);
    }
}
