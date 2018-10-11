/**
 * @author xiaoshua
 */
public class Main {


    public static void main(String[] args) {

        final int N = 500;
        String aimStr = "PPPPNNPPPNPPNPN";
        boolean[] prime = new boolean[N + 1];
        for (int i = 1; i <= N; i++) {
            prime[i] = isPrime(i);
        }

        Fraction[] probability = new Fraction[N + 1];
        for (int i = 1; i <= N; i++) {
            probability[i] = new Fraction(1L, 500L).multi(prime[i] ? new Fraction(2, 3) : new Fraction(1, 3));
        }

        for (int i = 1; i < aimStr.length(); i++) {

            Fraction[] newProbability = new Fraction[N + 1];
            for (int j = 0; j <= N; j++) {
                newProbability[j] = new Fraction();
            }

            for (int j = 1; j <= N; j++) {
                int nextA = j - 1;
                int nextB = j + 1;
                if (nextA == 0) {
                    nextA = 2;
                }
                if (nextB == N + 1) {
                    nextB = N - 1;
                }
                boolean aimCharType = aimStr.charAt(i) == 'P';
                boolean positionType = isPrime(nextA);
                Fraction addToA = probability[j].multi(new Fraction(1, 2)).multi(aimCharType == positionType ? new Fraction(2, 3) : new Fraction(1, 3));
                newProbability[nextA] = newProbability[nextA].add(addToA);
                positionType = isPrime(nextB);
                Fraction addToB = probability[j].multi(new Fraction(1, 2)).multi(aimCharType == positionType ? new Fraction(2, 3) : new Fraction(1, 3));
                newProbability[nextB] = newProbability[nextB].add(addToB);
            }
            probability = newProbability;
        }

        Fraction answer = new Fraction();
        for (int i = 1; i <= N; ++i) {
            answer = answer.add(probability[i]);
        }

        System.out.println(answer.numerator + "/" + answer.denominator);
    }

    public static boolean isPrime(int n) {
        if (n == 1) {
            return false;
        }

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    static class Fraction {
        /**
         * The numerator number part of the fraction (the three in three sevenths).
         */
        private final long numerator;
        /**
         * The denominator number part of the fraction (the seven in three sevenths).
         */
        private final long denominator;


        Fraction() {
            this(0L, 1L);
        }

        Fraction(long numerator, long denominator) {
            if (numerator < 0 || denominator <= 0) {
                throw new IllegalArgumentException("numerator or denominator can not be negative");
            }
            long curGcd = gcd(numerator, denominator);
            if (curGcd != 1) {
                numerator /= curGcd;
                denominator /= curGcd;
            }
            this.numerator = numerator;
            this.denominator = denominator;
        }


        Fraction multi(Fraction other) {
            long newNumerator = this.numerator * other.numerator;
            long newDenominator = denominator * other.denominator;
            return new Fraction(newNumerator, newDenominator);
        }


        Fraction add(Fraction other) {
            if (other.numerator == 0) {
                return this;
            } else if (this.numerator == 0) {
                return other;
            } else {
                long newDenominator = lcm(denominator, other.denominator);
                long newNumerator = this.numerator * (newDenominator / denominator) + other.numerator * (newDenominator / other.denominator);
                return new Fraction(newNumerator, newDenominator);
            }
        }

    }


    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }
}
