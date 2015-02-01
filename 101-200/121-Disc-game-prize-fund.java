public class Main {
    public static void main(String[] args) {
        new Task().solve();
    }
}

class Task {
    public void solve() {
        double eps = 1e-9;
        double[] p = new double[15];
        for (int i = 0; i < p.length; i++) {
            p[i] = 1.0 / (i + 2);
        }
        double[][] dp = new double[16][16];
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp.length; j++) {
                dp[i][j] = 0;
            }
        }

        dp[0][0] = 1;

        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 15; j++) {
                if (dp[i][j] < eps) {
                    continue;
                }
                dp[i + 1][j + 1] += p[i] * dp[i][j];
                dp[i + 1][j] += (1 - p[i]) * dp[i][j];
            }
        }

        double sum = 0;
        for (int i = 8; i < dp[15].length; i++) {
            sum += dp[15][i];
        }
        System.out.println(1 / sum);

    }

}
