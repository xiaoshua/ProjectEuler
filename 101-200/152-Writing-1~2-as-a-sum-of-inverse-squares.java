import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @author xiaoshua
 */
public class Main {

    private static final int N = 81;
    static boolean[] isPrime = new boolean[N];
    static boolean[] possible = new boolean[N];

    public static void main(String[] args) {

        long begin = System.currentTimeMillis();
        Arrays.fill(isPrime, true);

        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i < N; i++) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }


        List<Integer> candidateList = calculateCandidate();
        //2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20,21,22,24,25,26,28,30,32,33,35,36,39,40,
        //42,44,45,48,50,52,55,56,60,63,65,66,68,70,72,75,77,78,80,


        long answer = gao(candidateList);
        long end = System.currentTimeMillis();
        System.out.println("time:" + (end - begin) + ",answer:" + answer);

    }

    static long gao(List<Integer> candidateList) {

        int size = candidateList.size();

        BigInteger bigIntDen = BigInteger.ONE;
        for (Integer candidate : candidateList) {
            bigIntDen = lcm(bigIntDen, BigInteger.valueOf(square(candidate)));
        }
        //bigIntDen:15011738501760000, so we can use long instead of BigInteger

        long bigDen = bigIntDen.longValue();

        long[] candidateArr = new long[size];

        for (int i = 0; i < size; i++) {
            candidateArr[i] = bigDen / square(candidateList.get(i));
        }


        Map<Long, Long> preCountMap = new HashMap<>(1 << 20);

        long aim = bigDen / 2;
        int preSize = 20;
        int mask = 1 << preSize;
        for (int i = 0; i < mask; i++) {
            long sum = 0;
            for (int j = 0; j < preSize; j++) {
                if (maskContain(i, j)) {
                    sum += candidateArr[size - j - 1];
                }
            }
            if (sum > aim) {
                continue;
            }
            Long count = preCountMap.get(sum);
            if (count == null) {
                count = 0L;
            }
            preCountMap.put(sum, count + 1);
        }

        preCountMap.put(0L, 1L);

        long[] revSum = new long[size + 1];
        revSum[size] = 0;
        for (int i = size - 1; i >= 0; i--) {
            revSum[i] = candidateArr[i] + revSum[i + 1];
        }

        return dfs(candidateArr, size - preSize, preCountMap, revSum, aim, 0, 0);
    }


    static long dfs(long[] arr, int len, Map<Long, Long> countMap, long[] revSum, long aim, int idx, long currentSum) {
        if (idx == len) {
            return countMap.getOrDefault(aim - currentSum, 0L);
        }
        if (currentSum + revSum[idx] < aim || currentSum > aim) {
            return 0;
        }
        return dfs(arr, len, countMap, revSum, aim, idx + 1, currentSum)
                + dfs(arr, len, countMap, revSum, aim, idx + 1, currentSum + arr[idx]);
    }

    private static int square(Integer integer) {
        return integer * integer;
    }

    static BigInteger gcd(BigInteger a, BigInteger b) {
        return b.equals(BigInteger.ZERO) ? a : gcd(b, a.mod(b));
    }


    static BigInteger lcm(BigInteger a, BigInteger b) {
        return a.multiply(b).divide(gcd(a, b));
    }

    static List<Integer> calculateCandidate() {
        List<Integer> candidatePrimeList = new ArrayList<>(N);
        candidatePrimeList.add(2);
        candidatePrimeList.add(3);

        Arrays.fill(possible, false);

        //assume all 2^a * 3^b is possible
        for (int i = 1; i < N; i *= 2) {
            for (int j = 1; j < N; j *= 3) {
                if (i * j >= N) {
                    break;
                }
                possible[i * j] = true;
            }
        }

        for (int i = 5; i < N; i++) {
            if (isPrime[i] && checkPrime(i)) {
                candidatePrimeList.add(i);
            }
        }

        for (int i = 3; i < N; i++) {
            if (!possible[i]) {
                continue;
            }

            // if i contain a prime which not possible, then i is impossible
            for (int j = 3; j < i; j++) {
                if (i % j == 0 && isPrime[j] && !candidatePrimeList.contains(j)) {
                    possible[i] = false;
                }
            }
        }

        //special
        possible[64] = possible[27] = possible[54] = false;
        List<Integer> candidateList = new ArrayList<>(N);
        for (int i = 2; i < N; i++) {
            if (possible[i]) {
                candidateList.add(i);
            }
        }

        return candidateList;
    }

    static boolean checkPrime(int p) {
        boolean result = false;
        int n = N / p;
        int maxMask = 1 << n;
        for (int i = 1; i < maxMask; i++) {
            List<BigInteger> denList = new ArrayList<>(n);
            for (int j = 0; j < n; j++) {
                if (maskContain(i, j)) {
                    denList.add(BigInteger.valueOf(square(j + 1)));
                }
            }

            BigInteger maxDen = BigInteger.ONE;
            for (BigInteger den : denList) {
                maxDen = lcm(maxDen, den);
            }

            BigInteger sum = BigInteger.ZERO;
            for (BigInteger den : denList) {
                sum = sum.add(maxDen.divide(den));
            }

            //if sum include factor of p*p, then p is possible
            if (!gcd(sum, BigInteger.valueOf(square(p))).equals(BigInteger.ONE)) {
                result = true;

                for (int j = 0; j < n; j++) {
                    if (maskContain(i, j)) {
                        possible[p * (j + 1)] = true;
                    }
                }
            }
        }

        return result;

    }

    private static boolean maskContain(int i, int j) {
        return (i & (1 << j)) > 0;
    }
}
