public class Main {
    public static void main(String[] args) {

        new Task().solve();
    }
}

class Task {


    long getLong(double tt) {
        long lo;
        if (tt > 0) {
            lo = (long) (tt + 0.5);
        } else {
            lo = (long) (-tt + 0.5);
            lo = -lo;
        }
        return lo;
    }

    long getVal(double[] u, int x) {
        long ret = 0;
        long t = 1;
        for (int i = 0; i < u.length; i++) {
            long lo = getLong(u[i]);
            if (Math.abs(lo - u[i]) > 1e-5) {
                System.out.printf("%.16f\n", u[i]);
            }
            ret += lo * t;
            t *= x;
        }
        return ret;
    }

    public static final double eps = 1e-7;

    boolean zero(double d) {
        return d < eps && d > -eps;
    }

    void swapLine(double[][] mat, int i, int j) {
        for (int k = 0; k < mat[i].length; k++) {
            double t = mat[i][k];
            mat[i][k] = mat[j][k];
            mat[j][k] = t;
        }
    }

    double[] gauss(double[][] mat) {
        int n = mat.length;
        for (int i = 0; i < n; i++) {
            int j;
            double mx = -1;
            int id = -1;
            for (j = i; j < n; j++) {
                if (mx < Math.abs(mat[j][i])) {
                    id = j;
                    mx = Math.abs(mat[j][i]);
                }
            }

            if (id != i) {
                swapLine(mat, i, id);
            }
            for (int k = i + 1; k < n; k++) {
                if (!zero(mat[k][i])) {
                    double tmp = mat[k][i] / mat[i][i];
                    for (int l = 0; l <= n; l++) {
                        mat[k][l] -= tmp * mat[i][l];
                    }
                }
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if (!zero(mat[j][i])) {
                    double tmp = mat[j][i] / mat[i][i];
                    mat[j][n] -= tmp * mat[i][n];
                }
            }
        }

        double[] ret = new double[n];
        for (int i = 0; i < n; i++) {
            ret[i] = mat[i][n] / mat[i][i];
        }

        return ret;
    }

    public void solve() {
        long ans = 0;
        double[] u = new double[11];

        for (int i = 0; i < 11; i++) {
            u[i] = ((i & 1) == 0) ? 1 : -1;
        }

        for (int i = 0; i < 10; i++) {// max power of n
            double[][] mat = new double[i + 1][i + 2];
            for (int j = 0; j <= i; j++) {//line equals x-1
                double t = 1;
                for (int k = 0; k <= i; k++) { // item
                    mat[j][k] = t;
                    t *= j + 1;
                }
                mat[j][i + 1] = getVal(u, j + 1);
            }
            double[] ui = gauss(mat);
            long tmp = getVal(ui, i + 2);
            for (double d : ui) {
                System.out.printf("%.16f ", d);
                System.out.println(getLong(d));
            }
            System.out.println();
            System.out.println(i + " " + tmp);
            ans += tmp;

        }
        System.out.println(ans);

    }

}
