// https://github.com/nayuki/Project-Euler-solutions/blob/master/java/p401.java
#include<cstdio>
#include <iostream>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
// 1e9
const int MOD = 10 * 10000 * 10000;
//1e15
const LL INF = 1000LL * 1000000 * 1000000;

// n*(n+1)*(2*n+1)/6;
LL sum(LL n) {
    LL a = n, b = n + 1, c = 2 * n + 1;
    if (a & 1) {
        b >>= 1;
    } else {
        a >>= 1;
    }

    if (a % 3 == 0) {
        a /= 3;
    } else if (b % 3 == 0) {
        b /= 3;
    } else {
        c /= 3;
    }

    return ((((a % MOD) * (b % MOD)) % MOD) * (c % MOD)) % MOD;
}

int main() {

    clock_t begin = clock();
    LL ans = 0;
    LL i;

    //divisor is i
    for (i = 1; i * i <= INF; ++i) {
        LL count = (INF / i) % MOD;
        ans += ((i * i) % MOD) * count;
        ans %= MOD;
    }

    //
    for (--i; i > 0; --i) {
        LL start = INF / (i + 1) + 1;
        LL end = INF / i;

        LL curSum = (MOD + sum(end) - sum(start - 1));
        ans += (curSum*i);
        ans %= MOD;
    }

    clock_t end = clock();
    cout << "time cost:" << 1.0 * (end - begin) / CLOCKS_PER_SEC << "S, answer:" << ans << endl;

    return 0;
}
