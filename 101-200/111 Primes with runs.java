public class Main {
    public static void main(String[] args) {

        new Task().solve();
    }
}

class Task {

    boolean isPrime(long n) {
        for (long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    public void solve() {
        long ans = 0;
        String s = "00000000";
        for (int i = 1; i < 10; i++) {
            for (int j = 1; j < 10; j += 2) {
                String t = i + s + j;
                long cur = Long.parseLong(t);
                if (isPrime(cur)) {
                    ans += cur;
                    System.out.println(cur);
                }
            }
        }

        for (int i = 1; i < 10; i++) {
            s = "";
            for (int j = 0; j < 10; j++) {
                s += i;
            }
            for (int j = 0; j < 10; j++) {
                for (int k = (j == 0 ? 1 : 0); k < 10; k++) {
                    String t = s.substring(0, j) + k + s.substring(j + 1);
                    long cur = Long.parseLong(t);
                    if (isPrime(cur)) {
                        ans += cur;
                        System.out.println(cur);
                    }
                }
            }
        }
//        System.out.println(ans);
        // only 0 2 and 8 can only hava 8 digits same
        int arr[] = {2, 8};
        for (int i : arr) {
            s = "";
            for (int j = 0; j < 10; j++) {
                s += i;
            }
            for (int j = 0; j < 10; j++) {
                for (int k = (j == 0 ? 1 : 0); k < 10; k++) {
                    for (int l = j + 1; l < 10; l++) {
                        for (int m = 0; m < 10; m++) {
                            String t = s.substring(0, j) + k + s.substring(j + 1, l) + m + s.substring(l + 1);
                            long cur = Long.parseLong(t);
                            if (isPrime(cur)) {
                                ans += cur;
                                System.out.println(cur);
                            }
                        }
                    }
                }
            }
        }
        System.out.println(ans);
    }

}

